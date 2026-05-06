#include <iostream>
using namespace std;

class Point {
	int x, y; //점의 좌표
public:
	void set(int x, int y) { this->x = x; this->y = y; }
	void showPoint() { cout << "(" << x << "," << y << ")" << endl; }
};

class ColorPoint : public Point { //Point클래스 상속. 파생클래스
	string color;
public:
	void setColor(string color) { this->color = color; }
	void showColorPoint();
};

void ColorPoint::showColorPoint() {
	showPoint();
	cout << color << endl;
}

int main() {
	Point p;
	p.set(3, 4);
	p.showPoint();

	ColorPoint cp;
	//cp.x = 5;
	cp.set(4, 5);
	cp.setColor("red");
	cp.showColorPoint();
}