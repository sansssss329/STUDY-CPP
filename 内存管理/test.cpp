#include <iostream>
using namespace std;
class A {
public:
    A(int x = 0) 
    :val(x)
    {}
private:
    int val;
};
int main() {
    int* p1 = new int(1);
    cout << *p1 << endl;
    delete p1;
    int * p2 = new int[10];
    for(int i = 0; i < 10; i++) cout << p2[i] << ' ';
    delete p2;
    return 0;
}