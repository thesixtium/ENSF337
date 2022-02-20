// ENSF 337 - Lab 7 exercise A

#include "cplx.h"
#include <iostream>

void global_print(const Cplx& n);


int main(void)
{
    Cplx num1;
    std::cout << "\nA" << std::endl;
    
    num1.setRealPart(666);
    std::cout << num1.getRealPart() << std::endl;
    std::cout << num1.getImaginaryPart() << std::endl;
    std::cout << "\nB" << std::endl;

    Cplx num2(34, 5);
    std::cout << "\nC" << std::endl;

    num1.setImaginaryPart(500);
    std::cout << "\nD" << std::endl;

    return 0;
}

