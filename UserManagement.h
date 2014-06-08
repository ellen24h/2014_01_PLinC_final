#ifndef  __1STVER_H__
#define __1STVER_H__

typedef struct info{

	int id;
	char name[20];
	char address[100];
	char phonenum[20];

}Info;

void readfile(Info* nextinfo);
int menu();
void returntomenu(void);

void printlist(Info* nextinfo);
void addmember(Info* nextinfo);
void savelist(Info* nextinfo);
void updatelist(Info* nextinfo);
void deletemember(Info* nextinfo);


#endif

