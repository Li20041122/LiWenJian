#include<stdio.h>
typedef unsigned int uint32_t;
typedef struct
{
	uint32_t get_count;
	uint32_t set_count;
	float out;
}ramp_t;
//初始化 
void ramp_init(ramp_t *ramp,uint32_t target_count)
{
	ramp->get_count = 0;
	ramp->set_count = target_count;
	ramp->out = 0;
}
//斜坡式上升 
float ramp_calc(ramp_t *ramp)
{
	if(ramp->set_count <= 0)
		return 0;
	if(ramp->get_count >= ramp->set_count)
		ramp->get_count = ramp->set_count;
	else
	ramp->get_count++;
	ramp->out = (float)ramp->get_count/(float)ramp->set_count;
	return ramp->out;
}
int main()
{
	ramp_t temp;
	//定义自变量x 
	float x=0;
	//初始化 
	ramp_init(&temp,10);
	int i=0;
	printf("斜坡式增长到1：\n");
	for(i=0;i<10;i++)
	{
		x=ramp_calc(&temp);
		printf("%.2f\n",x);
	}
	//初始化 
	ramp_init(&temp,10);
	printf("斜坡式下降到1：\n");
	for(i=0;i<10;i++)
	{
		x=-ramp_calc(&temp);
		printf("%.2f\n",x);
	}
	return 0;
}
