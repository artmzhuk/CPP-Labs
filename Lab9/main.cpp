#include "Seq.h"
#include <iostream>

int main(){
    Seq<int, 4> s;
    s.add(5);
    s.add(2);
    s.add(6);
    s.add(1);
    std::cout << "s[1]\t" << s[1] << '\n';
    std::cout << "s: \t";
    std::cout << s;
    s*2;
    std::cout << "s*2: \t";
    std::cout << s;

    Seq<int, 4> s2;
    s2.add(9);
    s2.add(5);
    s2.add(3);
    s2.add(7);
    std::cout << "s2: \t";
    std::cout << s2;
    s+s2;
    std::cout << "sum: \t";
    std::cout << s;
    return 0;
};