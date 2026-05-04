#include <iostream>
using namespace std;

class Power {
	int kick;
	int punch;
public:
	Power(int kick = 0, int punch = 0) { this->kick = kick; this->punch = punch; }
	void show();
	//Power operator +(Power op2);
	Power operator +(int op2);
	bool operator==(Power op2);
	Power& operator+=(Power op2);
	Power& operator ++(); //전위
	bool operator !();
	//Power operator ++(int x); 
	//후위(전위연산자와 구분하기위해 매개변수 사용)
	friend Power operator +(int op1, Power op2);
	friend Power operator +(Power op1, Power op2);
	friend Power operator++(Power& op1, int op2);

	Power& operator << (int op2);
};

Power& Power::operator <<(int op2) {
	kick += op2;
	punch += op2;

	return *this;
}

/*
Power Power::operator++(int x) {//후위
//참조리턴은 쓰면안된다!!!->tmp가 사라지기때문에 원본을 가르키면 안된다.
	Power tmp = *this;
	kick++;
	punch++;
	return tmp;
} */

bool Power::operator!() {
	if (kick == 0 && punch == 0) return true;
	else return false;
}

Power& Power::operator++() { //전위
	kick++;
	punch++;
	return *this;
}

Power& Power::operator+=(Power op2) {
	kick = kick + op2.kick; //kick += op2.kick;
	punch = punch + op2.punch;

	return *this;
}

bool Power::operator==(Power op2) {
	if (kick == op2.kick && punch == op2.punch) return true;
	else return false;
}

Power Power::operator+(int op2) {
	Power tmp;

	tmp.kick = kick + op2;
	tmp.punch += punch + op2;

	return tmp;
}

/*Power Power::operator+(Power op2) {
	Power tmp;
	tmp.kick = kick + op2.kick;
	tmp.punch = punch + op2.punch;

	return tmp;
}*/

void Power::show() {
	cout << "kick=" << kick << ',' << "punch" << punch << endl;
}

Power operator +(Power op1, Power op2) {
	Power tmp;

	tmp.kick = op1.kick + op2.kick;
	tmp.punch = op1.punch + op2.punch;

	return tmp;
}

Power operator +(int op1, Power op2) {
	Power tmp;
	tmp.kick = op1 + op2.kick;
	tmp.punch = op1 + op2.punch;

	return tmp;
}

Power operator++(Power& op1, int op2) {
	Power tmp = op1;
	op1.kick++;
	op1.punch++;
	return tmp;
}

int main() {
	Power a(4,6), b(-4, -6), c(1,1);

	a << 3 << 5 << 6; //a.<<(3);
	a.show();
	//cout << 3 << 4 << 6; //cout.<<(3)

	//b = a++; //a.++(0) --> ++(a,0)후위연산자
	//a.show();
	//b.show();

	//b = 2 + a; //2.+(a); 안된다!!! ==> +(2,a)로 해석
	//a.show();
	//b.show();

	/*c = a + b; //+연산자를  Powor의 멤버가 아니고, 외부함수로 작성
	// +(a,b);
	// a.(b) 현재 이 연산자 주석 처리
	a.show();
	b.show();
	c.show();  */

	//c = a++; //후위연산자 a.++(0);
	//a.show();
	//c.show();

	//c = ++++a; // a.++();
	//a.show();
	//c.show();

	// a.!();
	if (!(a+b)) cout << "파워없음" << endl;
	else cout << "파워있음" << endl;

	//b = a + 2; //a.+(2);
	//a.show();
	//b.show();
	//c = a + b; // a.+(b); <--이렇게 바꾼다는것이 중요하다!!

	// a.==(b); <--컴파일러가 이렇게 변경한다!
	//if (a == b) cout << "두 파워가 같다" << endl;
	//else cout << "두 파워가 같지 않다." << endl;
	
	//c = (a += b); //a.+=(b);  // (a += b) += c += d;같은 문법도 가능하다.
	//(a += b) += c;
	

	
	
}