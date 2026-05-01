#include <iostream>
using namespace std;

class Power {
	int punch;
	int kick;
public:
	Power(int punch=0, int kick=0) {
		this->punch = punch;
		this->kick = kick;
	}
	void show();
	Power operator+(Power& b);
	Power operator + (int n);
	bool operator ==(Power b);
	Power& operator +=(Power b);
	bool operator !();
	Power& operator ++(); //전위연산자 //Lvalue가 될수있기때문에 참조리턴한다!!
	Power operator++(int n); //후위연산자
	friend Power operator+(int n, Power a);
	Power& operator<<(int n);
	Power& operator<<(Power b);
};

void Power::show() {
	cout << "(" << punch << "," << kick << ")" << endl;
}

Power Power::operator+(Power& b) {
	Power tmp;
	tmp.punch = punch + b.punch;
	tmp.kick = kick + b.kick;
	return tmp;
}

Power Power::operator+(int b) {
	Power tmp;
	tmp.punch = punch + b;
	tmp.kick = kick + b;
	return tmp;
}

bool Power::operator == (Power b) {
	if (punch == b.punch && kick == b.kick)
		return true;
	else
		return false;
}

Power& Power::operator+=(Power b) {
	punch += b.punch;
	kick += b.kick;
	return *this;
}

bool Power::operator!() {
	if (punch == 0 && kick == 0)
		return true;
	else return false;
}

Power& Power::operator++() { //전위연산자
	punch++;
	kick++;
	return *this;
}

Power Power::operator++(int n) { //후위연산자
	Power tmp = *this;
	punch++;
	kick++;
	return tmp;
}

Power operator+(int n, Power a) {
	Power tmp;
	tmp.punch = n + a.punch;
	tmp.kick = n + a.kick;

	return tmp;
}

Power& Power::operator<<(int n) {
	punch += n;
	kick += n;
	return *this;
}

Power& Power::operator<<(Power n) {
	punch += n.punch;
	kick += n.kick;
	return *this;
}

int main() {
	int n = 2 + 3;
	Power a(2, 3), b(20, 30), c;
	c = a + b; //a.+(b)
	
	if (a == b) //a. == (b)
		cout << "equals" << endl;
	else
		cout << "not equals" << endl;

	a = Power(10, 20);
	(a += Power(1,1)) += Power(2,2); //a.+=(b)
	
	c = a + 2; //a.+(2)
	a.show(); c.show();


	if (!Power(0,0)) //a.!()
		cout << "Power 없음" << endl;
	else
		a.show();

	b = ++a; //a.++()
	a.show(); b.show();

	++++a; //이것도 가능하다!!!!!!
	//a.show();

	++a = Power(2, 3); //전위연산자는 Lvalue가 되는것을 허용하고 있다.
	b = Power(1, 1);
	a.show(); b.show();

	b = a++; //a.++(0);
	a.show(); b.show();


	c=2 + a; //2.+(a) ----안된다면----> +(2,a)
	a.show(); c.show();

	a.show(); c.show();
	a << 3 << c << 5; //a.<<(3), <<(a,3) 둘중 하나로 컴파일러가 변역할수 있다!!!!
	a.show();
}