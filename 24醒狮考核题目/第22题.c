#include <stdio.h>
//> ע�⣺��׼�����������ֵ��ֻ�ɸ�����������
void Control(int *nowspeed,int maxspeed);
int main() {
	int nowspeed=5000,maxspeed=4000;
	//�����һ��void���� ��
	Control(&nowspeed,maxspeed);
	//���ڴ˲���һ������ ��
 	printf("nowspeed:%d\n",nowspeed);
 	return 0;
}
//���ڴ˲��亯����
//��һ������Ϊ�����ǰת�٣��ڶ���������������� 
void Control(int *nowspeed,int maxspeed)
{
	if(*nowspeed>maxspeed)
	{
		*nowspeed=maxspeed;
	}
	else if(*nowspeed<-maxspeed)
	{
		*nowspeed=-maxspeed;
	}
}
//���ڴ˲��亯����
//> ע��:�ٲ��ɼ���ȫ�ֱ���!
