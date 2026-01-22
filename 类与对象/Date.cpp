#include"Date.h"
bool Date::DateCheck() {
    if(_month < 1 || _month > 12 || _day > GetMonthDay(_month)) return 0;
    return 1;
}


Date::Date(int x, int y, int z) {
    _year = x;
    _month = y;
    _day = z;
    if(!Date::DateCheck()) {
        cout << "日期非法" << endl;
    }
}
Date::Date(const Date& d) {
    _year = d._year;
    _month = d._month;
    _day = d._day;
}


void Date::Print() {
    cout << _year << " - " << _month << " - " << _day << endl;
}


bool Date::operator>(const Date& d) {
    if(_year == d._year) {
        if(_month == d._month) {
            return _day > d._day;
        }
        return _month > d._month;
    }
    return _year > d._year;
}
bool Date::operator==(const Date& d) {
    return (_year == d._year) && (_month == d._month) && (_day == d._day);
}
bool Date::operator<(const Date& d) {
    if(_year == d._year) {
       if(_month == d._month) {
           return _day < d._day;
       }
       return _month < d._month;
    }
    return _year < d._year;
}
bool Date::operator!=(const Date& d) {
    return !(*this == d);
}
bool Date::operator>=(const Date& d) {
    return !(*this < d);
}
bool Date::operator<=(const Date& d) {
    return !(*this > d);
}


Date& Date::operator-=(int day) {
    if(day < 0) return *this += (-day);
    _day -= day;
    int tmp = GetMonthDay(_month);
    while(_day <= 0) {
        _day += tmp;
        if(_month == 1) {
            _month = 12;
            _year--;
        } 
        else {
            _month--;
        }
        tmp = GetMonthDay(_month);
    }
    return *this;
}
Date Date::operator-(int day) {
    Date tmp(*this);
    tmp -= day;
    return tmp;
}
Date& Date::operator+=(int day) {
    if(day < 0) return *this -= (-day);
    _day += day;
    int tmp = Date::GetMonthDay(_month);
    while(_day > tmp) {
        _day -= tmp;
        if(_month == 12) {
            _month = 1;
            _year++;
        }
        else {
            _month++;
        }
        tmp = Date::GetMonthDay(_month);
    }
    return *this;
}
Date Date::operator+(int day) {
    Date tmp(*this);
    tmp += day;
    return tmp;
}


Date Date::operator++(int) {
    Date tmp(*this);
    *this += 1;
    return tmp;
}
Date& Date::operator++() {
    *this += 1;
    return *this;
}
Date Date::operator--(int) {
    Date tmp(*this);
    *this -= 1;
    return tmp;
}
Date& Date::operator--() {
    *this -= 1;
    return *this;
}


int Date::operator-(const Date& d) {
    int flag = 1;
    Date max = *this;
    Date min = d;
    if(*this < d) {
        flag = -1;
        max = d;
        min = *this;
    }
    int n = 0;
    while(min != max) {
        min++;
        n++;
    }
    return flag * n;
}


ostream& operator<<(ostream& out, const Date& d) {
    out << d._year << " - " << d._month << " - " << d._day;
    return out;
}
istream& operator>>(istream& in, Date& d) {
    in >> d._year >> d._month >> d._day;
    return in;
}