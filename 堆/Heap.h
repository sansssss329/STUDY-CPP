#pragma once
#include<stdio.h>
#include<stdlib.h>
#include<stdbool.h>
#include<assert.h>
#include<math.h>
#define HPDataType int

typedef struct
{
	HPDataType* a;
	int size;
	int capacity;
}Heap;

void HPInit(Heap* php);
void HPPush(Heap* php, HPDataType x);
void HPPopTop(Heap* php);
bool HPEmpty(Heap* php);
int HPSize(Heap* php);
void HPPrint(Heap* php);
void HPSort(HPDataType* a, int NumsSize);
void HPNPopK(int Size, int k);