#include "Matrix.cpp"
#include "Point.cpp"

#include <vector>
#include <iostream>
using namespace::std;

#pragma once
class Backend
	/*
	Groups the methods for finding the line of best fit.
	*/
{
	public:
		Backend();

		void init();

	private:

		int _degReg = 0;
		vector<Matrix<double>> _matsVec;
		Matrix<double> _A;
		Matrix<double> _b;
		Matrix<double> _coefMat;

		vector<Point<double>> _pointVec;

		void promptUserDegReg();
		void promptUserPoints();
		void setMatrices();

		void printPoints();
};

