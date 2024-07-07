#include <stdio.h>
typedef enum
{
	Math=0,           //数学 
	English,		  //英语 
	Physics,          //物理 
	Chemical          //化学 
}CourseType;
typedef struct 
{
	CourseType type;  //课程 
	int credit;       //学分 
	float score;      //成绩 
}Course;
Course arr[12];
Course *courses=NULL;
//输入函数 
void addCourse(int count) 
{
	//超过10提示数组已满 
	if(count>=10)
	{
		printf("Error:数组已满\n");
		return ;
	}
	//记录科目类型 
	int type;
	printf("请输入科目(0=Math, 1=English, 2=Physics, 3=Chemistry): \n");
	scanf("%d",&type);
	courses[count].type=(CourseType)type;
	printf("请输入学分：\n");
	scanf("%d",&courses[count].credit);
	printf("请输入成绩：\n");
	scanf("%f",&courses[count].score);
}
//计算绩点函数 
float calculateGPA(int CourseNumber)
{
	//超过10强制等于10 
	if(CourseNumber>10)
	{
		CourseNumber=10;
	}
	float Signal_GPA=0;
	float Sum_GPA=0;
	float Eve_GPA=0;
	int i=0;
	//遍历 
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
	//计算平均数 
	Eve_GPA=Sum_GPA/CourseNumber;
	return Eve_GPA;
}
int main()
{
	//令指针指向数组 
	courses=arr;
	//平均绩点 
	float Eve_GPA=0;
	int i;
	//CourseNumber用来计数有多少课程 
	int CourseNumber=0;
	printf("请输入课程数量："); 
	scanf("%d",&CourseNumber);
	printf("请输入课程信息：\n");
	for(i=0;i<CourseNumber;i++)
	{ 
		addCourse(i);
	}
	Eve_GPA=calculateGPA(CourseNumber);
	printf("绩点：%.2f\n",Eve_GPA); 
	return 0;
}

