#include <stdio.h>
typedef enum
{
	GIMBAL_INIT_NEVER=0,
	GIMBAL_INIT_DONE,
	NO_ACTION,
	IS_ACTION  
}gimbal_state_t;
int main()
{
	//定义枚举变量 
	gimbal_state_t gimbalState;
	//云台当前状态 
	gimbalState=GIMBAL_INIT_DONE;
	printf("云台当前状态：%d",gimbalState);
	return 0;
}

