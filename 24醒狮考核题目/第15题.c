#include<stdio.h>
typedef unsigned int uint32_t;
typedef struct
{
	uint32_t get_count;
	uint32_t set_count;
	float out;
}ramp_t;
//��ʼ�� 
void ramp_init(ramp_t *ramp,uint32_t target_count)
{
	ramp->get_count = 0;
	ramp->set_count = target_count;
	ramp->out = 0;
}
//б��ʽ���� 
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
	//�����Ա���x 
	float x=0;
	//��ʼ�� 
	ramp_init(&temp,10);
	int i=0;
	printf("б��ʽ������1��\n");
	for(i=0;i<10;i++)
	{
		x=ramp_calc(&temp);
		printf("%.2f\n",x);
	}
	//��ʼ�� 
	ramp_init(&temp,10);
	printf("б��ʽ�½���1��\n");
	for(i=0;i<10;i++)
	{
		x=-ramp_calc(&temp);
		printf("%.2f\n",x);
	}
	return 0;
}
