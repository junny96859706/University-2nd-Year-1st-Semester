#include <iostream>
using namespace std;

class Circle {
	int radius;
public:
	Circle(int radius) { this->radius = radius; }
	Circle& plus(int n);
	int getRadius() { return radius; }
};

Circle& Circle::plus(int n) {
	radius += n;
	return *this;
}

int main() {
	Circle a(5);
	a.plus(10).plus(5).plus(200);
	cout << a.getRadius() << endl;

	string x("hello");
	x.append("kitae").append("!");
	cout << x;
}