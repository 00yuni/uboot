#include "sqlist.h"

int sqlist_insert(head* ptr, const void* data, int mode);

void sqlist_display(head* ptr, backfunc* ps);

int sqlist_delete(head* ptr, const void* data1, cmpfunc* ps);

int sqlist_fetch(head* ptr, const void* data1, cmpfunc* ps, void* data2);

void* sqlist_find(head* ptr, const void* data1, cmpfunc* ps);


head* sqlist_create(int datasize)
{
	head* me;
	me = (head*)malloc(sizeof(*me));
	if (me == NULL)
		return NULL;

	me->size = datasize;
	me->node.prev = &me->node;
	me->node.next = &me->node;
	me->insert = sqlist_insert;
	me->display = sqlist_display;
	me->delet = sqlist_delete;
	me->fetch = sqlist_fetch;
	me->find = sqlist_find;

	return me;
}

int sqlist_insert(head* ptr,const void* data,int mode)
{
	struct node_st* newnode;
	newnode = (node_st*)malloc(sizeof(*newnode) + ptr->size);
	if (newnode == NULL)
		return -1;
	memcpy(newnode->data, data, ptr->size);

	if (mode == STARTHEAD)
	{
		newnode->prev = &ptr->node;
		newnode->next = ptr->node.next;
	}
	else if (mode == ENDHEAD)
		 {
			newnode->next = &ptr->node;
			newnode->prev = ptr->node.prev;
		 }
	     else
		 return -3;
	newnode->prev->next = newnode;
	newnode->next->prev = newnode;
	return 0;
}

void sqlist_display(head* ptr,backfunc* ps)
{
	struct node_st* cur = NULL;
	for (cur = ptr->node.next; cur != &ptr->node; cur = cur->next)
		ps(cur->data);
}

struct node_st* finddata(head* ptr, const void* data1, cmpfunc* ps)
{
	node_st* cur = NULL;
	for (cur = ptr->node.next; cur != &ptr->node; cur = cur->next)
	{
		if (ps(data1, cur->data) == 0)
			break;//Ìø³öÑ­»·
	}
	return cur;
}

int sqlist_delete(head* ptr, const void* data1, cmpfunc* ps)
{
	struct node_st* node1;
	node1 = finddata(ptr, data1, ps);
	if (node1 == &ptr->node)
		return -1;
	node1->prev->next = node1->next;
	node1->next->prev = node1->prev;
	free(node1);
	return 0;
}


int sqlist_fetch(head* ptr, const void* data1, cmpfunc* ps, void* data2)
{
	struct node_st* node1;
	node1 = finddata(ptr, data1, ps);
	if (node1 == &ptr->node)
		return -1;
	node1->prev->next = node1->next;
	node1->next->prev = node1->prev;
	if (data2 != NULL)
		memcpy(data2, node1->data, ptr->size);
	free(node1);
	return 0;
}


void* sqlist_find(head* ptr,const void* data1,cmpfunc* ps)
{
	node_st* me;
	me = finddata(ptr, data1, ps);
	if (me == &ptr->node)
		return NULL;
	return me->data;
}


void sqlist_destroy(head* ptr)
{
	struct node_st* cur = NULL;
	struct node_st* next = NULL;
	for (cur = ptr->node.next; cur != &ptr->node; cur = next)
	{
		next = cur->next;
		free(cur);
	}
	free(ptr);
	return;
}
<<<<<<< Updated upstream
/*
1\2\33\44
*/
=======
>>>>>>> Stashed changes
