#include <iostream>
using namespace std;

class Exp {
	int base; //지수 표현의 베이스 값
	int exp; //지수 표현의 지수 값
public:
	Exp(int base = 1, int exp = 1);
	int calcValue();
	friend istream& operator>>(istream& in, Exp& p);
	friend ostream& operator<<(ostream& out, Exp& p);
};

Exp::Exp(int base, int exp) {
	this->base = base;
	this->exp = exp;
}

int Exp::calcValue() {
	int temp = 1;
	for (int i = 0; i < exp; i++) {
		temp = temp * base;
	}
	return temp;
}

istream& operator>>(istream& in, Exp& p) {
	cout << "베이스:";
	in >> p.base;
	cout << "지수:";
	in >> p.exp;
	return in;
}

ostream& operator<<(ostream& out, Exp& p) {
	out << p.base << "의" << p.exp << "승: " << p.calcValue();
	return out;
}

int main() {
	Exp a, b;
	cin >> a >> b; //지수를 나타내는 두 객체 입력
	cout << a << endl << b << endl; //지수를 나타내는 두 객체 출력
}