#include"Sort.h"
#include "Stack.h"
int MidValue(int* a, int left, int right) {
	int mid = (left + right) / 2;
	if (a[left] > a[mid]) {
		if (a[left] < a[right]) {
			return right;
		}
		else {
			if (a[right] > a[mid]) { 
				return right;
			}
			else {
				return mid;
			}
		}
	}
	else {
		if (a[right] > a[mid]) {
			return mid;
		}
		else {
			if (a[right] > a[left]) {
				return right;
			}
			else {
				return left;
			}
		}
	}
}

void Swap(int* a, int* b) {
	int tmp = *a;
	*a = *b;
	*b = tmp;
}

void Print(int* a, int n) {
	for (int i = 0; i < n; i++) {
		printf("%d ", a[i]);
	}
}

void InsertSort(int* a, int n) {
	for (int i = 0; i < n - 1; i++) {
		int end = i;
		int tmp = a[end + 1];
		while (end >= 0) {
			if (tmp < a[end]) {
				a[end + 1] = a[end];
				end--;
			}
			else {
				break;
			}
		}
		a[end + 1] = tmp;
	}
}



void HPAdjustDown(int* a, int NumSize, int parent) {
	assert(a);
	int child = parent * 2 + 1;
	while (child < NumSize) {
		if (child + 1 < NumSize && a[child] < a[child + 1]) {
			child++;
		}
		if (a[child] > a[parent]) {
			Swap(&a[child], &a[parent]);
		}
		parent = child;
		child = parent * 2 + 1;
	}
}


void HeapSort(int* a, int n) {
	assert(a);
	//½¨¶Ñ
	for (int i = n / 2 - 1; i >= 0; i--) {
		HPAdjustDown(a, n, i);
	}
	int end = n - 1;
	while (end >= 0) {
		Swap(&a[0], &a[end]);
		HPAdjustDown(a, end, 0);
		end--;
	}
}


void ShellSort(int* a, int n) {
	int gap = 3;
	while (gap > 1) {
		gap = gap / 3 + 1;
		for (int i = 0; i < n - gap; i++) {
			int end = i;
			int tmp = a[end + gap];
			while (end >= 0) {
				if (a[end] > tmp) {
					a[end + gap] = a[end];
					end -= gap;
				}
				else {
					break;
				}
			}
			a[end + gap] = tmp;
		}
	}
}

void BubbleSort(int* a, int NumsSize) {
	int n = NumsSize;
	for (int i = 0; i < NumsSize; i++) {
		int flag = 0;
		for (int j = 0; j < n - 1; j++) {
			if (a[j] > a[j + 1]) {
				flag = 1;
				Swap(&a[j], &a[j + 1]);
			}

		}
		if (flag == 0) {
			break;
		}
		n--;
	}
}

void SelectSort(int* a, int n) {
	int begin = 0, end = n - 1;
	int min, max;
	while (begin < end) {
		for (int i = 1; i < end; i++) {
			if (a[begin] > a[i]) {
				min = i;
				Swap(&a[begin], &a[min]);
			}
			if (a[end] < a[i]) {
				max = i;
				Swap(&a[end], &a[max]);
			}
		}
		begin++;
		end--;
	}
}

void QuickSort(int* a, int left , int right) {
	if (left >= right) return;
	int begin = left, end = right, key = left;
	while (begin < end) {
		while (begin < end && a[end] >= a[key]) {
			end--;
		}
		while (begin < end && a[begin] <= a[key]) {
			begin++;
		}
		Swap(&a[begin], &a[end]);
	}
	Swap(&a[end], &a[key]);
	QuickSort(a, left, end - 1);
	QuickSort(a, end + 1, right);
}

void QuickSort1(int * a, int left, int right) {
	if (left >= right) return;

	int key = MidValue(a, left, right);
	Swap(&a[key], &a[left]);
	key = left;
	int tmp = a[key];
	int begin = left, end = right;
	while (begin < end) {
		while (end > begin && a[end] > tmp) {
			end--;
		}
		a[begin] = a[end];
		while (begin < end && a[begin] <= tmp) {
			begin++;
		}
		a[end] = a[begin];
	}
	a[end] = tmp;
	QuickSort1(a, left, end - 1);
	QuickSort1(a, end + 1, right);
}

void QuickSort2(int* a, int left, int right) {
	if (left >= right) return;
	int key = MidValue(a, left, right);
	Swap(&a[key], &a[left]);
	key = left;
	int pcur = left + 1;
	int prev = left;
	while (pcur <= right) {
		if (a[pcur] < a[key] && ++prev != pcur) Swap(&a[prev], &a[pcur]);
		pcur++;
	}
	Swap(&a[key], &a[prev]);
	QuickSort2(a, left, prev - 1);
	QuickSort2(a, prev + 1, right);
}

void Stack_QuickSort(int* a, int left, int right) {
	ST* st = (ST*)malloc(sizeof(ST));
	if (!st) {
		perror("malloc fail");
	}
	STInit(st);
	STDataType tmp = { left, right };
	STPush(st, tmp);
	while (!STEmpty(st)) {
		STDataType cur = STTop(st);
		STPop(st);
		int key = MidValue(a, cur.x, cur.y);
		int begin = cur.x, end = cur.y;
		Swap(&a[key], &a[cur.x]);
		key = cur.x;
		while (begin < end) {
			while (begin < end && a[key] < a[end]) {
				end--;
			}
			while (begin < end && a[key] >= a[begin]) {
				begin++;
			}
			Swap(&a[begin], &a[end]);
		}
		Swap(&a[key], &a[end]);
		if (end + 1 < cur.y) {
			STDataType R = { end + 1, cur.y };
			STPush(st, R);
		}
		if (cur.x < end - 1) {
	    	STDataType L = { cur.x, end - 1 };
			STPush(st, L);
		} 
	}
}

void _MergeSort(int* a, int* tmp, int left, int right) {
	if (left >= right) return;

	int mid = (left + right) / 2;
	_MergeSort(a, tmp, left, mid);
	_MergeSort(a, tmp, mid + 1, right);

	int begin1 = left, end1 = mid;
	int begin2 = mid + 1, end2 = right;
	int i = begin1;
	while (begin1 <= end1 && begin2 <= end2) {
		if (a[begin1] <= a[begin2]) {
			tmp[i++] = a[begin1++];
		}
		else {
			tmp[i++] = a[begin2++];
		}
	}
	while (begin1 <= end1) tmp[i++] = a[begin1++];
	while (begin2 <= end2) tmp[i++] = a[begin2++];
	memcpy(a + left, tmp + left, sizeof(int) * (right - left + 1));
}

void MergeSort(int* a, int n) {
	assert(a);
	int* tmp = (int*)malloc(sizeof(int) * n);
	if (!tmp) {
		perror("malloc fail");
		exit(1);
	}
	_MergeSort(a, tmp, 0, n - 1);
}

void No_MergeSort(int* a, int n) {
	assert(a);
	int* tmp = (int*)malloc(sizeof(int) * n);
	if (!tmp) {
		perror("malloc fail");
		exit(1);
	}
	int gap = 1;
	while (gap < n) {
		for (int i = 0; i < n; i += 2 * gap) {
			int begin1 = i, end1 = i + gap - 1;
			int begin2 = i + gap, end2 = i + gap * 2 - 1;
			if (end1 >= n) break;
			if (end2 >= n) end2 = n - 1;
			int j = i;
			while (begin1 <= end1 && begin2 <= end2) {
				if (a[begin1] <= a[begin2]) {
					tmp[j++] = a[begin1++];
				}
				else {
					tmp[j++] = a[begin2++];
				}
			}
			while (begin1 <= end1) tmp[j++] = a[begin1++];
			while (begin2 <= end2) tmp[j++] = a[begin2++];
			memcpy(a + i, tmp + i, sizeof(int) * (end2 - i + 1));
		}
		gap *= 2;
	}
}

void CountSort(int* a, int n) {
	assert(a);
	int max = a[0], min = a[0];
	for (int i = 0; i < n; i++) {
		if (a[i] > max) max = a[i];
		if (a[i] < min) min = a[i];
	}

	int range = max - min + 1;
	int* tmp = (int*)calloc(range, sizeof(int)); 
	if (!tmp) {
		perror("calloc fail");
		exit(1);
	}

	for (int i = 0; i < n; i++) {
		tmp[a[i] - min]++;
	}

	int i = 0, j = 0;
	while (i < n) {
		while (tmp[j]-- && i < n) {
			a[i] = j + min;
			i++;
		}
		j++;
	}
	
	free(tmp);
}