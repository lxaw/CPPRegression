#include "Matrix.cpp"

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
		Matrix<double> _A;
		Matrix<double> _b;
		Matrix<double> _coefMat;

		// prompts what type of regression (ie: linear, quadratic, etc);
		void promptUserDegreeRegression();

		// prompts user how many points of data they have to regress
		void promptUserPointAmount();

		// ask what point values found 
		void promptPointValues();
		
		// calculates the coefficients of regression
		void calculateCoefficients();
};

