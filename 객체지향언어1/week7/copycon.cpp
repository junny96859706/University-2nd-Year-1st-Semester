#include <iostream>
using namespace std;

//복사생성자?:객체의 복사생성시 호출되는 특별한 생성자
//한클래스에 오직 한개만 선언 가능
//보통생성자와 클래스내에 중복 선언 가능
class Circle {
private:
	int radius;
public:
	Circle(const Circle& src);
	Circle() { radius = 1; }
	Circle(int radius) { 
		this->radius = radius; 
	}
	int getRadius() { return radius; }
	double getArea() { return 3.14 * radius * radius; }

	//디폴트 복사생성자가 컴파일러에 의해 삽입되지 않는다.
	//디폴트 복사생성자를 쓰면 안된다!!!!(얉은 복사이기 때문이다)
};

Circle::Circle(const Circle& src) {
	this->radius = src.radius;
	cout << "복사생성자 실행 radius =" << radius << endl;
}

int main() {
	Circle src(30); //반지름이 30인 객체
	//Circle dest(src); //복사생성
	Circle dest = src; //dest(src),dest객체의 복사 생성자 호출

	//dest = src; //복사생성자 불리지 않는다. 단순 복사

	cout << "원본의 면적" << src.getArea() << endl;
	cout << "사본의 면적" << dest.getArea() << endl;
}