# define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
#include "Funtion.h"
extern T teacher[20];
int main()
{
	int result=-1;
	char command[100] = {0};
	printf("���������ֿ���:");
	scanf("%s", command);
	//�������Ƿ���ȷ
	result = ExamCommand(command);
	if (result == 0)
		return 0;
	//���������ȷ����ʾ�˵�
	while (1)
	{
		//ѡ��
		int choice;
		//�ٽ���ѭ���ж�����ϵͳ�Ƿ������ֹ���
		while (1)
		{
			MenuShow();
			scanf("%d", &choice);
			if (choice > 7 || choice < 1)
			{
				printf(" ________________________________________________________________\n");
				printf("|                                                                |\n");
				printf("|                 ��Ǹ��û�����ֹ��ܣ���������ѡ��               |\n");
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
			printf("|              ��л��ʹ�ñ�ϵͳ��ף��ÿ���������!               |\n");
			printf("|________________________________________________________________|\n");
			return 0; break;
		}
	}
	return 0;
}