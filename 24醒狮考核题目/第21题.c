//���дһ������������һ��������������鳤����Ϊ��������
//�������е����ֵ����ͨ��ָ�뽫���ֵ���ظ����ú�����(����Ҫ
//��:���ýṹ����ָ��������ݽ��) 
#include <stdio.h>
void FindMax(int *arr,int length,int *max);
int main() 
{
	int arr[] = {8, 11, 4, 2, 6};
	int length = sizeof(arr) / sizeof(arr[0]);
	int max;
	//�ڴ���д���� ��
	FindMax(arr,length,&max);
	//�ڴ���д���� ��
	printf("���ֵ��%d\n", max);
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

