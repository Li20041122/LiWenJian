#pragma once
#ifndef __FUNTION_H
#define __FUNTION_H
//定义文件
extern FILE* fp;
//定义一个关于教师基本信息的结构体
typedef struct Teacher {
	long int Number;          //教师号
	char Name[20];			  //姓名
	char Gender[5];			  //性别
	int Age;			      //年龄
	char Education[20];		  //学历
	char Occupation[50];	  //职称
	double Salary;			  //工资
	char Address[50];		  //地址
	char Telephone[17];  //电话
} T;
//定义初始教师人数
extern int TeacherNum;
//功能
void MenuShow();
int ExamCommand(char x[]);
void InputTea(void);
void DeleteTea(void);
void SufTea(void);
void LookupTea(void); 
void ChangeTea(void);
void SortTea();
#endif // !__FUNTION_H

