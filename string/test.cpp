#include"string.h"
using namespace my;

int main () {
    string s1("sadffewf");
    s1 += "asdfghjkl;";
    std::cout << s1 << std::endl;
    s1 += 'l';
    std::cout << s1 << std::endl;   
    return 0;
}