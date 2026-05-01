#include <iostream>
using namespace std;

class circle { //클래스 선언부생성
public:
	int radius;
	double getarea();
};

double circle::getarea() {//클래스 구현부생성
	return 3.14 * radius * radius;
}


int main() {
	circle dounet;
	dounet.radius = 5;
	double area = dounet.getarea();
	cout << "클래스로 만든 도넛의 넓이는" << area << "입니다" << endl;

}