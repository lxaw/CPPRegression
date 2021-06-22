#include <iostream>
// user classes
#include "Matrix.h"


using namespace::std;

// Constructor
template <typename T>
Matrix<T>::Matrix(int m, int n) {
	_m = m;
	_n = n;
	
	// initiate the dimensions, set zeros for default;
	init();
	setZeroes();
}
// destructor
template <typename T>
Matrix<T>::~Matrix() {
	freeMem();
}

// init dimensions of matrix
/*
With reference to:
https://www.mrericsir.com/blog/technology/c-2d-generic-array-class/
*/
template <typename T>
void Matrix<T>::init() {
	_mat = new T * [_m];
	for (int i = 0;i < _m;i++) {
		_mat[i] = new T[_n];
	}
}
template <typename T>
void Matrix<T>::freeMem() {
	for (int i = 0;i < _m;i++) {
		delete[] _mat[i];
	}
	delete[] _mat;
}

// print methods
template <typename T>
void Matrix<T>::print() {
	for (int i = 0;i < _m;i++) {
		// create the inner bracket
		cout << "[";
		for (int j = 0; j < _n; j++) {
			cout << _mat[i][j];
			if (j != _n - 1) {
				cout << ",";
			}
		}
		cout << "]";
		if (i != _m - 1) {
			cout << endl;
		}
	}
}

/*
Matrix methods.
*/

template <typename T>
void Matrix<T>::setZeroes() {
	for (int i = 0; i < _m;i++) {
		for (int j = 0; j < _n;j++) {
			_mat[i][j] = 0;
		}
	}
}

// indexing methods
template <typename T>
T Matrix<T>::getAtIndex(const int& row, const int& col) {
	return _mat[row][col];
}

template <typename T>
void Matrix<T>::setAtIndex(const T& t,const int& row, const int& col) {
	_mat[row][col] = t;
}




/*
Setters Getters
*/
template <typename T>
void Matrix<T>::setM(int anInt) {
	_m = anInt;
}

template <typename T>
int Matrix<T>::getM() {
	return _m;
}

template <typename T>
void Matrix<T>::setN(int anInt) {
	_n = anInt;
}

template <typename T>
int Matrix<T>::getN() {
	return _n;
}

