#include <iostream>
using namespace std;

class Circle {
	int radius;
public:
	Circle() { radius = 1; cout << "생성자호출 " << radius << endl; }
	Circle(int r) { radius = r; cout << "생성자호출 " << radius << endl;
	}
	~Circle() { cout << "소멸자호출 " << radius << endl; }
	void setRadius(int r) { radius = r; }
	double getArea();
};

double Circle::getArea() {
	return 3.14 * radius * radius;
}

int main() {
	int n[10]; //정수10개로 이루러진 배열생성, 배열의 이름은 n
	n[0] = 5;

	Circle circleArray[3] = { Circle(10),Circle(20),Circle() };
	//배열의 이름은 circleArrayek, Circle 객체 3개
	//Circle()생성자호출, 각객체마다.
	/*circleArray[0].setRadius(10);
	circleArray[1].setRadius(20);
	circleArray[2].setRadius(30); */

	for (int i = 0; i < 3; i++)
		cout << circleArray[i].getArea() << endl;

	Circle* p;
	p = circleArray;  //배열의 이름은 곹,배열의 시작주소
	for (int i = 0; i < 3; i++) {
		cout << p->getArea() << endl;
		p++;
	}
}