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
	// copy constructor
	Matrix(const Matrix& m1);
	~Matrix();

	void print() const;

	/*
	Matrix methods.
	*/
	void setZeroes(); // resets the matrix to the zero matrix
	void setIdentity(); // resets the matrix to the identity matrix
	void setRandomInt(); // resets the matrix to random (0-9) values for testing
	/*
	Matrix operations. I tried out operator overloading here.
	https://www.quantstart.com/articles/Matrix-Classes-in-C-The-Header-File/
	is a big help.

	Note these functions RETURN matrices.
	*/
	
	// copy assignment operator
	Matrix<T>& operator = (const Matrix<T>& m);
	
	// add
	Matrix<T> operator+(const Matrix<T>& aMatrix);
	// sub
	Matrix<T> operator-(const Matrix<T>& aMatrix);
	// mult
	Matrix<T> operator*(const Matrix<T>& aMatrix);
	// transpose
	Matrix<T> transpose();
	// get inverse of matrix
	Matrix<T> inverse();

	/*
	NOTE: In Gilbert Strang's Book, matrix indexing is
	done "row,col"
	*/
	T getAtIndex(const int& row, const int& col) const;
	void setAtIndex(const T& t, const int& row, const int& col);

	// getters setters
	
	void setM(int m);
	int getM() const;
	void setN(int n);
	int getN() const;

	
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
	
};

