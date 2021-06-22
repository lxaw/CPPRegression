#include <iostream>

// User created classes
#include "Matrix.h"
#include "Matrix.cpp"

int main(){
    Matrix<double> mat(4,4);
    mat.setAtIndex(6.1, 1, 2);
    mat.print();
    return 0;
}

