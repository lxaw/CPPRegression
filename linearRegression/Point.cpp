#include <iostream>
#include "Point.h"

using namespace::std;

// constructor
template <typename T>
Point<T>::Point(T x, T y) {
	setX(x);
	setY(y);
}

template <typename T>
T Point<T>::getX(){
	return _arr[0];
}

template <typename T>
T Point<T>::getY(){
	return _arr[1];
}

template <typename T>
void Point<T>::setX(T anX) {
	_arr[0] = anX;
}

template <typename T>
void Point<T>::setY(T aY) {
	_arr[1] = aY;
}

template <typename T>
void Point<T>::print() {
	cout << "(" << _arr[0] << "," << _arr[1] << ")" << "\n";
}





