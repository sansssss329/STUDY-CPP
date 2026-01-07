#include<iostream>
using namespace std;


class Stack {
public:
	Stack(int x = 0) {
		int* tmp = (int*)malloc(sizeof(int) * 4);
		if (!tmp) {
			perror("Stack::malloc fail");
			exit(1);
		}
		a = tmp;
		size = top = 0;
		capacity = 4;
	}

	void Print() {
		for (int i = 0; i < size; i++) {
			cout << a[i] << ' ';
		}
		cout << endl;
	}

	void Push(int x) {
		if (size == capacity) {
			int* tmp = (int*)realloc(a, 2 * capacity);
			if (!tmp) {
				perror("Stack::malloc fail");
				exit(1);
			}
			a = tmp;
			capacity *= 2;
		}
		a[top] = x;
		top++; size++;
	}

	void Pop() {
		if (!top) return;
		top--; size--;
	}

	bool Empty() {
		return size == 0;
	}


private:
	int* a;
	int top;
	int size;
	int capacity;
};

class Myqueue {
public:
private:
};



int main() {
	Stack s1();
	s1.Print();
	return 0;
}