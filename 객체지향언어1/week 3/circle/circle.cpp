#include <iostream>
using namespace std;

//선언부
class circle { 
	int radius; //radius는 private로 설정된다!!!!!!
public: //멤버함수를 함수로 바꾸는것은 좋지않은 코딩방식이다.
	double getarea();
	int getradius();
	circle(); //생성자선언.
	circle(int n); //생성자2 선언
	~circle();//소멸자 선언
};

//구현부
circle::~circle() {
	cout << radius << "의원이 소멸됨.." << endl;
}

circle::circle() { //생성자구현
	radius =1;
	cout << "생성자 실행.." << endl;
}

circle::circle(int n) {
	radius = n;
	cout << "생성자 실행.." << endl;
}

double circle::getarea() {
	return 3.14 * radius * radius;
}

int circle::getradius() { //::은 범위지정연산자이다.
	return radius;
}

//메인함수
int main() {
	circle donut; //반지름이 1인 원생성, circle()생성자 불러짐
	double area = donut.getarea();
	cout << "도넛의 면적은" << area << "입니다" << endl;

	circle pizza(30); //circle(30)
	cout << "피자의 면적은" << pizza.getarea() << "입니다" << endl;
}