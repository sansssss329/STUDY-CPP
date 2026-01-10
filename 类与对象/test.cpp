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
    ~Stack() {
        free(a);
        a = nullptr;
    }
private:
	int* a;
	int top;
	int size;
	int capacity;
};

class Time {
public:
    Time(int x = 2025, int y = 1, int z = 1) {
        _year = x;
        _month = y;
        _day = z;
    }

    Time(Time& d1) {
        _year = d1._year;
        _month = d1._month;
        _day = d1._day;
    }

    void Insert(int x, int y, int z) {
         _year = x;
        _month = y;
        _day = z;
    }
    void Print() {
        cout << _year << " // " << _month << " // " << _day << endl;
    }

    bool operator==(Time d1) {
        return d1._year == _year
        && d1._month == _month
        && d1._day == _day;
    }
private:
    int _year;
    int _month;
    int _day; 
};



int main() {
	// Stack s1(0);
    // s1.Push(21);
    // s1.Push(15);
    // s1.Push(142);
    // s1.Push(11);
    // s1.Push(16);
    // s1.Push(12);
    // s1.Push(1214);
    // s1.Push(141);
    // s1.Push(13);
    // s1.Push(12);
	// s1.Print();
    Time t1(1);
    t1.Insert(2026, 1, 10);

	return 0;
}