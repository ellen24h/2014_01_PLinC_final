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

int searchById(Info* nextinfo);
int searchByName(Info* nextinfo);

void printlist(Info* nextinfo);
void addmember(Info* nextinfo);
void savelist(Info* nextinfo);
void editmember(Info* nextinfo, int index);
void searchmember(Info* nextinfo);
void updatelist(Info* nextinfo);
void deletemember(Info* nextinfo);
void exitprogram(Info* nextinfo);




#endif

