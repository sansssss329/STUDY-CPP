#pragma once
#include<iostream>
#include<cstring>
#include<assert.h>
namespace my {
    class string {
    public:
        // friend std::istream& operator>>(std::istream& i, string& str);
        friend std::ostream& operator<<(std::ostream& o, const string& str);

        string()
        :_size(0)
        ,_capacity(1)
        {
            _str = new char[1]{'\0'};
        }

        string(const string& str);
        string(const char c);
        string(const char* ch);
        

        int size() const {
            return _size;
        }

        int capacity() const {
            return _capacity;
        }

        char* c_str() const {
            return _str;
        }


        typedef char* iterator;
        typedef const char* const_iterator;
        iterator begin();
        iterator end();
        const_iterator const_begin() const;
        const_iterator const_end() const;


        char operator[](size_t i);


        string& operator=(const string& str);
        string& operator+=(const string& str);
        string operator+(const string& str);


        string& operator=(const char c);
        string& operator+=(const char c);
        string operator+(const char c);


        string& operator=(const char* ch);
        string& operator+=(const char* ch);
        string operator+(const char* ch);


        void append(char* ch);
        void append(char* ch, size_t n);
        void append(size_t n, char c);
        void append(char* ch, size_t pos, size_t len);
        void append(string& str, size_t pos, size_t len);

        void push_back(char* ch);

        ~string() {
            delete[] _str;
        }


    private:
    char* _str;
    size_t _size;
    size_t _capacity;
    static size_t npos;
    };
}