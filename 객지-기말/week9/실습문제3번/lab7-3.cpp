#include <iostream>
using namespace std;

class Coffee {
	int water, espresso, sugar, cream;
public:
	Coffee(int water = 1, int coffee = 1, int sugar = 0, int cream = 0) {
		this->water = water;
		this->espresso = coffee;
		this->sugar = sugar;
		this->cream = cream;
	}
	void show() {
		cout << "물" << water << ", 커피" << espresso;
		cout << ", 설탕" << sugar << ", 크림" << cream << endl;
	}
	//실습문제3번
	bool operator!();
	friend bool operator >(const Coffee& a,const Coffee& b);
	//실습문제4번
	Coffee& operator <<(Coffee& p);
	friend Coffee& operator <<(Coffee& p, int n);
};

bool Coffee::operator!() {
	if (this->sugar == 0)
		return true;
	else
		return false;
}

//💡비교 연산자는 양쪽 모두 값을 바꾸지 않으므로 둘 다 const& 로 받는 것이 정석!
bool operator >(const Coffee& a,const Coffee& b) {
	if ((a.water + a.espresso + a.sugar + a.cream) > (b.water + b.espresso + b.sugar + b.cream))
		return true;
	else
		return false;
}

Coffee& Coffee::operator <<(Coffee& p) {
	this->water += p.water;
	this->espresso += p.espresso;
	this->sugar += p.sugar;
	this->cream += p.cream;

	return *this;
}

//연쇄연산을 위해서 참조리턴!!! 참조해서 온 원본p를 다시 리턴하기때문에, return p;해도  상관없다!
Coffee& operator <<(Coffee& p, int n) {
	p.water += 3;
	return p;
}

int main() {
	Coffee a(2, 5, 0, 0), b(2, 2, 2, 2);
	if (!a) //설탕이 없으면 //컴파일러가 해석? a.operator!(); or operator!(a); 
		cout << "No sugar!!" << endl;
	if (a > b) //컴파일러가 operator>(a,b)로 해석
		cout << "커피 a가 양이 더 많아요." << endl;
	else
		cout << "커피 b가 양이 더 많아요." << endl;

	a << b << 3; //커피a에 커피b를 더하고, 물양을 3 더한다. //a.operator<<(b)로 해석, operator<<(a,3)으로 해석
	a.show();
}