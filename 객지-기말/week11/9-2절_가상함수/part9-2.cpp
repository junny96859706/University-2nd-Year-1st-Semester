#include <iostream>
using namespace std;
//9-2장:가상함수:virtual키워드로 선언된 멤버함수 + 가상소멸자
//virtual키워드의 의미:동적바인딩 지시어
// 컴파일러에서 함수에 대한 호출바인딩을 실행시간까지 미루도록 지시

class Base {
public:
	void g(){ }
	virtual void f() { cout << "Base::f()called" << endl; }
	virtual ~Base() { cout << "~Base()" << endl; }
};

class Derived : public Base {
public:
	//가상함수는 동적바인딩을 통해 보장한다!!!!
	//오버라이딩의 목적:파생클래스에서 구현할 함수 인터페이스제공(파생클래스의 다형성)
	virtual void f() { cout << "Derived::f() called" << endl; }//함수 오버라이딩(덮어쓰기)
	~Derived() { cout << "~Derived()" << endl; }
};


int main() {

	Derived* p = new Derived();
	// ...
	// ...
	Base* q = p; //업캐스팅
	// ...
	// ..
	q->f();
	delete q; //~Base()호출
}