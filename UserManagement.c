#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include "UserManagement.h"
#pragma warning(disable: 4996)

int menu()
{
	int select = 0;

	printf("������������������������������������������������������������������������������\n");
	printf("��                                                                          ��\n");
	printf("��                                                                          ��\n");
	printf("��                       /ȸ/��/��/��/��/��/��/��/                          ��\n");
	printf("��                                                                          ��\n");
	printf("��                                                              Ver0.1_Ellen��\n");
	printf("������������������������������������������������������������������������������\n");
	printf("������������������������������������������������������������������������������\n");
	printf("��\t\t\t\t\t\t\t\t\t    ��\n");
	printf("��\t\t\t   \t1. ȸ����ܺ���\t\t\t\t    ��\n");
	printf("��\t\t\t\t\t\t\t\t\t    ��\n");
	printf("��\t\t\t   \t2. ȸ������ϱ�\t\t\t\t    ��\n");
	printf("��\t\t\t\t\t\t\t\t\t    ��\n");
	printf("��\t\t\t   \t3. ȸ����������\t\t\t\t    ��\n");
	printf("��\t\t\t\t\t\t\t\t\t    ��\n");
	printf("��\t\t\t   \t4. ȸ���˻��ϱ�\t\t\t\t    ��\n");
	printf("��\t\t\t\t\t\t\t\t\t    ��\n");
	printf("��\t\t\t   \t5. ȸ�������ϱ�\t\t\t\t    ��\n");
	printf("��\t\t\t\t\t\t\t\t\t    ��\n");
	printf("��\t\t\t   \t6. ȸ�������ϱ�\t\t\t\t    ��\n");
	printf("��\t\t\t\t\t\t\t\t\t    ��\n");
	printf("��\t\t\t   \t7. ���α׷�����\t\t\t\t    ��\n");
	printf("��\t\t\t\t\t\t\t\t\t    ��\n");
	printf("������������������������������������������������������������������������������\n");
	printf("\t\t\t>>���Ͻô� ����� ��ȣ�� �Է��ϼ���! ");
	scanf("%c", &select);

	return select;
}

void readfile()
{

	Info nextinfo[MAX_SIZE] = { 0, };
	FILE* readfile;
	char buff[100];
	int i = 0, j = 0;

	readfile = fopen("data.txt", "rt");
	if (readfile == NULL)					//file�� ������ error
	{
		puts("ERROR\n");
		return -1;
	}

	fgets(buff, 100, readfile);
	printf("%s", buff);


	while (!feof(readfile))
	{
		fscanf(readfile, "%d\t%[^\t]\t%[^\t]\t%[^\n]", &nextinfo[i].id, nextinfo[i].name, nextinfo[i].address, nextinfo[i].phonenum);
		i++;
	}

	fclose(readfile);

}

void returntomenu(void)
{
	char userinput;

	fflush(stdin);

	printf("�޴��� ���ư��÷��� 0�� �Է��ϼ���: ");
	scanf("%c", &userinput);

	if (userinput == '0')
		menu();
	else
	{
		printf("�߸� �Է��ϼ̽��ϴ�.\n");
		returntomenu();
	}
}

void printlist()
{
	system("cls");
	Info nextinfo[MAX_SIZE] = { 0, };
	FILE* readfile;
	char buff[100];
	int i = 0, j = 0;

	readfile = fopen("data.txt", "rt");
	if (readfile == NULL)					//file�� ������ error
	{
		puts("ERROR\n");
		return -1;
	}

	fgets(buff, 100, readfile);
	printf("%s", buff);


	while (!feof(readfile))
	{
		fscanf(readfile, "%d\t%[^\t]\t%[^\t]\t%[^\n]", &nextinfo[i].id, nextinfo[i].name, nextinfo[i].address, nextinfo[i].phonenum);
		i++;
	}
	while (nextinfo[j].id)
	{
		printf("%d   \t%s  %s\t%s\n", nextinfo[j].id, nextinfo[j].name, nextinfo[j].address, nextinfo[j].phonenum);
		j++;
	}

	fclose(readfile);
	returntomenu();
}

void savelist(void);


int main(void)
{
	readfile();
	int selected = 0;

	while (selected != 7)
	{
		selected = menu();
		switch (selected)
		{
		case '1':
			printlist();
			break;
		//case '2':
			//addmember();
		//case '3':
			//savelist();
		}
	}
	
}


