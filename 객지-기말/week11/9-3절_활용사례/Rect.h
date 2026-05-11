#ifndef RECT_H
#define RECT_H

#include "Shape.h"

class Rect : public Shape {
protected:
	void draw();
public:
	~Rect() {
		cout << "~Rect" << endl;
	}
};

#endif
