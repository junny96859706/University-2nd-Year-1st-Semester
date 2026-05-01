#include <iostream>
using namespace std;

class Circle {
	int radius;
public:
	Circle() { radius = 1; }
	Circle(int r) { radius = r; }
	double getArea();
};

double Circle::getArea() {
	return 3.14 * radius * radius;
}

void print(Circle* p) {
	cout << p->getArea() << endl;
}

int main() {
	Circle circles[3] = { Circle(1),Circle(5),Circle() };
	for (int i = 0; i < 3; i++) {
		cout << circles[i].getArea() << "\t"; //\t는 탭이다!!!
	}

	Circle* p = circles; //&circles[0]과 같다!!
	for (int i = 0; i < 3; i++) {
		cout << p->getArea() << "\t"; //\t는 탭이다!!!
		p++;
	}
}

void main1() {
	Circle donut,pizza(30);
	Circle* p;
	p = &donut;
	cout << donut.getArea() << ',' << p->getArea() << endl;
	cout << (*p).getArea() << (&donut)->getArea() << endl;
	print(&donut);
	print(&pizza);
}