#define _CRT_SECURE_NO_WARNINGS
#include"Heap.h"
void text1() {
	HPDataType a[] = {6,1,33,22,13,4,2,44,23};
	HPSort(a, sizeof(a) / sizeof(a[0]));
	for (int i = 0; i < sizeof(a) / sizeof(a[0]); i++) {
		printf("%d ",a[i]);
	}
}


void text2() {
	FILE* f = fopen("data.txt", "w");
	if (!f) {
		perror("fopen");
		exit(1);
	}
	int n = 100000;;
	srand((unsigned int)time(NULL));
	while (n--) {
		int num = rand() % 1000000;
		fprintf(f, "%d\n", num);
	}
	fclose(f);
	f = NULL;

	HPNPopK(100000, 10);
}

int main() {
	/*Heap hp = { 0 };
	HPInit(&hp);
	HPPush(&hp, 0);
	HPPush(&hp, 1);
	HPPush(&hp, 2);
	HPPush(&hp,	13);
	HPPush(&hp, 4);
	HPPush(&hp, 5);
	HPPush(&hp, 3);
	HPPush(&hp, 17);
	HPPush(&hp, 9);
	HPPrint(&hp);

	HPPopTop(&hp);
	HPPrint(&hp);*/
	//text1();

	/*text2();*/

	HPNPopK(100000, 10);

	return 0;
}