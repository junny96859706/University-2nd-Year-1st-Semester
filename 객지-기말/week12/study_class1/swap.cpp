#include <iostream>
#include <string>
using namespace std;

template <class T>
void myswap(T& a, T& b) { //교수님은 이렇게 표현하신다!(엔터키는 상관X)
	T temp;
	temp = a;
	a = b;
	b = temp;
}

int main() {
	int a = 4, b = 5;
	myswap(a, b);
	cout << a << "," << b << endl;

	double c = 0.3, d = 12.5;
	myswap(c, d);
	cout << c << "," << d << endl;

	string x = "hello", y = "yoo";
	myswap(x, y);
	cout << x << "," << y << endl;
}