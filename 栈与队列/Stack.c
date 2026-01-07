#include"Stack.h"
void STInit(ST* pst) {
	assert(pst);
	pst->a = (STDataType*)malloc(sizeof(STDataType) * 4);
	if (!pst->a) {
		perror("malloc fail");
		return;
	}
	pst->top = 0;
	pst->capacity = 4;
}

void STDestory(ST* pst) {
	assert(pst);
	pst->top = pst->capacity = 0;
	free(pst->a);
	pst->a = NULL;
}

void STPush(ST* pst, STDataType x) {
	assert(pst);
	if (pst->top == pst->capacity) {
		int new_capacity = 2 * pst->capacity;
		STDataType* pcur = (STDataType*)realloc(pst->a, sizeof(STDataType) * new_capacity);
		if (!pcur) {
			perror("realloc fail");
			return;
		}
		pst->a = pcur;
		pst->capacity = new_capacity;
	}
	pst->a[pst->top++] = x;
}

bool STEmpty(ST* pst) {
	assert(pst);
	return pst->top == 0;
}

void STPop(ST* pst) {
	assert(pst);
	if (STEmpty(pst)) {
		return;
	}
	pst->top--;
}

STDataType STTop(ST* pst) {
	assert(pst && !STEmpty(pst));
	return pst->a[pst->top - 1];
}

int STSize(ST* pst) {
	assert(pst);
	return pst->top;
}