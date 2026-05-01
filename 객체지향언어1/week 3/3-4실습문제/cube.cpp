#include <iostream>
using namespace std;

class Cube {
	int width, length, height;
	int area;
public:
	Cube(int width,int length,int height);
	void increase(int width, int length, int height);
	int getVolume();
	bool isZero();
};

Cube::Cube(int width, int length, int height) {
	this->width = width;
	this->length = length;
	this->height = height;
}

int Cube::getVolume() {
	area = width * length * height;
	return area;
}

void Cube::increase(int width, int length, int height) {
	this->width += width;
	this->length += length;
	this->height += height;
}

bool Cube::isZero() {
	if (area == 0)
		return true;
	else
		return false;
}



int main() {
	Cube cube(1, 2, 3);
	cout << "큐브의 부피는" << cube.getVolume() << endl;
	cube.increase(1, 2, 3);
	cout << "큐브의 부피는" << cube.getVolume() << endl;
	if (cube.isZero())
		cout << "큐브의 부피는 0" << endl;
	else
		cout << "큐브의 부피는 0이 아님" << endl;
}