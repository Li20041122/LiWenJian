#include<stdio.h>
typedef struct S
{
	char name[20];     //姓名 
	int  num;          //学号 
	float score;       //成绩 
}Student;
//输出函数 
void Print(Student *stu)
{
	printf("姓名   学号   成绩\n");
	int i=0;
	for(i=0;i<2;i++)
	{
		printf("%s   %d    %.2f\n",stu[i].name,stu[i].num,stu[i].score); 
	}
}
int main()
{
	Student stu[2]={{"小红",101,94.5},{"小明",102,89.3}};
	Print(stu);
	return 0;
}

