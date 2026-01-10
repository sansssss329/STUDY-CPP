#include"Queue.h"
void QueueInit(pQueue pq) {
	pq->phead = pq->ptail = NULL;
	pq->size = 0;
}

//Î²²å
void QueuePush(pQueue pq, QDataType x) {
	assert(pq);
	pQN pcur = (pQN)malloc(sizeof(QN));
	if (!pcur) {
		perror("malloc fail");
		return;
	}
	pcur->val = x;
	pcur->next = NULL;
	if (!pq->ptail) {
		pq->phead = pq->ptail = pcur;
	}
	else {
		pq->ptail->next = pcur;
		pq->ptail = pcur;
	}
	pq->size++;
}

//Í·É¾
void QueuePop(pQueue pq) {
	assert(pq && pq->phead);
	pQN pcur = pq->phead->next;
	free(pq->phead);
	if (!pcur) {
		pq->phead = pq->ptail = NULL;
	}
	else {
		pq->phead = pcur;
	}
	pq->size--;
}

bool QueueEmpty(pQueue pq) {
	assert(pq);
	return pq->phead == NULL;
}

int QueueSize(pQueue pq) {
	assert(pq);
	return pq->size;
}


QDataType QueueFront(pQueue pq) {
	assert(pq && pq->phead);
	return pq->phead->val;
}


QDataType QueueBack(pQueue pq) {
	assert(pq && pq->ptail);
	return pq->ptail->val;
}

void QueueDestory(pQueue pq) {
	assert(pq);
	free(pq);
	pq = NULL;
}