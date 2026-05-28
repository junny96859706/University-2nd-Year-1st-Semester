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

	Coffee& operator +=(const Coffee& p);
	Coffee& operator +=(int n);
	friend Coffee operator++(Coffee& p, int);
};

//C++에서는 원본을 수정하지 않는 참조 매개변수에는 const를 붙여주는 것이 객체지향 프로그래밍의 정석(가이드라인).
// const를 안 붙이면 black += Coffee(1, 2); 처럼 임시 객체를 더할 때 컴파일 에러가 날 수 있음.
Coffee& Coffee::operator+=(const Coffee& p) {
	this-> water += p.water;
	this->espresso += p.espresso;
	this->sugar += p.sugar;
	this->cream += p.cream;

	return *this;
}

Coffee& Coffee::operator +=(int n) {
	this->espresso += n;
	return *this;
}

// 전위 연산자와 구분하기 위해 맨 뒤에 의미 없는 'int'를 적어주는 규칙!
//후위 연산자이므로 '증가 전 값'을 반환해야한다!!!
Coffee operator++(Coffee& p, int) {
	Coffee temp = p; // ① [백업]후위연산자이므로 값이 증가하기 전의 상태를 먼저 복사
	++p.espresso; //원본 객체(p)의 샷을 진짜로 1 증가시킨다.
	return temp; //아까 백업해둔 " 객체(temp)"를 최종 반환
}


int main() {
	Coffee black(2, 5, 0, 0), dabang(2, 2, 2, 2);
	black += dabang; //black.+=(dabang);
	black += 1; //black커피에 에스프레소 1샷 추가
	black++; //black커피에 다시 에스프레소 1샷 추가 //++(blank
	black.show();
}