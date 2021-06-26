#include "Backend.h"


void Backend::init() {
	promptUserDegreeRegression();
}

void Backend::promptUserDegreeRegression() {
	cout << "What is the degree to which you want to perform regression?\nie: constant is 0, linear 1, quadratic 2...\n";
	cin >> _degReg;
	cout << "We will perform regression to " << _degReg << " degrees.\n";
}
