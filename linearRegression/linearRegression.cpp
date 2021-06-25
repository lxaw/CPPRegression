#include <iostream>

// User created classes
#include "Matrix.h"
#include "Matrix.cpp"

int main(){
    Matrix<double> mat(3,4);
    mat.setRandomInt();
    cout << "MAT:" << endl;
    mat.print();
    Matrix<double> mat2(4, 3);
    mat2.setRandomInt();
    cout << "MAT2" << endl;
    mat2.print();

    Matrix<double> res = mat * mat2;
    res.print();

    return 0;
}

