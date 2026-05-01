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
	Circle circles[2][3] = { {Circle(1), Circle(2), Circle(3)},
						     {Circle(4), Circle(5), Circle()} };
	for (int i = 0; i < 2; i++) {
		for (int j = 0; j < 3; j++) {
			cout << "Circle[" << i << "][" << j << "]의 면적은 ";
			cout << circles[i][j].getArea() << endl;
		}
	} 
}