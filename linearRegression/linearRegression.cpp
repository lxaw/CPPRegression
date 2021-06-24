#include <iostream>

// User created classes
#include "Matrix.h"
#include "Matrix.cpp"

int main(){
    Matrix<double> mat(4,4);
    mat.setRandomInt();
    cout << "MAT:" << endl;
    mat.print();
    Matrix<double> t = mat.transpose();
    cout << "T:" << endl;
    t.print();
    return 0;
}

