#include <iostream>
using namespace std;

class Point {
protected://protected접근지정자
	int x, y; //점의 좌표
public:
	Point(int x, int y) {
		this->x = x;
		this->y = y;
		cout << "point생성자" << x << ' ' << y <<  endl;
	}
	void showPoint() { cout << "(" << x << "," << y << ")" << endl; }
};

class ColorPoint : public Point { //Point클래스 상속. 파생클래스
	string color;
public:
	ColorPoint(string color, int x, int y) : Point(x, y) {
		this->color = color;
		cout << "ColorPoint생성자" << endl;
	}
	void showColorPoint();
};

void ColorPoint::showColorPoint() {
	//showPoint();
	cout << color << x << ' ' << y << endl;
}

int main() {
	ColorPoint cp("red",5,6);
	cp.showColorPoint();

}