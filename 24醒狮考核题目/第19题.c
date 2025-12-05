#include<stdio.h>
typedef int int32_t; 
enum
{
	NOW_ERR = 0,
	LAST_ERR,
	LLAST_ERR,
};
typedef struct pid
{
	float set;
	float get;
	float error[3];
	float kp;
	float ki;
	float kd;
 
	float pout;
	float iout;
	float dout;
	float out; 
 
	int32_t maxout;
	int32_t integral_limit;
	
 	void (*f_pid_init)(struct pid *pid_t,
	float p,
	float i,
	float d,
	int32_t max_out,
	int32_t integral_limit);
	void (*f_pid_reset)(struct pid *pid_t,
	float p,
	float i,
	float d);
}pid_t;

static void abs_limit(float *x,int32_t limit)
{
 	if(*x > limit)
 	*x = limit;
 	if(*x < -limit)
	*x = -limit;
}

static void pid_init(pid_t *pid,float p,float i,float d,int32_t max_out,int32_t integral_limit)
{
 	pid->kp = p;
 	pid->ki = i;
 	pid->kd = d;
 	pid->maxout = max_out;
 	pid->integral_limit = integral_limit;
}

static void pid_reset(pid_t *pid,float p,float i,float d)
{
 	pid->kp = p;
	pid->ki = i;
	pid->kd = d;
 
	pid->pout = 0;
	pid->iout = 0;
	pid->dout = 0;
	pid->out = 0;
}

void PID_Struct_Init(pid_t *pid,float p,float i,float d,int32_t max_out,int32_t integral_limit)
{
 	pid->f_pid_init = pid_init;
 	pid->f_pid_reset = pid_reset;
 	pid->f_pid_init(pid,p,i,d,max_out,integral_limit);
 	pid->f_pid_reset(pid,p,i,d);
}

float pid_calc(pid_t *pid,float get,float set)
{
 	pid->get = get;
 	pid->set = set;
 	pid->error[NOW_ERR] = set - get;
 
	pid->pout = pid->kp * pid->error[NOW_ERR];
	pid->iout += pid->ki * pid->error[NOW_ERR];
	pid->dout = pid->kd * (pid->error[NOW_ERR] - pid->error[LAST_ERR]);
	//积分限幅

	abs_limit(&(pid->iout),pid->integral_limit);
	pid->out = pid->pout + pid->iout + pid->dout;
	abs_limit(&(pid->out),pid->maxout);
	//最终值限幅

	pid->out += pid->pout + pid->iout + pid->dout;
	abs_limit(&(pid->out), pid->maxout);
	pid->error[LLAST_ERR] = pid->error[LAST_ERR];
	pid->error[LAST_ERR] = pid->error[NOW_ERR];
	//最终值输出
	return pid->out;
}
int main()
{
	float final=0;
	pid_t pid;
	//初始化 
	PID_Struct_Init(&pid,1,0.01,20,500,100);
	//计算 
	final=pid_calc(&pid,10,50);
	printf("%f",final);
	return 0;
}

