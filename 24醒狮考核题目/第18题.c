#include<stdio.h>
typedef unsigned char uint8_t;
typedef unsigned short int uint16_t;
uint8_t alpha = 0;
uint8_t beta = 0;
uint16_t gama = 20001;
int main()
{
	//分离高八位 
	beta=gama >>8;
	//分离低八位 
	alpha=gama & 0xFF;
	printf("高八位：%d\n",beta);
	printf("低八位：%d\n",alpha);
	return 0;
}
