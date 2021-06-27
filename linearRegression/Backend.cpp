#include "Backend.h"

#include <string>
#include <iostream>

using namespace::std;
// constructor
Backend::Backend() {
	init();
	promptUserPoints();
}


void Backend::init() {
	promptUserDegReg();

}

void Backend::promptUserDegReg(){
	cout << "What is the degree to which you want to perform regression?\nie: constant is 0, linear 1, quadratic 2...\n";
	cin >> _degReg;
	cout << "We will perform regression to " << _degReg << " degrees.\n";
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
		double x = stod(ui.substr(0, ui.find(delim)));
		double y = stod(ui.substr(0, ui.find(delim)));
		Point<double> p(x, y);
		_pointVec.push_back(p);
	}
	cout << "You have entered: " << _pointVec.size() << " points.";
}
