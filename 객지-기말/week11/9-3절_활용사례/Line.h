#ifndef LINE_H
#define LINE_H

#include "Shape.h"

class Line : public Shape {
protected:
	void draw(); //오버라이딩
public:
	~Line() {
		cout << "~Line" << endl;
	}
};

#endif