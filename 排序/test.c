#include"Sort.h" 

void test1() {
	int a[] = { 1,4,2,4,6,3,2,2,23,24,324,325 };

}

void test2() {
	int a[] = { 1,4,2,4,6,3,2,2,23,24,324,325 };
	HeapSort(a, sizeof(a) / sizeof(a[0]));
	Print(a, sizeof(a) / sizeof(a[0]));
}

void test3() {
	int a[] = { 1,4,2,4,6,3,2,2,23,24,324,325 };
	ShellSort(a, sizeof(a) / sizeof(a[0]));
	Print(a, sizeof(a) / sizeof(a[0]));
}

void test4() {
	int a[] = { 1,4,2,4,6,3,2,2,23,24,324,325 };
	InsertSort(a, sizeof(a) / sizeof(a[0]));
	Print(a, sizeof(a) / sizeof(a[0]));
}

void test5() {
	int a[] = { 1,4,2,4,6,3,2,2,23,24,324,325 };
	QuickSort(a, 0, sizeof(a) / sizeof(a[0]) - 1);
	Print(a, sizeof(a) / sizeof(a[0]));
}

void test6() {
	int a[] = { 1,4,2,4,6,3,2,2,23,24,324,325 };
	QuickSort2(a, 0, sizeof(a) / sizeof(a[0]) - 1);
	Print(a, sizeof(a) / sizeof(a[0]));
}

void test7() {
	int a[] = { 1,4,2,4,6,3,2,2,23,24,324,325 };
	QuickSort1(a, 0,sizeof(a) / sizeof(a[0]) - 1);
	Print(a, sizeof(a) / sizeof(a[0]));
}

void test8() {
	int a[] = { 3,4332,534,75,235,976,3459,3587,3529,643,953,0 };
	Stack_QuickSort(a, 0, sizeof(a) / sizeof(a[0]) - 1);
	Print(a, sizeof(a) / sizeof(a[0]));
}

void test9() {
	int a[] = { 3,4332,534,7554,25,6,39,37,35124529,64643,952133,2130 };
	MergeSort(a, sizeof(a) / sizeof(a[0]));
	Print(a, sizeof(a) / sizeof(a[0]));
}

void test10() {
	int a[] = { 3,4332,534,75,235,976,3459,3587,3529,643,953,0 };
	No_MergeSort(a, sizeof(a) / sizeof(a[0]));
	Print(a, sizeof(a) / sizeof(a[0]));
}

void test11() {
	int a[] = { 3,4332,534,75,235,976,3459,3587,3529,643,953,0 };
	CountSort(a, sizeof(a) / sizeof(a[0]));
	Print(a, sizeof(a) / sizeof(a[0]));
}

int main() {
	test3();
	return 0;
}