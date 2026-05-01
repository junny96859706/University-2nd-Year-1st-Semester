#include <iostream>
using namespace std;

class Circle {
	int radius;
public:
	Circle();
	Circle(int radius);
	~Circle();
	double getArea();
	int getRadius();
	void setRadius(int radius);
};

Circle::~Circle() {
	cout << "소멸자 실행" << radius << endl;
}

Circle::Circle() {
	radius = 1;
	cout << "생성자 실행" << radius << endl;
}
Circle::Circle(int radius) {
	this->radius = radius;
	cout << "생성자 실행" << radius << endl;
}

double Circle::getArea() {
	return 3.14 * radius * radius;
}

int Circle::getRadius() { return radius; }
void Circle::setRadius(int radius) {
	this->radius = radius;
}

void increase(Circle &c) { //c의 생성자,Circle()호출?
	int r = c.getRadius();
	r++;
	c.setRadius(r);
} //c의 소멸자 호출

int main() {
	Circle waffle(30);

	increase(waffle);
	cout << waffle.getRadius() << endl;

}