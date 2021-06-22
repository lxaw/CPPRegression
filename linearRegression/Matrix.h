#pragma once

using namespace::std;

template <class T>
class Matrix
	/*
	Represents a 2 Dimensional matrix.
	Note 2 dimensions: the regression that will be performed is for 2 variables.
	*/
{
public:
	// constructor / destructor
	Matrix(int m, int n);
	~Matrix();

	void print();

	/*
	Matrix methods.
	*/
	void setZeroes();

	/*
	Matrix operations. I tried out operator overloading here.
	https://www.quantstart.com/articles/Matrix-Classes-in-C-The-Header-File/
	is a big help.

	Note these functions RETURN matrices.
	*/
	
	// add
	Matrix<T> operator+(const Matrix<T>& aMatrix);
	// sub
	Matrix<T> operator-(const Matrix<T>& aMatrix);
	// dot prod
	Matrix<T> operator*(const Matrix<T>& aMatrix);
	// transpose
	Matrix<T> transpose();

	/*
	NOTE: In Gilbert Strang's Book, matrix indexing is
	done "row,col"
	*/
	T getAtIndex(const int& row, const int& col);
	void setAtIndex(const T& t, const int& row, const int& col);

	// getters setters
	
	void setM(int m);
	int getM();
	void setN(int n);
	int getN();

	
private:
	int _m; // col size
	int _n; // row size

	// dynamic allocation
	T** _mat;



	/*
	Private methods
	*/
	// initialize matrix size, allocate the mem
	void init();
	// free memory
	void freeMem();
	
};

