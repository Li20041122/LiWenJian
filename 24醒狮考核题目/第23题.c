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
	//����ö�ٱ��� 
	gimbal_state_t gimbalState;
	//��̨��ǰ״̬ 
	gimbalState=GIMBAL_INIT_DONE;
	printf("��̨��ǰ״̬��%d",gimbalState);
	return 0;
}

