#include <iostream>
using namespace std;

class Oval {
	int width = 0, height = 0;
public:
	Oval() {
		this->width = 1;
		this->height = 1;
	}
	Oval(int width, int height) { 
		this->width = width;
		this->height = height;
	}
	~Oval();
	void set(int width, int height) {
		this->width = width;
		this->height = height;
	}
	void show();
	int getWidth();
	int getHeight();
	double area();
};

Oval::~Oval() {
	cout << "Oval 소멸:" << width << "x" << height << endl;
}

void Oval::show() {
	cout << "Oval:width=" << width << ", height=" << height << endl;
}

double Oval::area() {
	return (width/2.0)*(height/2.0) * 3.14;
}

int Oval::getWidth() {
	return width;
}

int Oval::getHeight() {
	return height;
}

int main() {
	Oval kitae, jane(10, 15);
	kitae.set(3, 4);
	kitae.show();
	cout << jane.getWidth() << "x" << jane.getHeight() << ",면적" << jane.area() << endl;
}