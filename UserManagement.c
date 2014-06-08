#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <Windows.h>
#include "UserManagement.h"
#pragma warning(disable: 4996)

int MAX = 255;
int nextid;

//�����Լ�
int main(void)
{

	Info* nextinfo;
	int j = 0;

	nextinfo = (Info*)malloc(sizeof(Info)*MAX);
	for (j = 0; j < MAX; j++)
	{
		nextinfo[j].id = -1;
	}

	readfile(nextinfo);

	int selected = 0;

	while (selected != 7)
	{
		fflush(stdin);
		selected = menu();

		switch (selected)
		{
		case '1':
			printlist(nextinfo);
			break;
		case '2':
			addmember(nextinfo);
			break;
		case '3':
			savelist(nextinfo);
			break;
		default:
			printf("1-7���� ���� �� �Է��ϼž� �մϴ�. �ٽ� �޴��� �����Ͻ÷��� �ƹ��ų� ��������.");
			fflush(stdin);
			_getch();
			break;
		}
	}

}

//�޴�ȭ��
int menu()
{
	char select;
	system("cls");

	printf("������������������������������������������������������������������������������\n");
	printf("��                                                                          ��\n");
	printf("��                                                                          ��\n");
	printf("��                       /ȸ/��/��/��/��/��/��/��/                          ��\n");
	printf("��                                                                          ��\n");
	printf("��                                                              Ver0.1_Ellen��\n");
	printf("������������������������������������������������������������������������������\n");
	printf("������������������������������������������������������������������������������\n");
	printf("��                                                                          ��\n");
	printf("��                               1. ȸ����ܺ���                            ��\n");
	printf("��                                                                          ��\n");
	printf("��                               2. ȸ������ϱ�                            ��\n");
	printf("��                                                                          ��\n");
	printf("��                               3. ȸ����������                            ��\n");
	printf("��                                                                          ��\n");
	printf("��                               4. ȸ���˻��ϱ�                            ��\n");
	printf("��                                                                          ��\n");
	printf("��                               5. ȸ�������ϱ�                            ��\n");
	printf("��                                                                          ��\n");
	printf("��                               6. ȸ�������ϱ�                            ��\n");
	printf("��                                                                          ��\n");
	printf("��                               7. ���α׷�����                            ��\n");
	printf("��                                                                          ��\n");
	printf("������������������������������������������������������������������������������\n");
	printf("                >>���Ͻô� ����� ��ȣ�� �Է��ϼ���: ");
	//fflush(stdin);
	scanf("%c", &select);
	printf("\n");

	return select;
}
 //datafile�о����
void readfile(Info* nextinfo)
{

	char buff[100];
	FILE *fp;
	fp = fopen("data.txt", "rt");

	fgets(buff, 100, fp);

	if (fp == NULL)					//file�� ������ error
	{
		puts("ERROR\n");
		return -1;
	}

	int i = 0;

	while (!feof(fp))
	{
		fscanf(fp, "%d\t%[^\t]\t%[^\t]\t%[^\n]", &nextinfo[i].id, nextinfo[i].name, nextinfo[i].address, nextinfo[i].phonenum);
		nextid = nextinfo[i].id + 1;
		i++;
	}

	printf("%d", nextid);
	
	fclose(fp);

}
//menu�� ���ư���
void returntomenu(void)
{
	char userinput;

	fflush(stdin);
	printf("�޴��� ���ư��÷��� 0�� �Է��ϼ���: ");
	scanf("%c", &userinput);

	printf("\n");

	if (userinput == '0')
		menu();
	else
	{
		printf("�߸� �Է��ϼ̽��ϴ�.");
		returntomenu();
	}
}
//1. ȸ����������
void printlist(Info* nextinfo)
{
	system("cls");

	int j = 0;
	printf("ȸ�����̵�\tȸ���̸�\tȸ���ּ�\t\tȸ���޴�����ȣ\n");

	while (nextinfo[j].id != -1)
	{
		printf("%d\t%s\t\t%s\t\t\t%s\n", nextinfo[j].id, nextinfo[j].name, nextinfo[j].address, nextinfo[j].phonenum);
		j++;
	}

	returntomenu();
}
//2. ȸ���߰��ϱ�
void addmember(Info* nextinfo)
{
	int i = 0, j = 0, k = 0;
	for (i = 0; i < MAX; i++)
	{	
		if (nextinfo[i].id == -1) break;
	}
	
	if (nextinfo[MAX - 1].id != -1)
	{
		MAX = MAX * 2;
		nextinfo = (Info*)realloc(nextinfo, sizeof(Info)*MAX);
	}

	for (j = MAX/2; j < MAX; j++)
	{
		nextinfo[j].id = -1;
	}
	
	system("cls");

	printf("ȸ�� ID:%d\n",nextid);
	nextinfo[i].id = nextid;
	nextid++;

	printf("ȸ�� �̸�: ");
	fflush(stdin);
	gets(nextinfo[i].name);

	printf("ȸ�� �ּ�: ");
	gets(nextinfo[i].address);
	int trueorfalse = 1;

	while (1)
	{
		printf("ȸ�� �޴�����ȣ: ");
		gets(nextinfo[i].phonenum);
		
		for (k = 0; k < strlen(nextinfo[i].phonenum); k++){
			if ((nextinfo[i].phonenum[k] >= '0' && nextinfo[i].phonenum[k] <= '9') || nextinfo[i].phonenum[k] == '-'){
				trueorfalse = 1;
				continue;
			}
			else{
				printf("���ڿ� '-'�� �Է� �����մϴ�.");
				trueorfalse = 0;
				break;
			}
		}
		if (trueorfalse == 0)
			continue;
		else
			break;
	}

	returntomenu();
}
//3. ȸ�������ϱ�
void savelist(Info* nextinfo)
{
	FILE *fp;
	fp = fopen("data.txt", "wt");

	for (int i = 1; i < MAX; i++)
	{
		if (nextinfo[i].id != -1)
			fprintf(fp, "%d\t%s\t\t%s\t\t\t%s\n", nextinfo[i].id, nextinfo[i].name, nextinfo[i].address, nextinfo[i].phonenum);
		else
			break;
	}

	fclose(fp);

	returntomenu();
}
//4. ȸ�������ϱ�
void updatelist(Info* nextinfo)
{
	printf
}
//5. ȸ�������ϱ�
void deletemember(Info* nextinfo)
{

}
//6. ȸ���˻��ϱ�
void searchmember(Info* nextinfo)
{

}
// ID�� �˻�
void searchById(Info* nextinfo)
{
	int temp = 0;
	int i = 0;

	printf("ã���� ID�� �Է��ϼ���: ");
	gets(temp);

	while (nextinfo[i].id != -1)
	{
		if (nextinfo->id == temp)
		{
			printf("ȸ��ID:%d", nextinfo[i].id);
			printf("ȸ���̸�:%s", nextinfo[i].name);
			printf("ȸ���ּ�:%s", nextinfo[i].address);
			pirntf("ȸ���޴�����ȣ:%s", nextinfo[i].phonenum);
		}
		else
			i++;
	}
}
// �̸����� �˻�
void searchByName(Info* nextinfo)
{
	int temp = 0;
	int i = 0;

	printf("ã���� �̸��� �Է��ϼ���: ");
	gets(temp);

	while (nextinfo[i].name != -1)
	{
		if (nextinfo->id == temp)
		{
			printf("ȸ��ID:%d", nextinfo[i].id);
			printf("ȸ���̸�:%s", nextinfo[i].name);
			printf("ȸ���ּ�:%s", nextinfo[i].address);
			pirntf("ȸ���޴�����ȣ:%s", nextinfo[i].phonenum);
		}
		else
			i++;
	}

}
//7. �����ϱ� 
