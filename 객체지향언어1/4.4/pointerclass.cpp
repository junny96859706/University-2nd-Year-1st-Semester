#include <iostream>
using namespace std;

class Circle {
	int radius;
public:
	Circle() { radius = 1; cout << "생성자호출 " << radius << endl; }
	Circle(int r) {
		radius = r; cout << "생성자호출 " << radius << endl;
	}
	~Circle() { cout << "소멸자호출 " << radius << endl; }
	void setRadius(int r) { radius = r; }
	double getArea();
};

double Circle::getArea() {
	return 3.14 * radius * radius;
}

int main() {
	Circle* p = new Circle[3]; //Circle() 생성자 실행
	p[0].setRadius(10);
	p[1].setRadius(20);
	p[2].setRadius(30);

	for (int i = 0; i < 3; i++) {
		cout << p[i].getArea() << endl;
	}

	Circle* a = p;
	for (int i = 0; i < 3; i++) {
		cout << a->getArea() << endl;
		a++;
	}

	a = p;
	for (int i = 0; i < 3; i++) {
		cout << (a+i)->getArea() << endl;
	}

	a = p;
	for (int i = 0; i < 3; i++) {
		cout << (*(a + i)).getArea() << endl;
	}

	delete[] p;
}