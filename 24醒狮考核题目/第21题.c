//请编写一个函数，接收一个整型数组和数组长度作为参数，找
//出数组中的最大值，并通过指针将最大值返回给调用函数。(特殊要
//求:利用结构体与指针相关内容解决) 
#include <stdio.h>
void FindMax(int *arr,int length,int *max);
int main() 
{
	int arr[] = {8, 11, 4, 2, 6};
	int length = sizeof(arr) / sizeof(arr[0]);
	int max;
	//在此填写函数 ↓
	FindMax(arr,length,&max);
	//在此填写函数 ↑
	printf("最大值：%d\n", max);
	return 0;
}
void FindMax(int *arr,int length,int *max)
{
	int i;
	*max=arr[0];
	for(i=0;i<length;i++)
	{
		if(arr[i+1]>*max)
		*max=arr[i+1];
	}
}

