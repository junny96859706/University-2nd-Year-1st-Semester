#include <iostream>
using namespace std;
//예제9-1:파생클래스에서 함수를 재정의하는 사례

class Base {
public:
	void f() { cout << "Base::f()called" << endl; }
};

class Derived : public Base {
public:
	void f() { cout << "Derived::f() called" << endl; } //같은함수 생성도 가능한 얘기다!!!! 
};


int main() {
	
	Derived d;
	Derived* pDer;
	pDer = &d;
	pDer->f(); //자식클래스의 f함수 호출
	// pDer->Base::f();라고 한다면 부모클래스 f()함수가 실행된다!

	Base* pBase;
	pBase = pDer; //업캐스팅(자식 클래스의 객체를 부모 클래스의 포인터로 가리키는 것)
	pBase->f(); //부모클래스의 f함수호출
} 