#include <stdio.h>
typedef enum
{
	Math=0,           //��ѧ 
	English,		  //Ӣ�� 
	Physics,          //���� 
	Chemical          //��ѧ 
}CourseType;
typedef struct 
{
	CourseType type;  //�γ� 
	int credit;       //ѧ�� 
	float score;      //�ɼ� 
}Course;
Course arr[12];
Course *courses=NULL;
//���뺯�� 
void addCourse(int count) 
{
	//����10��ʾ�������� 
	if(count>=10)
	{
		printf("Error:��������\n");
		return ;
	}
	//��¼��Ŀ���� 
	int type;
	printf("�������Ŀ(0=Math, 1=English, 2=Physics, 3=Chemistry): \n");
	scanf("%d",&type);
	courses[count].type=(CourseType)type;
	printf("������ѧ�֣�\n");
	scanf("%d",&courses[count].credit);
	printf("������ɼ���\n");
	scanf("%f",&courses[count].score);
}
//���㼨�㺯�� 
float calculateGPA(int CourseNumber)
{
	//����10ǿ�Ƶ���10 
	if(CourseNumber>10)
	{
		CourseNumber=10;
	}
	float Signal_GPA=0;
	float Sum_GPA=0;
	float Eve_GPA=0;
	int i=0;
	//���� 
	for(i=0;i<CourseNumber;i++)
	{
		if(courses[i].score>=90 && courses[i].score<=90)
			Signal_GPA=4.0;
		else if(courses[i].score>=80 && courses[i].score<=89)
			Signal_GPA=3.0;
		else if(courses[i].score>=70 && courses[i].score<=79)
			Signal_GPA=2.0;
		else if(courses[i].score>=60 && courses[i].score<=69)
			Signal_GPA=1.0;
		else if(courses[i].score<60)
			Signal_GPA=0;
		Sum_GPA+=Signal_GPA;
	}
	//����ƽ���� 
	Eve_GPA=Sum_GPA/CourseNumber;
	return Eve_GPA;
}
int main()
{
	//��ָ��ָ������ 
	courses=arr;
	//ƽ������ 
	float Eve_GPA=0;
	int i;
	//CourseNumber���������ж��ٿγ� 
	int CourseNumber=0;
	printf("������γ�������"); 
	scanf("%d",&CourseNumber);
	printf("������γ���Ϣ��\n");
	for(i=0;i<CourseNumber;i++)
	{ 
		addCourse(i);
	}
	Eve_GPA=calculateGPA(CourseNumber);
	printf("���㣺%.2f\n",Eve_GPA); 
	return 0;
}

