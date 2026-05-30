#include <iostream>
using namespace std;

class Point {
	int x, y;
public:
	Point(int x, int y) { this->x = x; this->y = y; }
	int getX() { return x; }
	int getY() { return y; }
protected:
	void move(int x, int y) { this->x = x; this->y = y; }
};

class Point3D : public Point {
	int z;
public:
	Point3D(int x, int y, int z) : Point(x, y) { this->z = z; }
	void show() { cout << "(" << getX() << "," << getY() << "," << z << ")" << endl; }
	void upZ() { z++; }
	void left() { //8-4번 문제의 핵심내용!!!!!!
		move(getX() - 1, getY()); // ⭕ 부모의 함수들을 조합해 x값만 1 감소시키기!
	}
	void up() {
		move(getX(), getY() + 1);
	}
	void set(int x, int y, int z) {
		move(x, y);
		this->z = z;
	}
};

int main() {
	Point3D p(1, 2, 3); //1,2,3은 각각 x,y,z 축의 값
	p.show(); //(1,2,3)
	p.upZ(); //z축으로 이동
	p.left(); //x축으로 이동
	p.up(); //y축으로 이동
	p.show(); //(0,3,4)
	p.set(10, 20, 30);
	p.show(); //(10,20,30)
}