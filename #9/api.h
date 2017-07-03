#include <stdio.h>
#include <stdlib.h>
#ifndef USEAPI
#include "list.h"
#else
struct list_head
{
	struct list_head *next, *prev;
};

struct hlist_head
{
	struct hlist_node *first;
};

struct hlist_node
{
	struct hlist_node *next, **pprev;
};
#endif

//增删查改 初始化 清除 遍历

struct node
{
	void *carrier;
	struct list_head list;
};

struct _list
{
	int length;
	struct node *head;
	struct list_head *p;
};

typedef struct _list listManager;

void initList(listManager *Man);
void addListNode(listManager *Man, void *content);
void popListNode(listManager *Man, void **content);
void firstListNode(listManager *Man, void *content);
void destroyList(listManager *Man);
void eachEntryNext(listManager *Man, void **p, int number);
void setNextStart(listManager *Man, int number);