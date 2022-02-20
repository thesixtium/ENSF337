//  ENSF 337, Exercise A
//  cplx.cpp
//  By: M. Moussavi 

#include "cplx.h"
#include <iostream>

Cplx::Cplx(double real , double imag ): realM(real), imagM(imag) {
    // point one
    std::cout << "\nPoint 1" << std::endl;
}

double Cplx::getRealPart() const {
    return realM;
}

double Cplx::getImaginaryPart( ) const {
    return imagM;
}

void Cplx::setRealPart(double arg) {
    std::cout << "\n3" << std::endl;
    realM = arg;
}

void Cplx::setImaginaryPart(double arg) {
    imagM = arg;
    // point
    std::cout << "\nPoint 2" << std::endl;
}



