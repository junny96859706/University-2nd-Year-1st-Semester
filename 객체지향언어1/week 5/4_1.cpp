#include <iostream>
using namespace std;

class Circle {
	int radius;
public:
	Circle() { radius = 1; }
	Circle(int r) {radius = r;}
	double getArea();
};

double Circle::getArea() {
	return 3.14 * radius * radius;
}

int main() {
	Circle donut; //dount 이름의 Circle타입객체
	Circle pizza(30); //반지름30짜리 객체 생성
	
	cout << "넓이는" << donut.getArea() << endl;
	
	Circle* p; //변수선언문:p라는변수, p변수에 저장되는 값은 Circle 객체의 주소
	p = &donut;
	cout << "넓이는" << p->getArea() << endl;
	cout << (*p).getArea() << endl;

	p = &pizza;
	cout << "넓이는" << p->getArea() << endl;
	cout << (*p).getArea() << endl;
}