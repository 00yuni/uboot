#pragma once
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define STARTHEAD 1
#define ENDHEAD 2

typedef void backfunc(const void* ps);
typedef int cmpfunc(const void* p, const void* q);

struct node_st
{
	struct node_st* prev;
	struct node_st* next;
	char data[1];
};

typedef struct head_st
{
	int size;
	struct node_st node;
	int (*insert)(head_st*, const void*, int);
	void (*display)(head_st* , backfunc*);
	int (*delet)(head_st*, const void*, cmpfunc*);
	int (*fetch)(head_st*, const void*, cmpfunc*, void*);
	void* (*find)(head_st*, const void*, cmpfunc*);


}head;

head* sqlist_create(int size);

void sqlist_destroy(head* ptr);
