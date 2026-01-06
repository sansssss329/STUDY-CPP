#pragma once
#include<stdio.h>
#include<stdlib.h>
#include<stdbool.h>
#include<assert.h>
#include<math.h>
#include<time.h>
#include<string.h>
void Print(int* a, int NumSize);
void InsertSort(int* a, int NumSize);
void HPAdjustDown(int* a, int NumSize, int parent);
void HeapSort(int* a, int n);
void ShellSort(int* a, int n);
void BubbleSort(int* a, int n);
void SelectSort(int* a, int n);

void QuickSort(int* a, int left, int right);
void QuickSort1(int* a, int left, int right);
void QuickSort2(int* a, int left, int right);
void Stack_QuickSort(int* a, int left, int right);
void MergeSort(int* a, int n);
void No_MergeSort(int* a, int n);

void CountSort(int* a, int n);