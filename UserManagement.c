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
			printf("1-7까지 숫자 중 입력하셔야 합니다. 다시 메뉴를 선택하시려면 아무거나 누르세요.");

			getch();
			break;
		}
		returntomenu(nextinfo);
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
		if (nextinfo[i].id == -1)
			break;
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
		if (nextinfo[j].id == 0)
		{
			j++;
			continue;
		}
		printf("%d\t%s\t\t%s\t\t\t%s\n", nextinfo[j].id, nextinfo[j].name, nextinfo[j].address, nextinfo[j].phonenum);
		j++;
	}

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
	scanf("%19s",nextinfo[i].name);
	fflush(stdin);

	printf("회원 주소: ");
	scanf("%99s", nextinfo[i].address);
	fflush(stdin);
	int trueorfalse = 1;

	while (1)
	{
		printf("회원 휴대폰번호: ");
		scanf("%19s", nextinfo[i].phonenum);
		fflush(stdin);
		
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
}
//3. 회원저장하기
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
//4. 회원수정하기
void updatelist(Info* nextinfo)
{
	system("cls");
	int index;
	char select;

	printf("어떤 정보로 검색하시겠습니까?\n");
	printf("1: ID로 검색\n");
	printf("2: 이름으로 검색\n");
	printf("m: 메뉴로 돌아가기\n");


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
			printf("1,2,m 중 하나를 입력하셔야 합니다.");
			fflush(stdin);
			break;
		}
		scanf("%c", &select);
	}


}
//수정하기
void editmember(Info* nextinfo, int index)
{
	char input;
	printf("어떤 정보를 수정하시겠습니까?\n");

	printf("1: ID 수정\n");
	printf("2: 이름 수정\n");
	printf("3: 주소 수정\n");
	printf("4: 휴대폰번호 수정\n");
	printf("m: 메뉴로 돌아가기\n");
	scanf("%c", &input);
	fflush(stdin);

	switch (input)
	{
	case'1':
		printf("수정할 ID를 입력하세요: ");
		scanf("%d", &nextinfo[index].id);
		fflush(stdin);
		break;
	case'2':
		printf("수정할 이름을 입력하세요: ");
		scanf("%19s", nextinfo[index].name);
		fflush(stdin);
		break;
	case'3':
		printf("수정할 주소를 입력하세요: ");
		scanf("%99s", nextinfo[index].address);
		fflush(stdin);
		break;
	case'4':
		printf("수정할 휴대폰번호를 입력하세요: ");
		scanf("%19s", nextinfo[index].phonenum);
		fflush(stdin);
		break;
	case'm':
		menu();
		break;
	default:
		printf("1-4,m중에서 하나를 입력하셔야 합니다.");
		editmember(nextinfo, index);
	}
}

//5. 회원삭제하기
void deletemember(Info* nextinfo)
{
	system("cls");
	int index;
	char select;

	printf("어떤 정보로 검색하시겠습니까?\n");
	printf("1: ID로 검색\n");
	printf("2: 이름으로 검색\n");
	printf("m: 메뉴로 돌아가기\n");


	scanf("%c", &select);
	fflush(stdin);

	while (select != 'm')
	{

		switch (select)
		{
		case'1':
			index = searchById(nextinfo);
			printf("삭제하시겠습니까?y/n");
			scanf("%c", &select);
			fflush(stdin);
			if (select == 'y')
			{
				nextinfo[index].id = 0;
				printf("삭제되었습니다!\n");
			}
			break;
		case'2':
			index = searchByName(nextinfo);
			printf("삭제하시겠습니까?y/n");
			scanf("%c", &select);
			fflush(stdin);
			if (select == 'y')
			{
				nextinfo[index].id = 0;
				printf("삭제되었습니다!\n");
			}
			break;
		case'm':
			menu();
			break;
		default:
			printf("1,2,m 중 하나를 입력하셔야 합니다.");
			fflush(stdin);
			break;
		}
		scanf("%c", &select);
	}

}

//6. 회원검색하기
void searchmember(Info* nextinfo)
{
	system("cls");
	char select;

	printf("어떤 정보로 검색하시겠습니까?\n");
	printf("1: ID로 검색\n");
	printf("2: 이름으로 검색\n");
	printf("m: 메뉴로 돌아가기\n");

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
			printf("1,2,m 중 하나를 입력하셔야 합니다.");
			fflush(stdin);
			break;
		}
		scanf("%c", &select);
	}
}
// ID로 검색
int searchById(Info* nextinfo)
{
	int id = 0;
	int index = 0;

	printf("찾으실 ID를 입력하세요: ");
	scanf("%d", &id);
	fflush(stdin);

	while (nextinfo[index].id != -1)
	{
		if (nextinfo[index].id != 0 && nextinfo[index].id == id)
		{
			printf("회원ID:%d\n", nextinfo[index].id);
			printf("회원이름:%s\n", nextinfo[index].name);
			printf("회원주소:%s\n", nextinfo[index].address);
			printf("회원휴대폰번호:%s\n", nextinfo[index].phonenum);
			break;
		}
		index++;
	}

	return index;
}
// 이름으로 검색
int searchByName(Info* nextinfo)
{
	char name[16];
	int index = 0;

	printf("찾으실 이름를 입력하세요: ");
	gets(name);

	while (nextinfo[index].id != -1)
	{
		if (nextinfo[index].id != 0 && strcmp(nextinfo[index].name, name) == 0)
		{
			printf("회원ID:%d\n", nextinfo[index].id);
			printf("회원이름:%s\n", nextinfo[index].name);
			printf("회원주소:%s\n", nextinfo[index].address);
			printf("회원휴대폰번호:%s\n", nextinfo[index].phonenum);
			break;
		}
		index++;
	}

	if (nextinfo[index].id == -1)
	{
		printf("검색 결과가 없습니다. 다시 입력해주세요.\n");
		return searchByName(nextinfo);
	}


	return index;
}
//7. 종료하기 
void exitprogram(Info* nextinfo)
{
	char input;
	printf("저장하고 종료하시겠습니까? y/n : ");
	scanf("%c", &input);
	fflush(stdin);

	if (input == 'y')
	{
		savelist(nextinfo);
		printf("성공적으로 저장되었습니다. 종료하시려면 아무키나 누르세요.\n");
		getch();
	}
	
}
	