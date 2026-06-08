#include <iostream>
using namespace std;

template <class T>
void swap_func(T &x,T &y) {
	T temp;
	
	temp = x;
	x = y;
	y = temp;
}

int main() {
	int a, b;
	double c, d;
	char x, y;

	a = 10;
	b = 20;
	cout << "a= " << a << ", b= " << b << endl;
	swap_func(a, b);
	cout << "a= " << a << ", b= " << b << endl;

	c = 10.5;
	d = 20.4;
	cout << "c= " << a << ", d= " << b << endl;
	swap_func(c, d);
	cout << "c= " << a << ", d= " << b << endl;

	x = 'K';
	y = 'k';
	cout << "x= " << a << ", y= " << b << endl;
	swap_func(x, y);
	cout << "x= " << a << ", y= " << b << endl;
}