#pragma once
#include<stdio.h>
#include<stdlib.h>
#include<assert.h>
#define LTDataType int
typedef struct ListNode
{
	LTDataType data;
	struct ListNode* next;
	struct ListNode* prev;
}LTNode;

LTNode* LTBuyNode(LTDataType x)
{
	LTNode* p = (LTNode*)malloc(sizeof(LTNode));
	if (!p)
	{
		perror("malloc");
		exit(1);
	}
	p->data = x;
	p->next = p->prev = p;
	return p;
}

void LTPrint(LTNode* phead)
{
	assert(phead);
	LTNode* pcur = phead->next;
	while (pcur != phead)
	{
		printf("%d->", pcur->data);
		pcur = pcur->next;
	}
	printf("\n");
}

//void LTInit(LTNode** phead)
//{
//	assert(phead && *phead);
//
//}

void LTPushBack(LTNode* phead, LTDataType x)
{
	assert(phead);
	LTNode* newnode = LTBuyNode(x);
	newnode->data = x;
	newnode->prev = phead->prev;
	newnode->next = phead;
	phead->prev->next = newnode;
	phead->prev = newnode;
}

void LTPushFront(LTNode* phead, LTDataType x)
{
	assert(phead);
	LTNode* pcur = LTBuyNode(x);
	pcur->next = phead->next;
	phead->next->prev = pcur;
	phead->next = pcur;
	pcur->prev = phead;
}

void LTPopBack(LTNode* phead)
{
	assert(phead && phead != phead->next);
	LTNode* pcur = phead->prev;
	pcur->prev->next = phead;
	phead->prev = pcur->prev;
	free(pcur);
}

void LTPopFront(LTNode* phead)
{
	assert(phead && phead != phead->next);
	LTNode* pcur = phead->next;
	pcur->prev = phead;
	phead->next = pcur->next;
	free(pcur);
}

LTNode* LTFind(LTNode* phead, LTDataType x)
{
	assert(phead);
	LTNode* pcur = phead->next;
	while (pcur != phead)
	{
		if (pcur->data == x)
		{
			return pcur;
		}
		pcur = pcur->next;
	}
	return NULL;
}

void LTInsert(LTNode* pos, LTDataType x)
{
	assert(pos);
	LTNode* newnode = LTBuyNode(x);
	newnode->next = pos;
	newnode->prev = pos->prev;
	pos->prev->next = newnode;
	pos->prev = newnode;
}
