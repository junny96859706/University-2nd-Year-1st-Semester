#include <iostream>
using namespace std;

#include "shape.h"

void Shape::draw() {
	cout << "--Shape --" << endl;
}

void Shape::paint() {
	draw(); //동적바인딩 되는 함수 호출
}

Shape* Shape::add(Shape* p) {
	next = p;
	return p;
}