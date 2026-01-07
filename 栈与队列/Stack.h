#pragma once
#include<stdio.h>
#include<stdlib.h>
#include<stdbool.h>
#include<assert.h>

#define STDataType char

typedef struct STNode
{
	STDataType* a;
	int top;
	int capacity;
}ST;

void STInit(ST* pst);
void STDestory(ST* pst);
void STPush(ST* pst, STDataType x);
void STPop(ST* pst);
STDataType STTop(ST* pst);
bool STEmpty(ST* pst);
int STSize(ST* pst);
