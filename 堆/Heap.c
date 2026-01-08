#define _CRT_SECURE_NO_WARNINGS
#include"Heap.h"
 


void Swap(HPDataType* a, HPDataType* b) {
	int tmp = *a;
	*a = *b;
	*b = tmp;
}

void HPInit(Heap* php) {
	php->a = NULL;
	php->size = 0;
	php->capacity = 0;
}

void HPAdjustUp(HPDataType* php, int child) {
	assert(php);
	while (php[(child - 1) / 2] > php[child] && child) {
		Swap(&php[(child - 1) / 2], &php[child]);
		child = (child - 1) / 2;
 	}
}

void HPAdjustDown(HPDataType* a, int NumsSize, int parent) {
	assert(a);
	int child = parent * 2 + 1;
	while (child < NumsSize) {
		if (child + 1 < NumsSize && a[child] > a[child + 1]) {
			child++;
		}
		if (a[parent] < a[child]) {
			break;
		}
		Swap(&a[parent], &a[child]);
		parent = child;
		child = parent * 2 + 1;
	}
}

void HPPush(Heap* php, HPDataType x) {
	assert(php);
	if (php->capacity == php->size) {
		int newcapacity = php->capacity == 0 ? 4 : (2 * php->capacity);
		HPDataType* pcur = (HPDataType*)realloc(php->a, sizeof(HPDataType) * newcapacity);
		if (!pcur) {
			perror("HPPush::realloc");
			exit(1);
		}
		php->a = pcur;
		php->capacity = newcapacity;
	}
	php->a[php->size] = x;
	HPAdjustUp(php, php->size++);
}

void HPPopTop(Heap* php) {
	assert(php && php->size);
	Swap(&php->a[0], &php->a[--php->size]);
	HPAdjustDown(php, php->size, 0);
}

bool HPEmpty(Heap* php) {
	assert(php);
	return php->size == 0 ? 1 : 0;
}

int HPSize(Heap* php) {
	assert(php);
	return php->size;
}

void HPPrint(Heap* php) {
	for(int i = 0 ; i < php->size ; i++) {
		printf("%d ", php->a[i]);
	}
	printf("\n");
}

void HPSort(HPDataType* a, int NumsSize) {
	for (int i = (NumsSize - 2) / 2 ; i >= 0; i--) {
		HPAdjustDown(a, NumsSize, i);
	}
	int end = NumsSize - 1;
	while (end > 0) {
		Swap(&a[0], &a[end]);
		HPAdjustDown(a, end, 0);
		end--;
	}
}

void HPNPopK(int Size, int k) {
	FILE* f = fopen("data.txt", "r");
	if (!f) {
		perror("fopen");
		exit(1);
	} 
	int* a = (int*)malloc(sizeof(int) * k);
	if (!a) {
		perror("HPNPopK::malloc");
		exit(1);
	}

	//读入前k个元素
	for (int i = 0; i < k; i++) fscanf(f, "%d", &a[i]);
	
	//先建堆
	for (int i = (k - 2) / 2; i >= 0; i--) {
		HPAdjustDown(a, k, i);
	}

	//遍历剩余元素，与堆顶比较
	int exp = Size - k;
	while (exp--) {
		int x = 0;
		fscanf(f, "%d", &x);
		if (x > a[0]) {
			a[0] = x;
			HPAdjustDown(a, k, 0);
		}
	}

	//排序
	int end = k - 1;
	while (end > 0) {
		Swap(&a[0], &a[end]);
		HPAdjustDown(a, end, 0);
		end--;
	}
	fclose(f);
	f = NULL;

	//打印
	for (int i = 0; i < k; i++) {
		printf("%d ", a[i]);
	}
}