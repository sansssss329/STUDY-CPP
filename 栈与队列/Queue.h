#pragma once
#include<stdio.h>
#include<stdlib.h>
#include<stdbool.h>
#include<assert.h>

#define QDataType int

typedef struct QueueNode
{
	QDataType val;
	struct QueueNode* next;
}QN, * pQN;

typedef struct Queue
{
	pQN phead;
	pQN ptail;
	int size;
}Queue, * pQueue;

void QueueInit(pQueue pq);
void QueuePush(pQueue pq, QDataType x);
void QueuePop(pQueue pq);
int QueueSize(pQueue pq);
bool QueueEmpty(pQueue pq);
QDataType QueueFront(pQueue pq);
QDataType QueueBack(pQueue pq);
void QueueDestory(pQueue pq);