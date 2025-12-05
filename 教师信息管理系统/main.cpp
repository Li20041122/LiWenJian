# define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
#include "Funtion.h"
extern T teacher[20];
int main()
{
	int result=-1;
	char command[100] = {0};
	printf("请输入数字口令:");
	scanf("%s", command);
	//检测口令是否正确
	result = ExamCommand(command);
	if (result == 0)
		return 0;
	//输入口令正确后显示菜单
	while (1)
	{
		//选择
		int choice;
		//再建个循环判断输入系统是否含有这种功能
		while (1)
		{
			MenuShow();
			scanf("%d", &choice);
			if (choice > 7 || choice < 1)
			{
				printf(" ________________________________________________________________\n");
				printf("|                                                                |\n");
				printf("|                 抱歉，没有这种功能，请您重新选择               |\n");
				printf("|________________________________________________________________|\n");
				printf("\n");
			}
			else
			{
				break;
			}
		}
		switch (choice)
		{
		case 1:
			InputTea(); break;
		case 2:
			DeleteTea(); break;
		case 3:
			SufTea(); break;
		case 4:
			LookupTea(); break;
		case 5:
			SortTea(); break;
		case 6:
			ChangeTea(); break;
		case 7:
			printf(" ________________________________________________________________\n");
			printf("|                                                                |\n");
			printf("|              感谢您使用本系统，祝您每天生活愉快!               |\n");
			printf("|________________________________________________________________|\n");
			return 0; break;
		}
	}
	return 0;
}