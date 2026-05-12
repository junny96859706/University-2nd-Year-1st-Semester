#include <iostream>
using namespace std;

class Base {
public:
	virtual void draw() {
		cout << "Base::f()" << endl;
	}
};

class Derived : public Base {
public:
	virtual void draw() {	
		cout << "Derived::f()" << endl;
	}
};

int main() {
	Derived d;
	d.draw();

	Derived* p;
	p = &d;
	p->draw();

	Base* q;
	q = &d; //업캐스팅
	q->draw();
}