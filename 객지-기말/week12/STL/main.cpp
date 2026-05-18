#include <iostream>
using namespace std;
//템플릿 장점: 함수코드의 재사용, 높은 소프트웨어의 생산성과 유용성
//템플릿 단점: 1.포팅에 취약 - 컴파일러에 따라 지원하지 않을 수 있음.
//			   2.컴파일 오류 메시지 빈약, 디버깅에 많은 어려움
 

//template <typename T>로 써도 된다!!!!
template <class T> void myswap(T& a, T& b) { //템플릿 함수, 제네릭 함수
	T tmp;
	tmp = a;
	a = b;
	b = tmp;
}
//컴파일러에서 구체화(specialization)을 통해 템플릿함수로부터 구체화된 함수의 소스코드가 생성됨.
//구체화 오류: 제네릭 타입에 구체적인 타입 지정시 주의!!

class Circle {
	int radius;
public:
	Circle(int radius = 1) { this->radius = radius; }
	int getRadius() { return radius; }

};

int main() {
	int a = 4, b = 5;
	
	myswap(a, b);
	cout << a << "," << b << endl;

	double c = 0.3, d = 12.5;
	myswap(c, d);
	cout << c << "," << d << endl;

	Circle donut(5), pizza(20);
	cout << donut.getRadius() << "," << pizza.getRadius() << endl;
	myswap(donut, pizza); //T가 Circle로 바꿔는 구체화 과정!!!->복사가 정상적으로 이루어진다. 
	cout << donut.getRadius() << "," << pizza.getRadius() << endl;
}