#include <iostream>
#include "Fraction.h"

int main(){
    Fractions f(3);
    std::cout << "NOD:\t\t";
    for (auto i : f)
        std::cout << i << " ";
    std::cout << "\nFraction[1] changed: 9/81\n";
    f[1] = Fractions::fraction(9, 81);
    f.print();
    for (auto i : f)
        std::cout << i << " ";
    return 0;
}