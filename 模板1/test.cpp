#include<iostream>
using namespace std;

// template <class T>
// void Swap(T& a, T& b) {
//     T tmp = a;
//     a = b;
//     b = tmp;
// }

// int main() {
//     string x, y;
//     cin >> x >> y;
//     Swap(x, y);
//     cout << x << ' ' << y << endl;
//     Swap<string>(x, y);
//     cout << x << ' ' << y << endl;    
//     return 0;
// }

template <class T>
class Stack {
public:
    Stack() 
    :_array (new T[4])
    ,_size (0)
    ,_capacity (4)
    {}

    T Front(){
        assert(_size);
        return _array[_size - 1];
    }

    void Push(const T& a) {
        if(_size == _capacity) {
            T* tmp = new T[_capacity * 2];
            memcpy(tmp, _array, _capacity * sizeof(T));
            delete[] _array;
            _array = tmp;
            _capacity *= 2;
        }
        _array[_size++] = a;
    }

    void Pop() {
        _size--;
    }

    int Size() {
        return _size;
    }

    bool Empty() {
        return _size == 0;
    }

    ~Stack() {
        delete[] _array;
        _array = nullptr;
    }
private:
    T* _array;
    int _size = 0;
    int _capacity = 4;
};
int main() {
    Stack<int> st;
    st.Push(182);
    st.Push(132);    
    st.Push(172);
    st.Push(123);
    st.Push(123);
    st.Push(312);
    st.Push(312);
    st.Push(132);
    st.Push(1212);
    st.Push(1242);
    st.Push(1432);
    st.Push(25);
    st.Push(18);
    st.Push(212);
    while(!st.Empty()) {
        cout << st.Front() << ' ';
        st.Pop();
    }
    return 0;
}