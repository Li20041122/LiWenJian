# define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
#include<string.h>
#include "Funtion.h"
int TeacherNum=0;
FILE* fp;
//��ʼ��ʦ��Ϣ
T teacher[23];
//��ʾ�˵�
void MenuShow()
{
	printf(" ________________________________________________________________\n");
	printf("|                    |                      |                    |\n");
	printf("|                    |         �˵�         |                    |\n");
	printf("|____________________|______________________|____________________|\n");
	printf("|                    |                      |                    |\n");
	printf("|1.��ʦ��Ϣ¼�빦��  |2.��ʦ��Ϣɾ������    |3.��ʦ��Ϣ�������  |\n");
	printf("|____________________|______________________|____________________|\n");
	printf("|                    |                      |                    |\n");
	printf("|4.��ʦ��Ϣ��ѯ����  |5.��ʦ��Ϣ������    |6.��ʦ��Ϣ�޸Ĺ���  |\n");
	printf("|____________________|______________________|____________________|\n");
	printf("|                    |                      |                    |\n");
	printf("|7.�˳�              |                      |                    |\n");
	printf("|____________________|______________________|____________________|\n");
	printf("��ѡ��:");
}
//������
int ExamCommand(char x[])
{
	//����Ϊ���������Ϳ�����Ϊ0
	char command[100] = "1";
	//count��������
	int count=0;
	while (strcmp(x,command)!=0)
	{
		if (count == 2)
		{
			printf(" ________________________________________________________________\n");
			printf("|                                                                |\n");
			printf("|                          ���˳�ϵͳ!                           |\n");
			printf("|________________________________________________________________|\n");
			return 0;
		}
		count++;
		printf(" ________________________________________________________________\n");
		printf("|                                                                |\n");
		printf("|                ����ԣ�����������(�����������)              |\n");
		printf("|________________________________________________________________|\n");
		printf("\n");
		printf("����:");
		scanf("%s", x);
	}
	printf(" ________________________________________________________________\n");
	printf("|                                                                |\n");
	printf("|                   ������ȷ����ӭ��ʹ�ñ�ϵͳ!                  |\n");
	printf("|________________________________________________________________|\n");
	return 1;
}
//��ʦ��Ϣ¼��
void InputTea()
{
	printf(" ________________________________________________________________\n");
	printf("|                                                                |\n");
	printf("|                    ��ʦ��Ϣ¼�빦��Ϊ������                  |\n");
	printf("|________________________________________________________________|\n");
	//pd�����ж��Ƿ�Ҫ����¼�룬count������¼��ǰ�ļ��еĽ�ʦ����
	int people = 0,i = 0,j = 0,count = 0;
	char pd[10];
	int sign;
	T tea[10];
	while (strcmp(pd,"0") != 0)
	{
		printf("���!��������Ҫ¼���������ʦ��Ϣ:");
		scanf("%d", &people);
		//���people������������Ч����
		if (people == 0 || people < 0)
		{
			printf("��Ч����\n");
			return;
		}
		for (i = 0; i < people; i++)
		{
			//ÿ�α���������
			count = 0;
			//ÿ�α�����Ҫ��һ���ļ���ʵ��ʵʱ���½�ʦ�ţ�������������Ա�
			fp = fopen("TeacherInformation.txt", "rb");
			if (fp == NULL)
			{
				printf("�ļ���ʧ��\n");
				return;
			}
			while (!feof(fp))
			{
				if (fread(&teacher[count], sizeof(T), 1, fp))
					count++;
			}
			fclose(fp);
			sign = 0;
			//��˳�������ʦ��Ϣ
			printf("\n��ʦ��:");scanf("%ld", &tea[i].Number);
			for (j = 0; j < count; j++)
			{
				if (teacher[j].Number == tea[i].Number)
				{
					printf(" ________________________________________________________________\n");
					printf("|                                                                |\n");
					printf("|                    ���д˽�ʦ�ţ�����������                    |\n");
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
			printf("\n����:");  scanf("%s", tea[i].Name);
			printf("\n�Ա�:");  scanf("%s", tea[i].Gender);
			printf("\n����:");  scanf("%d", &tea[i].Age);
	        printf("\nѧ��:");  scanf("%s", tea[i].Education);
			printf("\nְ��:");  scanf("%s", tea[i].Occupation);
			printf("\n����:");  scanf("%lf", &tea[i].Salary);
			printf("\n��ַ:");  scanf("%s", tea[i].Address);
			printf("\n�绰:");  scanf("%s", tea[i].Telephone);
			fp = fopen("TeacherInformation.txt", "ab");
			if (fp == NULL)
			{
				printf("�ļ���ʧ��\n");
				return;
			}
			fwrite(&tea[i], sizeof(T), 1, fp);
			fclose(fp);
		}
		while (1)
		{
			printf("\n�����Ƿ���Ҫ����¼���ʦ��Ϣ,�ǵĻ�����1,��Ļ�������0:");
			//������������0��1
			scanf("%s", pd);
			if (strcmp(pd, "0") == 0 || strcmp(pd, "1") == 0)
			{
				break;
			}
			else
			{
				printf("\nû������ѡ��������������\n");
			}
		}
	}
	fclose(fp);
	printf(" ________________________________________________________________\n");
	printf("|                                                                |\n");
	printf("|                    ��ϲ,��ʦ��Ϣ¼�����!                      |\n");
	printf("|________________________________________________________________|\n");
	printf("\n");
	printf("�����ѡ������Ҫ�Ĺ���\n");
	return;
}
//��ʦ��Ϣɾ��
void DeleteTea()
{
	printf(" ________________________________________________________________\n");
	printf("|                                                                |\n");
	printf("|                    ��ʦ��Ϣɾ������Ϊ������                  |\n");
	printf("|________________________________________________________________|\n");
	//pd�����жϿͻ��Ƿ���Ҫ����ɾ��,is_No�����ж��Ƿ��������ʦ��
	int Number, i = 0, j = 0, count = 0, is_No=1;
	char pd[10];
	//��ǰ��ʦ������Ϊ0
	printf("��������Ҫɾ����ʦ�Ľ�ʦ��:");
	scanf("%d", &Number);
	while (1)
	{
		//���¶���Ϊ1
		is_No = 1;
		fp = fopen("TeacherInformation.txt", "rb");
		if (fp == NULL)
		{
			printf("�ļ���ʧ��\n");
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
			printf("�ļ���ʧ��\n");
			return;
		}
		for (i = 0; i < count; i++)
		{
			if (teacher[i].Number == Number)
			{
				for (j = i; j < count; j++)
				{
					//��һ���ṹ�������ǰһ�����ǵ�
					teacher[j] = teacher[j + 1];
				}
				is_No = 0;
				//����Ҫ���һ���ṹ�壬����count--
				count--;
				break;
			}
		}
		if (is_No)
		{
			printf("\n��Ǹ��û�������ʦ��\n");
		}
		for (i = 0; i < count; i++)
		{
			fwrite(&teacher[i], sizeof(T), 1, fp);
		}
		//count���㣬�����´����¼���
		count = 0;
		fclose(fp);
		while (1)
		{
			//������������0��1
			printf("\n�����Ƿ���Ҫ����ɾ��,�ǵĻ�����1����Ļ�����0:");
			scanf("%s", pd);
			if (strcmp(pd, "0") == 0 || strcmp(pd, "1") == 0)
			{
				break;
			}
			else
			{
				printf("\nû������ѡ��������������\n");
			}
		}
		if (strcmp(pd, "0") == 0)
			break;
		printf("��������Ҫɾ����ʦ�Ľ�ʦ��:");
		scanf("%d", &Number);
	}
	printf(" ________________________________________________________________\n");
	printf("|                                                                |\n");
	printf("|                    ��ϲ,��ʦ��Ϣɾ�����!                      |\n");
	printf("|________________________________________________________________|\n");
	printf("\n");
	printf("�����ѡ������Ҫ�Ĺ���\n");
	return;
}
//��ʦ��Ϣ���
void SufTea()
{
	printf(" ________________________________________________________________\n");
	printf("|                                                                |\n");
	printf("|                    ��ʦ��Ϣ�������Ϊ������                  |\n");
	printf("|________________________________________________________________|\n");
	//pd�����ж��Ƿ�������,count����fread����
	int i = 0,count = 0;
	char pd[10];
	while (1)
	{
		fp = fopen("TeacherInformation.txt", "rb");
		if (fp == NULL)
		{
			printf("�ļ���ʧ��\n");
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
			printf("|               ��Ǹ,����ϵͳ����ʱû�н�ʦ��Ϣ                  |\n");
			printf("|________________________________________________________________|\n");
			break;
		}
		printf("\n���ã����������еĽ�ʦ��Ϣ\n");
		printf(" ____________________________________________________________________________________________________________________\n");
		printf("|            |            |            |            |            |            |            |            |            |\n");
		printf("|��ʦ��      |����        |�Ա�        |����        |ѧ��        |ְ��        |����        |סַ        |�绰        |\n");
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
			//������������0��1
			printf("\n�����Ƿ���Ҫ���������ʦ��Ϣ,�ǵĻ������0������Ļ�����0:");
			scanf("%s", pd);
			if (strcmp(pd, "0") == 0 || strcmp(pd, "1") == 0)
			{
				break;
			}
			else
			{
				printf("\nû������ѡ��������������\n");
			}
		}
		if (strcmp(pd, "0") == 0)
			break;
	}
	printf("\n�����ѡ������Ҫ�Ĺ���\n");
	return;
}
//��ʦ��Ϣ��ѯ
void LookupTea()
{
	printf(" ________________________________________________________________\n");
	printf("|                                                                |\n");
	printf("|                    ��ʦ��Ϣ��ѯ����Ϊ������                  |\n");
	printf("|________________________________________________________________|\n");
	//findway�����жϲ�ѯ��ʽ
	int findway = 0, i;
	char pd[10];
	printf("\n���ã����������ֲ�ѯ��ʽ:\n");
	while (1)
	{
		fp = fopen("TeacherInformation.txt", "rb");
		if (fp == NULL)
		{
			printf("�ļ���ʧ��\n");
			return;
		}
		printf(" ________________________________________________________________\n");
		printf("|                                                                |\n");
		printf("|����ʦ�Ų�ѯ:�밴1                                              |\n");
		printf("|________________________________________________________________|\n");
		printf("|                                                                |\n");
		printf("|��ְ�Ʋ�ѯ:�밴2                                                |\n");
		printf("|________________________________________________________________|\n");
		printf("����ѡ����:");
		scanf("%d", &findway);
		if ((findway != 1) &&( findway != 2))
		{
			printf(" ________________________________________________________________\n");
			printf("|                                                                |\n");
			printf("|                      ��Ǹ��û�����ֲ�ѯ��ʽ                    |\n");
			printf("|________________________________________________________________|\n");
			printf("\n");
		}
		else
		{
			if (findway == 1)
			{
				int Number;
				//count1������¼��ǰ���еĽ�ʦ����
				int count1 = 0;
				//Ҫ����û�������ʦ�ŵ����
				printf("������Ҫ��ѯ�Ľ�ʦ��:");
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
						printf("\n���ã������������ʦ����Ϣ:\n");
						printf(" ____________________________________________________________________________________________________________________\n");
						printf("|            |            |            |            |            |            |            |            |            |\n");
						printf("|��ʦ��      |����        |�Ա�        |����        |ѧ��        |ְ��        |����        |סַ        |�绰        |\n");
						printf("|___________ |____________|____________|____________|____________|____________|____________|____________|____________|\n");
						printf("|            |            |            |            |            |            |            |            |            |\n");
						printf("|%-12ld|%-12s|%-12s|%-12d|%-12s|%-12s|%-12.2lf|%-12s|%-12s|\n",
							teacher[i].Number, teacher[i].Name, teacher[i].Gender, teacher[i].Age,
							teacher[i].Education, teacher[i].Occupation, teacher[i].Salary, teacher[i].Address,
							teacher[i].Telephone);
						printf("|___________ |____________|____________|____________|____________|____________|____________|____________|____________|\n");
						//���̴�ϣ���������ж�
						break;
					}
				}
				if (i == count1)
				{
					printf(" ________________________________________________________________\n");
					printf("|                                                                |\n");
					printf("|              ��Ǹ����ʦϵͳ��û�м�¼�������ʦ��              |\n");
					printf("|________________________________________________________________|\n");
					printf("\n");
				}
			}
			if (findway == 2)
			{
				char Ocu[50];
				//count2������¼��ǰ���еĽ�ʦ����
				int count2 = 0;
				//Ҫ����û�������ʦ�ŵ����
				printf("������Ҫ��ѯ��ְ��:");
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
						printf("\n���ã������������ʦ����Ϣ:\n");
						printf(" ____________________________________________________________________________________________________________________\n");
						printf("|            |            |            |            |            |            |            |            |            |\n");
						printf("|��ʦ��      |����        |�Ա�        |����        |ѧ��        |ְ��        |����        |סַ        |�绰        |\n");
						printf("|___________ |____________|____________|____________|____________|____________|____________|____________|____________|\n");
						printf("|            |            |            |            |            |            |            |            |            |\n");
						printf("|%-12ld|%-12s|%-12s|%-12d|%-12s|%-12s|%-12.2lf|%-12s|%-12s|\n",
							teacher[i].Number, teacher[i].Name, teacher[i].Gender, teacher[i].Age,
							teacher[i].Education, teacher[i].Occupation, teacher[i].Salary, teacher[i].Address,
							teacher[i].Telephone);
						printf("|___________ |____________|____________|____________|____________|____________|____________|____________|____________|\n");
						//���̴�ϣ���������ж�
						break;
					}
				}
				if (i == count2)
				{
					printf(" ________________________________________________________________\n");
					printf("|                                                                |\n");
					printf("|          ��Ǹ����ʦϵͳ��û�м�¼��ӵ�����ְ�Ƶ���ʦ          |\n");
					printf("|________________________________________________________________|\n");
					printf("\n");
				}
			}
		}
		fclose(fp);
		while (1)
		{
			printf("\n�������Ƿ���Ҫ������ѯ���ǵĻ�����1����Ļ�����0:");
			scanf("%s", pd);
			if (strcmp(pd, "0") == 0 || strcmp(pd, "1") == 0)
			{
				break;
			}
			else
			{
				printf("\nû������ѡ��������������\n");
			}

		}
		if (strcmp(pd, "0") == 0)
		{
			break;
		}
	}
	printf("\n�����ѡ������Ҫ�Ĺ���\n");
}
//��ʦ��Ϣ�޸�
void ChangeTea()
{
	printf(" ________________________________________________________________\n");
	printf("|                                                                |\n");
	printf("|                    ��ʦ��Ϣ�޸Ĺ���Ϊ������                  |\n");
	printf("|________________________________________________________________|\n");
	//pd�����жϿͻ��Ƿ���Ҫ�����޸�,is_No�����ж��Ƿ��������ʦ��
	int Number, i = 0, j = 0, count = 0, is_No = 1;
	char pd[10];
	//�������û����¶������Ϣ
	long int NewNumber;          //��ʦ��
	char NewName[20];			  //����
	char NewGender[5];			  //�Ա�
	int  NewAge;			      //����
	char NewEducation[20];		  //ѧ��
	char NewOccupation[50];	      //ְ��
	double NewSalary;			  //����
	char NewAddress[50];		  //��ַ
	char NewTelephone[17];        //�绰
	//change�����ж��޸�����
	int change = 0;
	printf("\n��������Ҫ�޸Ľ�ʦ�Ľ�ʦ��:");
	scanf("%d", &Number);
	while (1)
	{
		//���¶���Ϊ0
		change = 0;
		//���¶���Ϊ0
		is_No = 1;
		fp = fopen("TeacherInformation.txt", "rb");
		if (fp == NULL)
		{
			printf("�ļ���ʧ��\n");
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
			printf("�ļ���ʧ��\n");
			return;
		}
		for (i = 0; i < count; i++)
		{
			if (teacher[i].Number == Number)
			{
				printf(" ________________________________________________________________\n");
				printf("|                    |                      |                    |\n");
				printf("|                    |     ���޸ĵ�����     |                    |\n");
				printf("|____________________|______________________|____________________|\n");
				printf("|                    |                      |                    |\n");
				printf("|1.��ʦ��            |2.��ʦ����            |3.��ʦ����          |\n");
				printf("|____________________|______________________|____________________|\n");
				printf("|                    |                      |                    |\n");
				printf("|4.��ʦѧ��          |5.��ʦְ��            |6.��ʦ����          |\n");
				printf("|____________________|______________________|____________________|\n");
				printf("|                    |                      |                    |\n");
				printf("|7.��ʦסַ          |8.��ʦ�绰            |9.��ʦ�Ա�          |\n");
				printf("|____________________|______________________|____________________|\n");
				printf("\n��Ҫ�޸ĵ�������:");
				scanf("%d", &change);
				switch (change)
				{
				case 1:
					printf("�������µĽ�ʦ��:"); scanf("%ld", &NewNumber);teacher[i].Number = NewNumber; break;
				case 2:
					printf("�������µ�����:"); scanf("%s",NewName); strcpy(teacher[i].Name,NewName); break;
				case 3:
					printf("�������µ�����:"); scanf("%d", &NewAge); teacher[i].Age =NewAge; break;
				case 4:
					printf("�������µ�ѧ��:"); scanf("%s",NewEducation);strcpy(teacher[i].Education, NewEducation);  break;
				case 5:
					printf("�������µ�ְ��:"); scanf("%s",NewOccupation); strcpy(teacher[i].Occupation, NewOccupation);  break;
				case 6:
					printf("�������µĹ���:"); scanf("%lf",&NewSalary); teacher[i].Salary = NewSalary; break;
				case 7:
					printf("�������µ�סַ:"); scanf("%s", NewAddress); strcpy(teacher[i].Address, NewAddress);  break;
				case 8:
					printf("�������µĵ绰:"); scanf("%s", NewTelephone);strcpy(teacher[i].Telephone, NewTelephone); break;
				case 9:
					printf("�������µ��Ա�:"); scanf("%s", NewGender); strcpy(teacher[i].Gender, NewGender); break;
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
			printf("|                       ��Ǹ��û�������ʦ��                     |\n");
			printf("|________________________________________________________________|\n");
			printf("\n");
			fclose(fp);
		}
		else
		{
			//д���ļ�
			for (i = 0; i < count; i++)
			{
				fwrite(&teacher[i], sizeof(T), 1, fp);
			}
			//count���㣬�����´����¼���
			count = 0;
			fclose(fp);
			printf(" ________________________________________________________________\n");
			printf("|                                                                |\n");
			printf("|                     ��ϲ����ʦ��Ϣ�޸����!                    |\n");
			printf("|________________________________________________________________|\n");
			printf("\n");
		}
		while (1)
		{
			printf("\n�����Ƿ���Ҫ�����޸�,�ǵĻ�����1����Ļ�����0:");
			scanf("%s", pd);
			if (strcmp(pd, "0") == 0 || strcmp(pd, "1") == 0)
			{
				break;
			}
			else
			{
				printf("\nû������ѡ��������������\n");
			}
		}
		
		if (strcmp(pd, "0") == 0)
			break;
		printf("��������Ҫ�޸Ľ�ʦ�Ľ�ʦ��:");
		scanf("%d", &Number);
	}
	printf("\n�����ѡ������Ҫ�Ĺ���\n");
	return;
}
//��ʦ��Ϣ����
void SortTea()
{
	printf(" ________________________________________________________________\n");
	printf("|                                                                |\n");
	printf("|                    ��ʦ��Ϣ������Ϊ������                  |\n");
	printf("|________________________________________________________________|\n");
	//��ʱ��������������
	T TeaTemp;
	//count����fread����,choice����ѡ������ʽ
	int i = 0,count = 0, choice = 0, j = 0;
	while (1)
	{
		printf("\n�����Ǽ�������ʽ:\n");
		printf(" ________________________________________________________________\n");
		printf("|                                                                |\n");
		printf("|1.����ʦ������(��С����)                                        |\n");
		printf("|________________________________________________________________|\n");
		printf("|                                                                |\n");
		printf("|2.�����ʲ�ѯ(�Ӵ�С)                                          |\n");
		printf("|________________________________________________________________|\n");
		printf("\n��ѡ������ʽ: ");
		scanf("%d", &choice);
		fp = fopen("TeacherInformation.txt", "rb");
		if (fp == NULL)
		{
			printf("�ļ���ʧ��\n");
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
			printf("�ļ���ʧ��\n");
			return;
		}
		if (choice == 1)
		{
			//����ʦ������
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
			//д���ļ�
			for (i = 0; i < count; i++)
			{
				fwrite(&teacher[i], sizeof(T), 1, fp);
			}
			fclose(fp);
			break;
		}
		else if (choice == 2)
		{
			//����������
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
			//д���ļ�
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
			printf("|             ��Ǹ��û����������ʽ����������ѡ��               |\n");
			printf("|________________________________________________________________|\n");
			printf("\n");
		}
		fclose(fp);
	}
	printf("\n�������\n�����ѡ������Ҫ�Ĺ���\n");
	return;
}