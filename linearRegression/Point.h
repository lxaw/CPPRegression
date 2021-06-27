
#pragma once

using namespace::std;
template <class T>
class Point
{
public:
	// constructor
	Point(T x, T y);

	T getX();
	T getY();
	void setX(T anX);
	void setY(T aY);
	void print();

private:
	T _arr[2];
};

