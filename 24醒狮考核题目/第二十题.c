#include<stdio.h>
typedef struct S
{
	char name[20];     //���� 
	int  num;          //ѧ�� 
	float score;       //�ɼ� 
}Student;
//������� 
void Print(Student *stu)
{
	printf("����   ѧ��   �ɼ�\n");
	int i=0;
	for(i=0;i<2;i++)
	{
		printf("%s   %d    %.2f\n",stu[i].name,stu[i].num,stu[i].score); 
	}
}
int main()
{
	Student stu[2]={{"С��",101,94.5},{"С��",102,89.3}};
	Print(stu);
	return 0;
}

