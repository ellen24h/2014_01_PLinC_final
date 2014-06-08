#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <Windows.h>
#include "UserManagement.h"
#pragma warning(disable: 4996)

int MAX = 255;
int nextid;

//메인함수
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
			printf("1-7까지 숫자 중 입력하셔야 합니다. 다시 메뉴를 선택하시려면 아무거나 누르세요.");
			fflush(stdin);
			_getch();
			break;
		}
	}

}

//메뉴화면
int menu()
{
	char select;
	system("cls");

	printf("┏━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━┓\n");
	printf("┃                                                                          ┃\n");
	printf("┃                                                                          ┃\n");
	printf("┃                       /회/원/관/리/프/로/그/램/                          ┃\n");
	printf("┃                                                                          ┃\n");
	printf("┃                                                              Ver0.1_Ellen┃\n");
	printf("┗━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━┛\n");
	printf("┏━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━┓\n");
	printf("┃                                                                          ┃\n");
	printf("┃                               1. 회원명단보기                            ┃\n");
	printf("┃                                                                          ┃\n");
	printf("┃                               2. 회원등록하기                            ┃\n");
	printf("┃                                                                          ┃\n");
	printf("┃                               3. 회원정보저장                            ┃\n");
	printf("┃                                                                          ┃\n");
	printf("┃                               4. 회원검색하기                            ┃\n");
	printf("┃                                                                          ┃\n");
	printf("┃                               5. 회원수정하기                            ┃\n");
	printf("┃                                                                          ┃\n");
	printf("┃                               6. 회원삭제하기                            ┃\n");
	printf("┃                                                                          ┃\n");
	printf("┃                               7. 프로그램종료                            ┃\n");
	printf("┃                                                                          ┃\n");
	printf("┗━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━┛\n");
	printf("                >>원하시는 기능의 번호를 입력하세요: ");
	//fflush(stdin);
	scanf("%c", &select);
	printf("\n");

	return select;
}
 //datafile읽어오기
void readfile(Info* nextinfo)
{

	char buff[100];
	FILE *fp;
	fp = fopen("data.txt", "rt");

	fgets(buff, 100, fp);

	if (fp == NULL)					//file이 없을때 error
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
//menu로 돌아가기
void returntomenu(void)
{
	char userinput;

	fflush(stdin);
	printf("메뉴로 돌아가시려면 0을 입력하세요: ");
	scanf("%c", &userinput);

	printf("\n");

	if (userinput == '0')
		menu();
	else
	{
		printf("잘못 입력하셨습니다.");
		returntomenu();
	}
}
//1. 회원정보보기
void printlist(Info* nextinfo)
{
	system("cls");

	int j = 0;
	printf("회원아이디\t회원이름\t회원주소\t\t회원휴대폰번호\n");

	while (nextinfo[j].id != -1)
	{
		printf("%d\t%s\t\t%s\t\t\t%s\n", nextinfo[j].id, nextinfo[j].name, nextinfo[j].address, nextinfo[j].phonenum);
		j++;
	}

	returntomenu();
}
//2. 회원추가하기
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

	printf("회원 ID:%d\n",nextid);
	nextinfo[i].id = nextid;
	nextid++;

	printf("회원 이름: ");
	fflush(stdin);
	gets(nextinfo[i].name);

	printf("회원 주소: ");
	gets(nextinfo[i].address);
	int trueorfalse = 1;

	while (1)
	{
		printf("회원 휴대폰번호: ");
		gets(nextinfo[i].phonenum);
		
		for (k = 0; k < strlen(nextinfo[i].phonenum); k++){
			if ((nextinfo[i].phonenum[k] >= '0' && nextinfo[i].phonenum[k] <= '9') || nextinfo[i].phonenum[k] == '-'){
				trueorfalse = 1;
				continue;
			}
			else{
				printf("숫자와 '-'만 입력 가능합니다.");
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
//3. 회원저장하기
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
//4. 회원수정하기
void updatelist(Info* nextinfo)
{
	printf
}
//5. 회원삭제하기
void deletemember(Info* nextinfo)
{

}
//6. 회원검색하기
void searchmember(Info* nextinfo)
{

}
// ID로 검색
void searchById(Info* nextinfo)
{
	int temp = 0;
	int i = 0;

	printf("찾으실 ID를 입력하세요: ");
	gets(temp);

	while (nextinfo[i].id != -1)
	{
		if (nextinfo->id == temp)
		{
			printf("회원ID:%d", nextinfo[i].id);
			printf("회원이름:%s", nextinfo[i].name);
			printf("회원주소:%s", nextinfo[i].address);
			pirntf("회원휴대폰번호:%s", nextinfo[i].phonenum);
		}
		else
			i++;
	}
}
// 이름으로 검색
void searchByName(Info* nextinfo)
{
	int temp = 0;
	int i = 0;

	printf("찾으실 이름를 입력하세요: ");
	gets(temp);

	while (nextinfo[i].name != -1)
	{
		if (nextinfo->id == temp)
		{
			printf("회원ID:%d", nextinfo[i].id);
			printf("회원이름:%s", nextinfo[i].name);
			printf("회원주소:%s", nextinfo[i].address);
			pirntf("회원휴대폰번호:%s", nextinfo[i].phonenum);
		}
		else
			i++;
	}

}
//7. 종료하기 
