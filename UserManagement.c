#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include "UserManagement.h"
#pragma warning(disable: 4996)

int menu()
{
	int select = 0;

	printf("┏━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━┓\n");
	printf("┃                                                                          ┃\n");
	printf("┃                                                                          ┃\n");
	printf("┃                       /회/원/관/리/프/로/그/램/                          ┃\n");
	printf("┃                                                                          ┃\n");
	printf("┃                                                              Ver0.1_Ellen┃\n");
	printf("┗━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━┛\n");
	printf("┏━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━┓\n");
	printf("┃\t\t\t\t\t\t\t\t\t    ┃\n");
	printf("┃\t\t\t   \t1. 회원명단보기\t\t\t\t    ┃\n");
	printf("┃\t\t\t\t\t\t\t\t\t    ┃\n");
	printf("┃\t\t\t   \t2. 회원등록하기\t\t\t\t    ┃\n");
	printf("┃\t\t\t\t\t\t\t\t\t    ┃\n");
	printf("┃\t\t\t   \t3. 회원정보저장\t\t\t\t    ┃\n");
	printf("┃\t\t\t\t\t\t\t\t\t    ┃\n");
	printf("┃\t\t\t   \t4. 회원검색하기\t\t\t\t    ┃\n");
	printf("┃\t\t\t\t\t\t\t\t\t    ┃\n");
	printf("┃\t\t\t   \t5. 회원수정하기\t\t\t\t    ┃\n");
	printf("┃\t\t\t\t\t\t\t\t\t    ┃\n");
	printf("┃\t\t\t   \t6. 회원삭제하기\t\t\t\t    ┃\n");
	printf("┃\t\t\t\t\t\t\t\t\t    ┃\n");
	printf("┃\t\t\t   \t7. 프로그램종료\t\t\t\t    ┃\n");
	printf("┃\t\t\t\t\t\t\t\t\t    ┃\n");
	printf("┗━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━┛\n");
	printf("\t\t\t>>원하시는 기능의 번호를 입력하세요! ");
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
	if (readfile == NULL)					//file이 없을때 error
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

	printf("메뉴로 돌아가시려면 0을 입력하세요: ");
	scanf("%c", &userinput);

	if (userinput == '0')
		menu();
	else
	{
		printf("잘못 입력하셨습니다.\n");
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
	if (readfile == NULL)					//file이 없을때 error
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


