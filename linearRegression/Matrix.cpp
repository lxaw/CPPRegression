#include <iostream>
#include <random>
#include <assert.h>
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
// default constructor
template <typename T>
Matrix<T>::Matrix() {
	_m = _n = 1;
	init();
	setZeroes();
}
template <typename T>
void Matrix<T>::setEqual(const Matrix<T>& aMatrix) {
	_m = aMatrix.getM();
	_n = aMatrix.getN();
	init();
	copyValues(aMatrix);
}

template <typename T>
void Matrix<T>::copyValues(const Matrix<T>& aMatrix) {
	assert(_m == aMatrix.getM() && _n == aMatrix.getN());
	for (int i = 0;i < _m;i++) {
		for (int j = 0;j < _n;j++) {
			T val = aMatrix.getAtIndex(i, j);
			setAtIndex(val, i, j);
		}
	}
}

// copy constructor
template <typename T>
Matrix<T>::Matrix(const Matrix& m1){
	cout << "call copy-const" << endl;
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
	cout << "DESTRUCTOR" << endl;
	if (NULL == _mat) {
		return;
	}
	for (int i = 0;i < _m;i++) {
		delete[] _mat[i];
	}
	delete[] _mat;

	_m = 0;
	_n = 0;
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
void Matrix<T>::print() const{
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

template <typename T>
Matrix<T> Matrix<T>::inverse() {
	// need to be square to have inverse!
	assert(_m == _n);
	// temp_mat is the temporary matrix for calcs
	Matrix<T> temp_mat(_m,2*_n);
	// res is the final result
	Matrix<T> res(_m, _n);
	// perform guass jordan...
	for (int i = 0;i < _m;i++) {
		for (int j = 0;j < temp_mat.getN();j++) {
			if (j < _n) {
				// fill the left side
				temp_mat.setAtIndex(getAtIndex(i, j), i, j);
			}
			else if ((j-_n) == i){
				// fill the right as the identity
				temp_mat.setAtIndex(1, i, j);
			}
		}
	}
	// now we perform elim on both parts
	for (int i = 0;i < _m;i++) {
		for (int j = 0;j < _n;j++) {
			if (j != i) {
				T l = temp_mat.getAtIndex(j, i) / temp_mat.getAtIndex(i, i);
				for (int k = 0; k < temp_mat.getN();k++) {
					T temp = temp_mat.getAtIndex(j, k);
					temp -= temp_mat.getAtIndex(i, k) * l;
					temp_mat.setAtIndex(temp, j, k);
				}
			}
		}
	}
	// now we divide out to get Identity on the left
	for (int i = 0;i < _m;i++) {
		T divisor = temp_mat.getAtIndex(i, i);
		for (int j = 0;j < temp_mat.getN();j++) {
			T temp = temp_mat.getAtIndex(i, j) / divisor;
			temp_mat.setAtIndex(temp, i, j);
			if (j >= _n) {
				res.setAtIndex(temp, i, (j-_n));
			}
		}
	}
	res.print();
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

template <typename T>
Matrix<T> Matrix<T>::operator*(const Matrix<T>& aMatrix) {
	// (m x n) * (n x p) = (m x p)
	// ie: (2x3)*(3x4) = (2x4)

	// need n of m1 = m of n2
	assert(_n == aMatrix.getM());

	int p = aMatrix.getN();
	Matrix<T> res(_m, p);

	
	for (int i = 0;i < _m;i++) {
		// loop through horizontal on m1
		for (int j = 0;j < p;j++) {
			// loop through vertical on m2
			T sum = 0;
			for (int k = 0;k < _n;k++) {
				//cout << i << " " << j << " " << k << "\n";
				T val1 = _mat[i][k];
				T val2 = aMatrix.getAtIndex(k,j);
				T mult = val1 * val2;
				sum += mult;

			}
			res.setAtIndex(sum, i, j);
		}
	}
	
	return res;
}

template <typename T>
Matrix<T> Matrix<T>::join(const Matrix<T>& aMatrix) {
	/*
	This function joins two matrices
	*/
	// need to be same height
	assert(_m == aMatrix.getM());

	int new_cols = _n + aMatrix.getN();

	Matrix<T> res(_m, new_cols);

	// populate the matrix
	for (int i = 0;i < _m;i++) {
		for (int j = 0;j < new_cols;j++) {
			int val;
			if (j < _n) {
				// populate first matrix side
				val = getAtIndex(i, j);
				res.setAtIndex(getAtIndex(i, j), i, j);
			}
			else {
				// populate second matrix side
				int adj_j = j - _n;
				val = aMatrix.getAtIndex(i, adj_j);
				res.setAtIndex(aMatrix.getAtIndex(i, adj_j), i, j);
			}
		}
	}
	
	return res;
}




