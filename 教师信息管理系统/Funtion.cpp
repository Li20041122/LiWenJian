# define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
#include<string.h>
#include "Funtion.h"
int TeacherNum=0;
FILE* fp;
//初始教师信息
T teacher[23];
//显示菜单
void MenuShow()
{
	printf(" ________________________________________________________________\n");
	printf("|                    |                      |                    |\n");
	printf("|                    |         菜单         |                    |\n");
	printf("|____________________|______________________|____________________|\n");
	printf("|                    |                      |                    |\n");
	printf("|1.教师信息录入功能  |2.教师信息删除功能    |3.教师信息浏览功能  |\n");
	printf("|____________________|______________________|____________________|\n");
	printf("|                    |                      |                    |\n");
	printf("|4.教师信息查询功能  |5.教师信息排序功能    |6.教师信息修改功能  |\n");
	printf("|____________________|______________________|____________________|\n");
	printf("|                    |                      |                    |\n");
	printf("|7.退出              |                      |                    |\n");
	printf("|____________________|______________________|____________________|\n");
	printf("请选择:");
}
//口令检查
int ExamCommand(char x[])
{
	//设置为数字密码型口令，口令不为0
	char command[100] = "1";
	//count用来计数
	int count=0;
	while (strcmp(x,command)!=0)
	{
		if (count == 2)
		{
			printf(" ________________________________________________________________\n");
			printf("|                                                                |\n");
			printf("|                          已退出系统!                           |\n");
			printf("|________________________________________________________________|\n");
			return 0;
		}
		count++;
		printf(" ________________________________________________________________\n");
		printf("|                                                                |\n");
		printf("|                口令不对，请重新输入(最多输入三次)              |\n");
		printf("|________________________________________________________________|\n");
		printf("\n");
		printf("口令:");
		scanf("%s", x);
	}
	printf(" ________________________________________________________________\n");
	printf("|                                                                |\n");
	printf("|                   口令正确，欢迎您使用本系统!                  |\n");
	printf("|________________________________________________________________|\n");
	return 1;
}
//教师信息录入
void InputTea()
{
	printf(" ________________________________________________________________\n");
	printf("|                                                                |\n");
	printf("|                    教师信息录入功能为您服务！                  |\n");
	printf("|________________________________________________________________|\n");
	//pd用来判断是否要继续录入，count用来记录当前文件中的教师人数
	int people = 0,i = 0,j = 0,count = 0;
	char pd[10];
	int sign;
	T tea[10];
	while (strcmp(pd,"0") != 0)
	{
		printf("你好!请问您需要录入多少名教师信息:");
		scanf("%d", &people);
		//如果people非整数，是无效数字
		if (people == 0 || people < 0)
		{
			printf("无效数字\n");
			return;
		}
		for (i = 0; i < people; i++)
		{
			//每次遍历都清零
			count = 0;
			//每次遍历都要读一遍文件，实现实时更新教师号，方便下面遍历对比
			fp = fopen("TeacherInformation.txt", "rb");
			if (fp == NULL)
			{
				printf("文件打开失败\n");
				return;
			}
			while (!feof(fp))
			{
				if (fread(&teacher[count], sizeof(T), 1, fp))
					count++;
			}
			fclose(fp);
			sign = 0;
			//按顺序输入教师信息
			printf("\n教师号:");scanf("%ld", &tea[i].Number);
			for (j = 0; j < count; j++)
			{
				if (teacher[j].Number == tea[i].Number)
				{
					printf(" ________________________________________________________________\n");
					printf("|                                                                |\n");
					printf("|                    已有此教师号，请重新输入                    |\n");
					printf("|________________________________________________________________|\n");
					printf("\n");
					sign = 1;
					break;
				}
			}
			if (sign)
			{
				i--;
				continue;
			}
			printf("\n姓名:");  scanf("%s", tea[i].Name);
			printf("\n性别:");  scanf("%s", tea[i].Gender);
			printf("\n年龄:");  scanf("%d", &tea[i].Age);
	        printf("\n学历:");  scanf("%s", tea[i].Education);
			printf("\n职称:");  scanf("%s", tea[i].Occupation);
			printf("\n工资:");  scanf("%lf", &tea[i].Salary);
			printf("\n地址:");  scanf("%s", tea[i].Address);
			printf("\n电话:");  scanf("%s", tea[i].Telephone);
			fp = fopen("TeacherInformation.txt", "ab");
			if (fp == NULL)
			{
				printf("文件打开失败\n");
				return;
			}
			fwrite(&tea[i], sizeof(T), 1, fp);
			fclose(fp);
		}
		while (1)
		{
			printf("\n请问是否需要继续录入教师信息,是的话输入1,否的话就输入0:");
			//把数字限制在0和1
			scanf("%s", pd);
			if (strcmp(pd, "0") == 0 || strcmp(pd, "1") == 0)
			{
				break;
			}
			else
			{
				printf("\n没有这种选择，请您重新输入\n");
			}
		}
	}
	fclose(fp);
	printf(" ________________________________________________________________\n");
	printf("|                                                                |\n");
	printf("|                    恭喜,教师信息录入完毕!                      |\n");
	printf("|________________________________________________________________|\n");
	printf("\n");
	printf("请继续选择您需要的功能\n");
	return;
}
//教师信息删除
void DeleteTea()
{
	printf(" ________________________________________________________________\n");
	printf("|                                                                |\n");
	printf("|                    教师信息删除功能为您服务！                  |\n");
	printf("|________________________________________________________________|\n");
	//pd用来判断客户是否需要继续删除,is_No用来判断是否有这个教师号
	int Number, i = 0, j = 0, count = 0, is_No=1;
	char pd[10];
	//当前教师人数记为0
	printf("请输入您要删除教师的教师号:");
	scanf("%d", &Number);
	while (1)
	{
		//重新定义为1
		is_No = 1;
		fp = fopen("TeacherInformation.txt", "rb");
		if (fp == NULL)
		{
			printf("文件打开失败\n");
			return;
		}
		while (!feof(fp))
		{
			if (fread(&teacher[count], sizeof(T), 1, fp))
				count++;
		}
		fclose(fp);
		fp = fopen("TeacherInformation.txt", "wb");
		if (fp == NULL)
		{
			printf("文件打开失败\n");
			return;
		}
		for (i = 0; i < count; i++)
		{
			if (teacher[i].Number == Number)
			{
				for (j = i; j < count; j++)
				{
					//后一个结构体数组把前一个覆盖掉
					teacher[j] = teacher[j + 1];
				}
				is_No = 0;
				//不需要最后一个结构体，所以count--
				count--;
				break;
			}
		}
		if (is_No)
		{
			printf("\n抱歉，没有这个教师号\n");
		}
		for (i = 0; i < count; i++)
		{
			fwrite(&teacher[i], sizeof(T), 1, fp);
		}
		//count清零，方便下次重新计数
		count = 0;
		fclose(fp);
		while (1)
		{
			//把数字限制在0和1
			printf("\n请问是否需要继续删除,是的话输入1，否的话输入0:");
			scanf("%s", pd);
			if (strcmp(pd, "0") == 0 || strcmp(pd, "1") == 0)
			{
				break;
			}
			else
			{
				printf("\n没有这种选择，请您重新输入\n");
			}
		}
		if (strcmp(pd, "0") == 0)
			break;
		printf("请输入您要删除教师的教师号:");
		scanf("%d", &Number);
	}
	printf(" ________________________________________________________________\n");
	printf("|                                                                |\n");
	printf("|                    恭喜,教师信息删除完毕!                      |\n");
	printf("|________________________________________________________________|\n");
	printf("\n");
	printf("请继续选择您需要的功能\n");
	return;
}
//教师信息浏览
void SufTea()
{
	printf(" ________________________________________________________________\n");
	printf("|                                                                |\n");
	printf("|                    教师信息浏览功能为您服务！                  |\n");
	printf("|________________________________________________________________|\n");
	//pd用于判断是否继续浏览,count用于fread遍历
	int i = 0,count = 0;
	char pd[10];
	while (1)
	{
		fp = fopen("TeacherInformation.txt", "rb");
		if (fp == NULL)
		{
			printf("文件打开失败\n");
			return;
		}
		count = 0;
		while (!feof(fp))
		{
			if(fread(&teacher[count], sizeof(T), 1, fp))
			count++;
		}
		if (count == 0)
		{
			printf(" ________________________________________________________________\n");
			printf("|                                                                |\n");
			printf("|               抱歉,现在系统里暂时没有教师信息                  |\n");
			printf("|________________________________________________________________|\n");
			break;
		}
		printf("\n您好，以下是已有的教师信息\n");
		printf(" ____________________________________________________________________________________________________________________\n");
		printf("|            |            |            |            |            |            |            |            |            |\n");
		printf("|教师号      |姓名        |性别        |年龄        |学历        |职称        |工资        |住址        |电话        |\n");
		printf("|____________|____________|____________|____________|____________|____________|____________|____________|____________|\n");
		for (i = 0; i < count; i++)
		{
			printf("|            |            |            |            |            |            |            |            |            |\n");
			printf("|%-12ld|%-12s|%-12s|%-12d|%-12s|%-12s|%-12.2lf|%-12s|%-12s|\n",
				teacher[i].Number, teacher[i].Name, teacher[i].Gender, teacher[i].Age,
				teacher[i].Education, teacher[i].Occupation, teacher[i].Salary, teacher[i].Address,
				teacher[i].Telephone);
			printf("|____________|____________|____________|____________|____________|____________|____________|____________|____________|\n");
		}
		fclose(fp);
		while (1)
		{
			//把数字限制在0和1
			printf("\n请问是否需要继续浏览教师信息,是的话输入非0数，否的话输入0:");
			scanf("%s", pd);
			if (strcmp(pd, "0") == 0 || strcmp(pd, "1") == 0)
			{
				break;
			}
			else
			{
				printf("\n没有这种选择，请您重新输入\n");
			}
		}
		if (strcmp(pd, "0") == 0)
			break;
	}
	printf("\n请继续选择您需要的功能\n");
	return;
}
//教师信息查询
void LookupTea()
{
	printf(" ________________________________________________________________\n");
	printf("|                                                                |\n");
	printf("|                    教师信息查询功能为您服务！                  |\n");
	printf("|________________________________________________________________|\n");
	//findway用于判断查询方式
	int findway = 0, i;
	char pd[10];
	printf("\n您好，以下是两种查询方式:\n");
	while (1)
	{
		fp = fopen("TeacherInformation.txt", "rb");
		if (fp == NULL)
		{
			printf("文件打开失败\n");
			return;
		}
		printf(" ________________________________________________________________\n");
		printf("|                                                                |\n");
		printf("|按教师号查询:请按1                                              |\n");
		printf("|________________________________________________________________|\n");
		printf("|                                                                |\n");
		printf("|按职称查询:请按2                                                |\n");
		printf("|________________________________________________________________|\n");
		printf("您的选择是:");
		scanf("%d", &findway);
		if ((findway != 1) &&( findway != 2))
		{
			printf(" ________________________________________________________________\n");
			printf("|                                                                |\n");
			printf("|                      抱歉，没有这种查询方式                    |\n");
			printf("|________________________________________________________________|\n");
			printf("\n");
		}
		else
		{
			if (findway == 1)
			{
				int Number;
				//count1用来记录当前已有的教师人数
				int count1 = 0;
				//要考虑没有这个教师号的情况
				printf("请输入要查询的教师号:");
				scanf("%d", &Number);
				while (!feof(fp))
				{
					if (fread(&teacher[count1], sizeof(T), 1, fp))
						count1++;
				}
				for (i = 0; i < count1; i++)
				{
					if (teacher[i].Number == Number)
					{
						printf("\n您好，以下是这个教师的信息:\n");
						printf(" ____________________________________________________________________________________________________________________\n");
						printf("|            |            |            |            |            |            |            |            |            |\n");
						printf("|教师号      |姓名        |性别        |年龄        |学历        |职称        |工资        |住址        |电话        |\n");
						printf("|___________ |____________|____________|____________|____________|____________|____________|____________|____________|\n");
						printf("|            |            |            |            |            |            |            |            |            |\n");
						printf("|%-12ld|%-12s|%-12s|%-12d|%-12s|%-12s|%-12.2lf|%-12s|%-12s|\n",
							teacher[i].Number, teacher[i].Name, teacher[i].Gender, teacher[i].Age,
							teacher[i].Education, teacher[i].Occupation, teacher[i].Salary, teacher[i].Address,
							teacher[i].Telephone);
						printf("|___________ |____________|____________|____________|____________|____________|____________|____________|____________|\n");
						//立刻打断，方便后面判断
						break;
					}
				}
				if (i == count1)
				{
					printf(" ________________________________________________________________\n");
					printf("|                                                                |\n");
					printf("|              抱歉，教师系统里没有记录到这个教师号              |\n");
					printf("|________________________________________________________________|\n");
					printf("\n");
				}
			}
			if (findway == 2)
			{
				char Ocu[50];
				//count2用来记录当前已有的教师人数
				int count2 = 0;
				//要考虑没有这个教师号的情况
				printf("请输入要查询的职称:");
				scanf("%s", Ocu);
				while (!feof(fp))
				{
					if (fread(&teacher[count2], sizeof(T), 1, fp))
						count2++;
				}
				for (i = 0; i < count2; i++)
				{
					if (strcmp(Ocu,teacher[i].Occupation) == 0)
					{
						printf("\n您好，以下是这个教师的信息:\n");
						printf(" ____________________________________________________________________________________________________________________\n");
						printf("|            |            |            |            |            |            |            |            |            |\n");
						printf("|教师号      |姓名        |性别        |年龄        |学历        |职称        |工资        |住址        |电话        |\n");
						printf("|___________ |____________|____________|____________|____________|____________|____________|____________|____________|\n");
						printf("|            |            |            |            |            |            |            |            |            |\n");
						printf("|%-12ld|%-12s|%-12s|%-12d|%-12s|%-12s|%-12.2lf|%-12s|%-12s|\n",
							teacher[i].Number, teacher[i].Name, teacher[i].Gender, teacher[i].Age,
							teacher[i].Education, teacher[i].Occupation, teacher[i].Salary, teacher[i].Address,
							teacher[i].Telephone);
						printf("|___________ |____________|____________|____________|____________|____________|____________|____________|____________|\n");
						//立刻打断，方便后面判断
						break;
					}
				}
				if (i == count2)
				{
					printf(" ________________________________________________________________\n");
					printf("|                                                                |\n");
					printf("|          抱歉，教师系统里没有记录到拥有这个职称的老师          |\n");
					printf("|________________________________________________________________|\n");
					printf("\n");
				}
			}
		}
		fclose(fp);
		while (1)
		{
			printf("\n请问您是否需要继续查询，是的话输入1，否的话输入0:");
			scanf("%s", pd);
			if (strcmp(pd, "0") == 0 || strcmp(pd, "1") == 0)
			{
				break;
			}
			else
			{
				printf("\n没有这种选择，请您重新输入\n");
			}

		}
		if (strcmp(pd, "0") == 0)
		{
			break;
		}
	}
	printf("\n请继续选择您需要的功能\n");
}
//教师信息修改
void ChangeTea()
{
	printf(" ________________________________________________________________\n");
	printf("|                                                                |\n");
	printf("|                    教师信息修改功能为您服务！                  |\n");
	printf("|________________________________________________________________|\n");
	//pd用来判断客户是否需要继续修改,is_No用来判断是否有这个教师号
	int Number, i = 0, j = 0, count = 0, is_No = 1;
	char pd[10];
	//以下是用户重新定义的信息
	long int NewNumber;          //教师号
	char NewName[20];			  //姓名
	char NewGender[5];			  //性别
	int  NewAge;			      //年龄
	char NewEducation[20];		  //学历
	char NewOccupation[50];	      //职称
	double NewSalary;			  //工资
	char NewAddress[50];		  //地址
	char NewTelephone[17];        //电话
	//change用于判断修改内容
	int change = 0;
	printf("\n请输入你要修改教师的教师号:");
	scanf("%d", &Number);
	while (1)
	{
		//重新定义为0
		change = 0;
		//重新定义为0
		is_No = 1;
		fp = fopen("TeacherInformation.txt", "rb");
		if (fp == NULL)
		{
			printf("文件打开失败\n");
			return;
		}
		count = 0;
		while (!feof(fp))
		{
			if (fread(&teacher[count], sizeof(T), 1, fp))
				count++;
		}
		fclose(fp);
		fp = fopen("TeacherInformation.txt", "wb");
		if (fp == NULL)
		{
			printf("文件打开失败\n");
			return;
		}
		for (i = 0; i < count; i++)
		{
			if (teacher[i].Number == Number)
			{
				printf(" ________________________________________________________________\n");
				printf("|                    |                      |                    |\n");
				printf("|                    |     可修改的内容     |                    |\n");
				printf("|____________________|______________________|____________________|\n");
				printf("|                    |                      |                    |\n");
				printf("|1.教师号            |2.教师姓名            |3.教师年龄          |\n");
				printf("|____________________|______________________|____________________|\n");
				printf("|                    |                      |                    |\n");
				printf("|4.教师学历          |5.教师职称            |6.教师工资          |\n");
				printf("|____________________|______________________|____________________|\n");
				printf("|                    |                      |                    |\n");
				printf("|7.教师住址          |8.教师电话            |9.教师性别          |\n");
				printf("|____________________|______________________|____________________|\n");
				printf("\n你要修改的内容是:");
				scanf("%d", &change);
				switch (change)
				{
				case 1:
					printf("请输入新的教师号:"); scanf("%ld", &NewNumber);teacher[i].Number = NewNumber; break;
				case 2:
					printf("请输入新的姓名:"); scanf("%s",NewName); strcpy(teacher[i].Name,NewName); break;
				case 3:
					printf("请输入新的年龄:"); scanf("%d", &NewAge); teacher[i].Age =NewAge; break;
				case 4:
					printf("请输入新的学历:"); scanf("%s",NewEducation);strcpy(teacher[i].Education, NewEducation);  break;
				case 5:
					printf("请输入新的职称:"); scanf("%s",NewOccupation); strcpy(teacher[i].Occupation, NewOccupation);  break;
				case 6:
					printf("请输入新的工资:"); scanf("%lf",&NewSalary); teacher[i].Salary = NewSalary; break;
				case 7:
					printf("请输入新的住址:"); scanf("%s", NewAddress); strcpy(teacher[i].Address, NewAddress);  break;
				case 8:
					printf("请输入新的电话:"); scanf("%s", NewTelephone);strcpy(teacher[i].Telephone, NewTelephone); break;
				case 9:
					printf("请输入新的性别:"); scanf("%s", NewGender); strcpy(teacher[i].Gender, NewGender); break;
				}
				is_No = 0;
				break;
			}
		}
		if (is_No!=0)
		{
			for (i = 0; i < count; i++)
			{
				fwrite(&teacher[i], sizeof(T), 1, fp);
			}
			printf(" ________________________________________________________________\n");
			printf("|                                                                |\n");
			printf("|                       抱歉，没有这个教师号                     |\n");
			printf("|________________________________________________________________|\n");
			printf("\n");
			fclose(fp);
		}
		else
		{
			//写入文件
			for (i = 0; i < count; i++)
			{
				fwrite(&teacher[i], sizeof(T), 1, fp);
			}
			//count清零，方便下次重新计数
			count = 0;
			fclose(fp);
			printf(" ________________________________________________________________\n");
			printf("|                                                                |\n");
			printf("|                     恭喜，教师信息修改完毕!                    |\n");
			printf("|________________________________________________________________|\n");
			printf("\n");
		}
		while (1)
		{
			printf("\n请问是否需要继续修改,是的话输入1，否的话输入0:");
			scanf("%s", pd);
			if (strcmp(pd, "0") == 0 || strcmp(pd, "1") == 0)
			{
				break;
			}
			else
			{
				printf("\n没有这种选择，请您重新输入\n");
			}
		}
		
		if (strcmp(pd, "0") == 0)
			break;
		printf("请输入你要修改教师的教师号:");
		scanf("%d", &Number);
	}
	printf("\n请继续选择你需要的功能\n");
	return;
}
//教师信息排序
void SortTea()
{
	printf(" ________________________________________________________________\n");
	printf("|                                                                |\n");
	printf("|                    教师信息排序功能为您服务！                  |\n");
	printf("|________________________________________________________________|\n");
	//临时变量，用来互换
	T TeaTemp;
	//count用于fread遍历,choice用来选择排序方式
	int i = 0,count = 0, choice = 0, j = 0;
	while (1)
	{
		printf("\n以下是几种排序方式:\n");
		printf(" ________________________________________________________________\n");
		printf("|                                                                |\n");
		printf("|1.按教师号排序(从小到大)                                        |\n");
		printf("|________________________________________________________________|\n");
		printf("|                                                                |\n");
		printf("|2.按工资查询(从大到小)                                          |\n");
		printf("|________________________________________________________________|\n");
		printf("\n请选择排序方式: ");
		scanf("%d", &choice);
		fp = fopen("TeacherInformation.txt", "rb");
		if (fp == NULL)
		{
			printf("文件打开失败\n");
			return;
		}
		count = 0;
		while (!feof(fp))
		{
			if (fread(&teacher[count], sizeof(T), 1, fp))
				count++;
		}
		fclose(fp);
		fp = fopen("TeacherInformation.txt", "wb");
		if (fp == NULL)
		{
			printf("文件打开失败\n");
			return;
		}
		if (choice == 1)
		{
			//按教师号排序
			for (i = 0; i < count - 1; i++)
			{
				for (j = 0; j < count - 1 - i; j++)
				{
					if (teacher[j].Number > teacher[j + 1].Number)
					{
						TeaTemp = teacher[j];
						teacher[j] = teacher[j + 1];
						teacher[j + 1] = TeaTemp;
					}
				}
			}
			//写入文件
			for (i = 0; i < count; i++)
			{
				fwrite(&teacher[i], sizeof(T), 1, fp);
			}
			fclose(fp);
			break;
		}
		else if (choice == 2)
		{
			//按工资排序
			for (i = 0; i < count - 1; i++)
			{
				for (j = 0; j < count - 1 - i; j++)
				{
					if (teacher[j].Salary < teacher[j + 1].Salary)
					{
						TeaTemp = teacher[j];
						teacher[j] = teacher[j + 1];
						teacher[j + 1] = TeaTemp;
					}
				}
			}
			//写入文件
			for (i = 0; i < count; i++)
			{
				fwrite(&teacher[i], sizeof(T), 1, fp);
			}
			fclose(fp);
			break;
		}
		else
		{
			printf(" ________________________________________________________________\n");
			printf("|                                                                |\n");
			printf("|             抱歉，没有这种排序方式，请您重新选择               |\n");
			printf("|________________________________________________________________|\n");
			printf("\n");
		}
		fclose(fp);
	}
	printf("\n排序完毕\n请继续选择你需要的功能\n");
	return;
}