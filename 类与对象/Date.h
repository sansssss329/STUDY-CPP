#pragma once
#include<iostream>
using namespace std;
class Date {
public:
    friend ostream& operator<<(ostream& out, const Date& d);
    friend istream& operator>>(istream& in, Date& d);


    Date(int x = 2000, int y = 1, int z = 1);
    Date(const Date& d);
    void Print();

    int GetMonthDay(int month) {
        if(_month == 2 && ((_year % 4 == 0 && _year % 100 != 0) || _year % 400 == 0)) return 29;
        static int day[] = {0,31,28,31,30,31,30,31,31,30,31,30,31};
        return day[month];
    }
    bool DateCheck();

    bool operator>(const Date& d);
    bool operator==(const Date& d);
    bool operator<(const Date& d);
    bool operator!=(const Date& d);
    bool operator>=(const Date& d);
    bool operator<=(const Date& d);

    Date& operator-=(int day);
    Date operator-(int day);
    Date& operator+=(int day);
    Date operator+(int day);

    Date operator++(int);
    Date& operator++();
    Date operator--(int);
    Date& operator--();

    int operator-(const Date& d);
private:
    int _year;
    int _month;
    int _day; 
};