#include <iostream>
#include <random>
// user classes
#include "Matrix.h"


using namespace::std;

// Constructor
template <typename T>
Matrix<T>::Matrix(int m, int n) {
	_mat = NULL;
	_m = m;
	_n = n;
	
	// initiate the dimensions, set zeros for default;
	init();
	setZeroes();
}
// copy constructor
template <typename T>
Matrix<T>::Matrix(const Matrix& m1){
	_m = m1.getM();
	_n = m1.getN();

	// initiate, set zeros
	init();
	for (int i = 0;i < _m;i++) {
		for (int j = 0;j < _n;j++) {
			_mat[i][j] = m1.getAtIndex(i, j);
		}
	}
}
// destructor
template <typename T>
Matrix<T>::~Matrix() {
	if (NULL == _mat) {
		return;
	}
	for (int i = 0;i < _n;i++) {
		delete[] _mat[i];
	}
	delete[] _mat;

	_n = 0;
	_m = 0;
	_mat = NULL;
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
	cout << endl;
}

/*
Matrix methods.
*/

template <typename T>
Matrix<T> Matrix<T>::transpose() {
	// only need to loop 1 less than the amount of columns
	// note: transpose switches the dim of the columns and the rows
	// if _m = _n, no worries
	Matrix<T> res(_n,_m);
	for (int i = 0;i < _m; i++) {
		for (int j = 0;j < _n;j++) {
			res.setAtIndex(_mat[i][j], j, i);
		}
	}
	return res;
}


// setting zero matrix or identity
template <typename T>
void Matrix<T>::setZeroes() {
	for (int i = 0; i < _m;i++) {
		for (int j = 0; j < _n;j++) {
			_mat[i][j] = 0;
		}
	}
}

template <typename T>
void Matrix<T>::setIdentity() {
	for (int i = 0;i < _m;i++) {
		for (int j = 0;j < _n;j++) {
			if (i == j) {
				// diagonal
				_mat[i][j] = 1;
			}
			else {
				_mat[i][j] = 0;
			}
		}
	}
}

template <typename T>
void Matrix<T>::setRandomInt() {
	random_device rd;
	mt19937 rng(rd());
	uniform_int_distribution<int> uni(0, 9);
	for (int i = 0;i < _m;i++) {
		for (int j = 0;j < _n;j++) {
			_mat[i][j] = uni(rng);
		}
	}
}

// indexing methods
template <typename T>
T Matrix<T>::getAtIndex(const int& row, const int& col) const{
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
int Matrix<T>::getM() const{
	return _m;
}

template <typename T>
void Matrix<T>::setN(int anInt) {
	_n = anInt;
}

template <typename T>
int Matrix<T>::getN() const{
	return _n;
}
/*
Matrix operators
*/

// copy assignment operator
template <typename T>
Matrix<T>& Matrix<T>::operator = (const Matrix<T>& aMatrix) {
	/*
	Look into copy swap
	*/
	cout << "assignment operator" << endl;
	return *this;
}

template <typename T>
Matrix<T> Matrix<T>::operator+(const Matrix<T>& aMatrix) {
	Matrix<T> res(_m, _n);
	for (int i = 0;i < _m;i++) {
		for (int j = 0;j < _n;j++) {
			T val = getAtIndex(i, j) + aMatrix.getAtIndex(i, j);
			res.setAtIndex(val, i, j);
		}
	}
	return res;
}

template <typename T>
Matrix<T> Matrix<T>::operator-(const Matrix<T>& aMatrix){
	Matrix<T> res(_m, _n);
	for (int i = 0;i < _m;i++) {
		for (int j = 0;j < _n;j++) {
			T val = getAtIndex(i, j) - aMatrix.getAtIndex(i, j);
			res.setAtIndex(val, i, j);
		}
	}
	return res;
}
