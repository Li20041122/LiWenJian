#include<stdio.h>
typedef unsigned char uint8_t;
typedef unsigned short int uint16_t;
uint8_t alpha = 0;
uint8_t beta = 0;
uint16_t gama = 20001;
int main()
{
	//����߰�λ 
	beta=gama >>8;
	//����Ͱ�λ 
	alpha=gama & 0xFF;
	printf("�߰�λ��%d\n",beta);
	printf("�Ͱ�λ��%d\n",alpha);
	return 0;
}
