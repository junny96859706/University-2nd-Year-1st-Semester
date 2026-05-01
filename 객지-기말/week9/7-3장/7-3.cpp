#include <iostream>
using namespace std;

class Power {
	int kick;
	int punch;
public:
	Power(int kick = 0, int punch = 0) { this->kick = kick; this->punch = punch; }
	void show();
	Power operator +(Power op2);
	Power operator +(int op2);
	bool operator==(Power op2);
	Power& operator+=(Power op2);
};

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

Power Power::operator+(Power op2) {
	Power tmp;
	tmp.kick = kick + op2.kick;
	tmp.punch = punch + op2.punch;

	return tmp;
}

void Power::show() {
	cout << "kick=" << kick << ',' << "punch" << punch << endl;
}

int main() {
	Power a(4, 6), b(4, 6), c(1,1);
	b = a + 2; //a.+(2);
	a.show();
	b.show();
	//c = a + b; // a.+(b); <--이렇게 바꾼다는것이 중요하다!!

	// a.==(b); <--컴파일러가 이렇게 변경한다!
	//if (a == b) cout << "두 파워가 같다" << endl;
	//else cout << "두 파워가 같지 않다." << endl;
	
	//c = (a += b); //a.+=(b);  // (a += b) += c += d;같은 문법도 가능하다.
	(a += b) += c;
	

	
	
}