#include <iostream>
#include "Fraction.h"


Fractions::fraction::fraction() {}
Fractions::fraction::fraction(int num, int denom) {
    this->num = num;
    this->denom = denom;
    nod = NOD(num, denom);
}

std::ostream &operator<<(std::ostream &os, const Fractions::fraction &fraction) {
    os<< fraction.num << "/" << fraction.denom << std::endl;
    return os;
}


Fractions::Fractions(int n) : n(n){
    fraction *arr = new fraction[5]();
    for (int i = 0; i < n; ++i){
        int thisNum;
        int thisDenom;
        std::cin >> thisNum >> thisDenom;
        std::cout << "Fraction added: " <<  thisNum << "/" << thisDenom <<std::endl;
        arr[i].num = thisNum;
        arr[i].denom = thisDenom;
        arr[i].nod = NOD(thisNum, thisDenom);
    }
    array = arr;
}

void Fractions::print() {
    for(int i = 0; i < n; i++){
        std::cout << array[i].num << "/" << array[i].denom << " ";
    }
    std::cout <<"\n";
}

Fractions::fraction &Fractions::operator[](int i) {
    return array[i];
}

int Fractions::NOD(int a, int b) {
    if (a < b) {
        std::swap(a, b);
    }
    while (a % b != 0) {
        a = a % b;
        std::swap(a, b);
    }
    return b;
}
