#include <iostream>
using namespace std;
class Time {
public:
    Time(int i = 1)
        : a(i)
        , b(a)
        , c((int*)malloc(12))
    {
        if(!c) {
            perror("Time::malloc");
            exit(1);
        }
    }


    ~Time() {
        free(c);
    }
private:
    int a;
    int b;
    int* c;
};

int main() {
    int a[] = {1,234,54,23476,347845,983};
    sort(a, a + 6);
    for(int i = 0; i < sizeof(a) / sizeof(a[0]); i++) {
        cout << a[i] << ' ';
    }
    return 0;
}