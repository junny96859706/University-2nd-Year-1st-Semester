#ifndef SHAPE_H
#define SHAPE_H

class Shape {
	Shape* next; //next는 Shape을 상속받은 객체를 가리킴
protected:
	virtual void draw();
public:
	virtual ~Shape() {
		cout << "shape소멸" << endl;
	}
	Shape() { next = NULL; }
	Shape* add(Shape* p);
	void paint();
	Shape* getNext() {
		return next;
	}

};

#endif