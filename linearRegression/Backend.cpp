#include "Backend.h"

#include <math.h>
#include <string>
#include <iostream>

using namespace::std;
// constructor
Backend::Backend() {
	init();
}


void Backend::init() {
	promptUserDegReg();
	promptUserPoints();
	printPoints();
	setMatrices();
}

void Backend::setMatrices() {
	// set up the matrix A depending on degree of regression
	// set up matrix B based sonly on y values
	// note: m for A is determined soley by number of points
	// note: n for A depends on degree of reg
	int m = _pointVec.size();
	int n = _degReg + 1;

	Matrix<double> matA(m, n);
	Matrix<double> matB(m, 1);

	// fill constants first
	for (int row = 0;row < m;row++) {
		double xVal = _pointVec[row].getX();
		double yVal = _pointVec[row].getY();
		for (int col = 0;col < n;col++) {
			if (col == 0) {
				// fill ones
				matA.setAtIndex(1, row, col);
			}
			// now set the points
			else {
				matA.setAtIndex(pow(xVal,col), row, col);
			}
		}
		// populate the b vector
		matB.setAtIndex(yVal, row, 0);
	}

	Matrix<double> matATA = matA.transpose() * matA;
	Matrix<double> matATB = matA.transpose() * matB;
	Matrix<double> matCoeff = (matATA.inverse()) * matATB;

	cout << "ATA:" << "\n";
	matATA.print();
	cout << "ATb:" << "\n";
	matATB.print();

	cout << "Regression coefficients:" << "\n";
	matCoeff.print();
}

void Backend::promptUserDegReg(){
	cout << "What is the degree to which you want to perform regression?\nie: constant is 0, linear 1, quadratic 2...\n";
	cin >> _degReg;
	cout << "We will perform regression to " << _degReg << " degrees.\n";
}
Point<double> getPoint(string aStr) {
	Point<double> p;
	string delim = ",";
	size_t pos = 0;
	string tok;
	int count = 0;
	while ((pos = aStr.find(delim)) != string::npos) {
		tok = aStr.substr(0, pos);
		double val = stod(tok);
		p.setX(val);
		aStr.erase(0, pos + delim.length());
	}
	double val = stod(aStr);
	p.setY(val);

	return p;
}

void Backend::promptUserPoints() {
	bool running = true;
	string delim = ",";
	while (running) {
		cout << "Enter point \"x,y\" or \"q\" to stop." << "\n";
		string ui;
		cin >> ui;
		if (ui == "q") {
			running = false;
			break;
		}
		Point<double> p = getPoint(ui);
		_pointVec.push_back(p);
	}
	cout << "You have entered: " << _pointVec.size() << " points.\n";
}

void Backend::printPoints() {
	cout << "Here are all of the points you entered." << "\n";
	for (auto p : _pointVec) {
		p.print();
	}
}
