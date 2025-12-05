#include <stdio.h>
//> 注意：不准在这给变量赋值，只可给函数声明！
void Control(int *nowspeed,int maxspeed);
int main() {
	int nowspeed=5000,maxspeed=4000;
	//请插入一个void函数 ↓
	Control(&nowspeed,maxspeed);
	//请在此插入一个函数 ↑
 	printf("nowspeed:%d\n",nowspeed);
 	return 0;
}
//请在此补充函数↓
//第一个参数为电机当前转速，第二个参数是最大限速 
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
//请在此补充函数↑
//> 注意:①不可加入全局变量!
