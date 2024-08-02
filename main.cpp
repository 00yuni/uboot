#include <stdio.h>
#include <stdlib.h>
#include <time.h>


#include "sqlist.h"
#define NAMESIZE 16
#define NUM 8

struct student
{
	int id;
	char name[16];
	int math;
	int chinese;
};

void print_s(const void* p)
{
	  const student* pp = (const student*)p;

	printf("%d %s %d %d\t\n", pp->id, pp->name, pp->math, pp->chinese);
}

int id_cmp(const void* p, const void* q)
{
	const int* pp = (const int*)p;
	const student* qq = (const student*)q;
	return (*pp - qq->id);
}

int name_cmp(const void* p, const void* q)
{
	const char* pp = (const char*)p;
	const student* qq = (const student*)q;
	return  strcmp(pp, qq->name);
}

int main()
{
	int i,ret;
	int id = 4;
	char name[] = "student2";
	void* data3 = NULL;
	student temp = {};
	head* list;
	srand((unsigned int)time(NULL));

	list = sqlist_create(sizeof(student));
	
	if (list == NULL)
		return -1;

	for (i = 0; i < NUM; i++)
	{
		temp.id = i;
		snprintf(temp.name, NAMESIZE, "student%d", i);
		temp.math = rand() % 40 + 60;
		temp.chinese = rand() % 40 + 60 ;

		ret = list->insert(list, &temp,ENDHEAD);
		if (ret)
			return -2;

	}
	
	list->display(list,print_s);

	list->delet(list, &id, id_cmp);
	list->delet(list, name, name_cmp);

	data3 = list->find(list, &id, id_cmp);
	if (data3 == NULL)
		printf("没有找到\n");
	else
	{
		printf("找到了\n");
		print_s(data3);
	}
	list->display(list, print_s);
		
	sqlist_destroy(list);

	return 0;
}
/*
1\2\33\44
*/