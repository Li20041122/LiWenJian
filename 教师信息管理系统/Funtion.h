#pragma once
#ifndef __FUNTION_H
#define __FUNTION_H
//�����ļ�
extern FILE* fp;
//����һ�����ڽ�ʦ������Ϣ�Ľṹ��
typedef struct Teacher {
	long int Number;          //��ʦ��
	char Name[20];			  //����
	char Gender[5];			  //�Ա�
	int Age;			      //����
	char Education[20];		  //ѧ��
	char Occupation[50];	  //ְ��
	double Salary;			  //����
	char Address[50];		  //��ַ
	char Telephone[17];  //�绰
} T;
//�����ʼ��ʦ����
extern int TeacherNum;
//����
void MenuShow();
int ExamCommand(char x[]);
void InputTea(void);
void DeleteTea(void);
void SufTea(void);
void LookupTea(void); 
void ChangeTea(void);
void SortTea();
#endif // !__FUNTION_H

