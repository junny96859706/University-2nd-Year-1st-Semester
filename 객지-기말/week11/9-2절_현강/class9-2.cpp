#include <iostream>
using namespace std;

class Shape { //추상클래스
	Shape* next;
protected:
	virtual void draw() = 0; //순수 가상 함수 선언
public:
	Shape() { next = NULL; }
	void paint() {
		draw();
	}
	Shape* add(Shape* p) {
		next = p;
		return p;
	}
	Shape* getNext(){ return next; }
};

class Line : public Shape {
protected:
	virtual void draw() { cout << "Line" << endl; }
};

class Rect : public Shape {
protected:
	virtual void draw() { cout << "Rect" << endl; }
};

class Circle : public Shape {
protected:
	virtual void draw() { cout << "Circle" << endl; }
};

void drawAll(Shape* p) {
	while (p != NULL) {
		p->paint();
		p = p->getNext();
	}
}

int main() {
	Shape* pstart = NULL;
	Shape* pLast = NULL;

	pstart = new Circle();
	pLast = pstart;

	pLast = pLast->add(new Rect());
	pLast = pLast->add(new Line());
	pLast = pLast->add(new Circle());

	drawAll(pstart);
}