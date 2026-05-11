#ifndef CIRCLE_H
#define CIRCLE_H

#include "Shape.h"

class Circle : public Shape {
protected:
	void draw(); //오버라이딩
public:
	~Circle() {
		cout << "~Circle" << endl;
	}
};

#endif 
