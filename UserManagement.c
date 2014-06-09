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

	while (selected != '7')
	{
		fflush(stdin);
		selected = menu();
		fflush(stdin);

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
		case '4':
			searchmember(nextinfo);
			break;
		case '5':
			updatelist(nextinfo);
			break;
		case'6':
			deletemember(nextinfo);
			break;
		case'7':
			exitprogram(nextinfo);
			return 0;
		default:
			printf("1-7���� ���� �� �Է��ϼž� �մϴ�. �ٽ� �޴��� �����Ͻ÷��� �ƹ��ų� ��������.");

			getch();
			break;
		}
		returntomenu(nextinfo);
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
		if (nextinfo[i].id == -1)
			break;
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
		if (nextinfo[j].id == 0)
		{
			j++;
			continue;
		}
		printf("%d\t%s\t\t%s\t\t\t%s\n", nextinfo[j].id, nextinfo[j].name, nextinfo[j].address, nextinfo[j].phonenum);
		j++;
	}

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
	scanf("%19s",nextinfo[i].name);
	fflush(stdin);

	printf("ȸ�� �ּ�: ");
	scanf("%99s", nextinfo[i].address);
	fflush(stdin);
	int trueorfalse = 1;

	while (1)
	{
		printf("ȸ�� �޴�����ȣ: ");
		scanf("%19s", nextinfo[i].phonenum);
		fflush(stdin);
		
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
}
//3. ȸ�������ϱ�
void savelist(Info* nextinfo)
{
	FILE *fp;
	fp = fopen("data.txt", "wt");

	for (int i = 1; i < MAX; i++)
	{
		if (nextinfo[i].id == -1)
			break;

		if (nextinfo[i].id != 0)
			fprintf(fp, "%d\t%s\t\t%s\t\t\t%s\n", nextinfo[i].id, nextinfo[i].name, nextinfo[i].address, nextinfo[i].phonenum);
	}

	fclose(fp);

}
//4. ȸ�������ϱ�
void updatelist(Info* nextinfo)
{
	system("cls");
	int index;
	char select;

	printf("� ������ �˻��Ͻðڽ��ϱ�?\n");
	printf("1: ID�� �˻�\n");
	printf("2: �̸����� �˻�\n");
	printf("m: �޴��� ���ư���\n");


	scanf("%c", &select);
	fflush(stdin);

	while (select != 'm')
	{

		switch (select)
		{
		case'1':
			index = searchById(nextinfo);
			editmember(nextinfo, index);
			break;
		case'2':
			index = searchByName(nextinfo);
			editmember(nextinfo, index);
			break;
		case'm':
			menu();
			break;
		default:
			printf("1,2,m �� �ϳ��� �Է��ϼž� �մϴ�.");
			fflush(stdin);
			break;
		}
		scanf("%c", &select);
	}


}
//�����ϱ�
void editmember(Info* nextinfo, int index)
{
	char input;
	printf("� ������ �����Ͻðڽ��ϱ�?\n");

	printf("1: ID ����\n");
	printf("2: �̸� ����\n");
	printf("3: �ּ� ����\n");
	printf("4: �޴�����ȣ ����\n");
	printf("m: �޴��� ���ư���\n");
	scanf("%c", &input);
	fflush(stdin);

	switch (input)
	{
	case'1':
		printf("������ ID�� �Է��ϼ���: ");
		scanf("%d", &nextinfo[index].id);
		fflush(stdin);
		break;
	case'2':
		printf("������ �̸��� �Է��ϼ���: ");
		scanf("%19s", nextinfo[index].name);
		fflush(stdin);
		break;
	case'3':
		printf("������ �ּҸ� �Է��ϼ���: ");
		scanf("%99s", nextinfo[index].address);
		fflush(stdin);
		break;
	case'4':
		printf("������ �޴�����ȣ�� �Է��ϼ���: ");
		scanf("%19s", nextinfo[index].phonenum);
		fflush(stdin);
		break;
	case'm':
		menu();
		break;
	default:
		printf("1-4,m�߿��� �ϳ��� �Է��ϼž� �մϴ�.");
		editmember(nextinfo, index);
	}
}

//5. ȸ�������ϱ�
void deletemember(Info* nextinfo)
{
	system("cls");
	int index;
	char select;

	printf("� ������ �˻��Ͻðڽ��ϱ�?\n");
	printf("1: ID�� �˻�\n");
	printf("2: �̸����� �˻�\n");
	printf("m: �޴��� ���ư���\n");


	scanf("%c", &select);
	fflush(stdin);

	while (select != 'm')
	{

		switch (select)
		{
		case'1':
			index = searchById(nextinfo);
			printf("�����Ͻðڽ��ϱ�?y/n");
			scanf("%c", &select);
			fflush(stdin);
			if (select == 'y')
			{
				nextinfo[index].id = 0;
				printf("�����Ǿ����ϴ�!\n");
			}
			break;
		case'2':
			index = searchByName(nextinfo);
			printf("�����Ͻðڽ��ϱ�?y/n");
			scanf("%c", &select);
			fflush(stdin);
			if (select == 'y')
			{
				nextinfo[index].id = 0;
				printf("�����Ǿ����ϴ�!\n");
			}
			break;
		case'm':
			menu();
			break;
		default:
			printf("1,2,m �� �ϳ��� �Է��ϼž� �մϴ�.");
			fflush(stdin);
			break;
		}
		scanf("%c", &select);
	}

}

//6. ȸ���˻��ϱ�
void searchmember(Info* nextinfo)
{
	system("cls");
	char select;

	printf("� ������ �˻��Ͻðڽ��ϱ�?\n");
	printf("1: ID�� �˻�\n");
	printf("2: �̸����� �˻�\n");
	printf("m: �޴��� ���ư���\n");

	scanf("%c", &select);
	fflush(stdin);

	while (select != 'm')
	{

		switch (select)
		{
		case'1': 
			searchById(nextinfo);
			break;
		case'2':
			searchByName(nextinfo);
			break;
		case'm':
			menu();
			break;
		default:
			printf("1,2,m �� �ϳ��� �Է��ϼž� �մϴ�.");
			fflush(stdin);
			break;
		}
		scanf("%c", &select);
	}
}
// ID�� �˻�
int searchById(Info* nextinfo)
{
	int id = 0;
	int index = 0;

	printf("ã���� ID�� �Է��ϼ���: ");
	scanf("%d", &id);
	fflush(stdin);

	while (nextinfo[index].id != -1)
	{
		if (nextinfo[index].id != 0 && nextinfo[index].id == id)
		{
			printf("ȸ��ID:%d\n", nextinfo[index].id);
			printf("ȸ���̸�:%s\n", nextinfo[index].name);
			printf("ȸ���ּ�:%s\n", nextinfo[index].address);
			printf("ȸ���޴�����ȣ:%s\n", nextinfo[index].phonenum);
			break;
		}
		index++;
	}

	return index;
}
// �̸����� �˻�
int searchByName(Info* nextinfo)
{
	char name[16];
	int index = 0;

	printf("ã���� �̸��� �Է��ϼ���: ");
	gets(name);

	while (nextinfo[index].id != -1)
	{
		if (nextinfo[index].id != 0 && strcmp(nextinfo[index].name, name) == 0)
		{
			printf("ȸ��ID:%d\n", nextinfo[index].id);
			printf("ȸ���̸�:%s\n", nextinfo[index].name);
			printf("ȸ���ּ�:%s\n", nextinfo[index].address);
			printf("ȸ���޴�����ȣ:%s\n", nextinfo[index].phonenum);
			break;
		}
		index++;
	}

	if (nextinfo[index].id == -1)
	{
		printf("�˻� ����� �����ϴ�. �ٽ� �Է����ּ���.\n");
		return searchByName(nextinfo);
	}


	return index;
}
//7. �����ϱ� 
void exitprogram(Info* nextinfo)
{
	char input;
	printf("�����ϰ� �����Ͻðڽ��ϱ�? y/n : ");
	scanf("%c", &input);
	fflush(stdin);

	if (input == 'y')
	{
		savelist(nextinfo);
		printf("���������� ����Ǿ����ϴ�. �����Ͻ÷��� �ƹ�Ű�� ��������.\n");
		getch();
	}
	
}
	