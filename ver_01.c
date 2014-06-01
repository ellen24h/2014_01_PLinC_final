#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include "ver_01.h"
#pragma warning(disable: 4996)

int menu()
{
	int select = 0;

	printf("������������������������������������������������������������������������������\n");
	printf("��\t\t\t\t\t\t\t\t\t    ��\n");
	printf("��\t\t\t\t\t\t\t\t\t    ��\n");
	printf("��\t\t\t   ȸ/��/��/��/��/��/��/��/\t\t\t    ��\n");
	printf("��\t\t\t\t\t\t\t\t\t    ��\n");
	printf("��\t\t\t\t\t\t\t\tVer0.1_Ellen��\n");
	printf("������������������������������������������������������������������������������\n");
	printf("������������������������������������������������������������������������������\n");
	printf("��\t\t\t\t\t\t\t\t\t    ��\n");
	printf("��\t\t\t   \t1. ȸ�����ܺ���\t\t\t\t    ��\n");
	printf("��\t\t\t\t\t\t\t\t\t    ��\n");
	printf("��\t\t\t   \t2. ȸ�������ϱ�\t\t\t\t    ��\n");
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
	printf("\t\t\t>>���Ͻô� ������ ��ȣ�� �Է��ϼ���! ");
	scanf("%d", &select);

	return select;
}

void printlist()
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
	while (nextinfo[j].id)
	{
		printf("%d   \t%s  %s\t%s\n", nextinfo[j].id, nextinfo[j].name, nextinfo[j].address, nextinfo[j].phonenum);
		j++;
	}
	fclose(readfile);

}

int main(void)
{
	int selected = menu();
	switch (selected)
	{
	case 1:
		printlist();
	}

	fflush(stdin);
	getchar();

}

 
