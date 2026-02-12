// #include<iostream>
// using namespace std;

// void Print(string& s) {
//     // 1、    
//     // for(int i = 0; i < s.length(); i++) {
//     //     cout << s[i];
//     // }

//     // 2、
//     string::iterator it = s.begin();
//     while(it != s.end()) {
//         cout << *it;
//         ++it;
//     }

//     // 3、
//     // for(auto& ch : s) {
//     //     cout << ch;
//     //     ch++;
//     // }
//     // cout << endl;
// }

// void test1(){
//     string s = "hellow worid";
//     Print(s);
// }


// void test2() {
//     string x = "AAAA~~~,cclady";
//     string::reverse_iterator it = x.rbegin();
//     while(it != x.rend()) {
//         cout << *it;
//         it++;
//     }
//     cout << endl;
// }


// void test3() {
//     string x;
//     for(int i = 0; i < 500; i++) {
//         x += '0';
//         if(x.size() == x.capacity()) {
//             cout << "change:" << x.capacity() << endl;
//         }
//     }
// }

// void test4() {
//     string s;
//     for(int i = 0; i < 100; i++) {
//        s += '0';
//        if(s.size() == s.capacity()) {
//             cout << "change:" << s.capacity() << endl;
//         }
//     }
//     s.reserve(100);
//     cout << "change:" << s.capacity() << endl;
// }
// int main () {
//     test4();
//     return 0;
// }

#include"string.h"

namespace my {
    // std::istream& operator>>(std::istream& i, string& str) {
    //     i >> str._str;
    //     str._size = strlen(str._str);
    //     str._capacity = str._size + 1;
    //     return i;
    // }
    std::ostream& operator<<(std::ostream& o, const string& str) {
        if(str._str) {
            o << str._str;
        }
        return o;
    }    
//
//
    string::string(const string& str) {
         _size = str.size();
        _capacity = str.capacity();
        char* tmp = new char[_capacity];
        memcpy(tmp, str.c_str(), _size + 1);
        _str = tmp;
    }
    string::string(const char c) {
        char* tmp = new char[2];
        tmp[0] = c; tmp[1] = '\0';
        _str = tmp;
        _size = 1;
        _capacity = 2;
    }
    string::string(const char* ch) {
        char* tmp = new char[strlen(ch) + 1];
        strcpy(tmp, ch);
        _str = tmp;
        _size = strlen(ch);
        _capacity = _size + 1;
    }
//
//
    string::iterator string::begin() {
        return &_str[0];
    }
    string::iterator string::end() {
        return &_str[_size];
    }
    string::const_iterator string::const_begin() const {
        return &_str[0];
    }
    string::const_iterator string::const_end() const {
        return &_str[_size];
    }
//
//
    char string::operator[](size_t i) {
        return _str[i];
    }
//
//
    string& string::operator=(const string& str) {
        if(this != &str) {
            char* tmp = new char[_capacity];
            memcpy(tmp, str.c_str(), _size + 1);
            delete[] _str;
            _str = tmp;
            _size = str.size();
            _capacity = str.capacity();
        }
        return *this;
    }
    string& string::operator+=(const string& str) {
        size_t re_size = _size + 1 + str.size();
        while(re_size > _capacity) {
            size_t newcapacity = 2 * _capacity;
            char* tmp = new char[newcapacity];
            memcpy(tmp, _str, _size + 1);
            delete[] _str;
            _str = tmp;
            _capacity = newcapacity;
        }
        memcpy(_str + _size, str.c_str(), str.size() + 1);
        _size += str.size();
        return *this;
    }
    string string::operator+(const string& str) {
        string tmp(*this);
        tmp += str;
        return tmp;
    }
//
//
    string& string::operator=(const char c) {
        char* tmp = new char[2];
        tmp[0] = c; tmp[1] = '\0';
        delete[] _str;
        _str = tmp;
        _size = 1;
        _capacity = 2;
        return *this;
    }
    string& string::operator+=(const char c) {
        int re_size = _size + 2;
        while(re_size > _capacity) {
            int newcapacity = 2 * _capacity;
            char* tmp = new char[newcapacity];
            memcpy(tmp, _str, _size + 1);
            delete[] _str;
            _str = tmp;
            _capacity = newcapacity;
        }
        _str[_size] = c; _str[_size + 1] = '\0';
        _size ++;
        return *this;
    }
    string string::operator+(const char c) {
        string tmp(*this);
        tmp += c;
        return tmp;
    }
//
//
    string& string::operator=(const char* ch) {
        assert(ch);
        char* tmp = new char[strlen(ch) + 1];
        strcpy(tmp, ch);
        delete[] _str;
        _str = tmp;
        _size = strlen(ch);
        _capacity = _size + 1;
        return *this;
    }
    string& string::operator+=(const char* ch) {
        assert(ch);
        size_t re_size = _size + strlen(ch) + 1;
        while(re_size > _capacity) {
            int newcapacity = re_size < 2 * _capacity ? re_size : 2 * _capacity;
            char* tmp = new char[newcapacity];
            memcpy(tmp, _str, _size + 1);
            delete[] _str;
            _str = tmp;
            _capacity = newcapacity;
        }
        memcpy(_str + _size, ch, strlen(ch) + 1);
        _size = re_size - 1;
        return *this;       
    }
    string string::operator+(const char* ch) {
        assert(ch);
        string tmp(*this);
        tmp += ch;
        return tmp;
    }
//
//
    void string::append(char* ch) {
        assert(ch);
        size_t re_size = _size + strlen(ch) + 1;
        while(re_size > _capacity) {
            int newcapacity = re_size < 2 * _capacity ? re_size : 2 * _capacity;
            char* tmp = new char[newcapacity];
            memcpy(tmp, _str, _size + 1);
            delete[] _str;
            _str = tmp;
            _capacity = newcapacity;
        }
        memcpy(_str + _size, ch, strlen(ch) + 1);
        _size = re_size - 1;
    }
    void string::append(char* ch, size_t len) {
        assert(ch && len <= strlen(ch));
        size_t re_size = _size + len + 1;
        while(re_size > _capacity) {
            int newcapacity = re_size < 2 * _capacity ? re_size : 2 * _capacity;
            char* tmp = new char[newcapacity];
            memcpy(tmp, _str, _size + 1);
            delete[] _str;
            _str = tmp;
            _capacity = newcapacity;
        }
        memcpy(_str + _size, ch, len + 1);
        _size = re_size - 1;
    }
    void string::append(size_t n, char c) {
        size_t re_size = _size + n + 1;
        while(re_size > _capacity) {
            int newcapacity = re_size < 2 * _capacity ? re_size : 2 * _capacity;
            char* tmp = new char[newcapacity];
            memcpy(tmp, _str, _size + 1);
            delete[] _str;
            _str = tmp;
            _capacity = newcapacity;
        }
        for(size_t i = _size; i < re_size - 1; i++) _str[i] = c;
        _size = re_size - 1;
        _str[_size] = '\0';
    }
    void string::append(char* ch, size_t pos, size_t len) {
        assert(ch && pos < strlen(ch) && len <= strlen(ch) - pos);
        size_t re_size = _size + len + 1;
        while(re_size > _capacity) {
            int newcapacity = re_size < 2 * _capacity ? re_size : 2 * _capacity;
            char* tmp = new char[newcapacity];
            memcpy(tmp, _str, _size + 1);
            delete[] _str;
            _str = tmp;
            _capacity = newcapacity;
        }
        memcpy(_str + _size, ch + pos, len);
        _size = re_size - 1;
        _str[_size] = '\0';
    }
    void string::append(string& str, size_t pos, size_t len) {

    }
//
//
    void string::push_back(char* ch) {
        assert(ch);
        size_t re_size = _size + strlen(ch) + 1;
        while(re_size >= _capacity) {
            int newcapacity = re_size < 2 * _capacity ? re_size : 2 * _capacity;
            char* tmp = new char[newcapacity];
            memcpy(tmp, _str, _size + 1);
            delete[] _str;
            _str = tmp;
            _capacity = newcapacity;
        }
        memcpy(_str + _size, ch, strlen(ch) + 1);
        _size = re_size - 1;
    }    
}