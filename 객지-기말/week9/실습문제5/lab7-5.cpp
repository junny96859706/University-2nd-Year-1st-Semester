#include <iostream>
#include <string>
using namespace std;

class Wallet {
	int money;
	string name;
public:
	Wallet(string name, int money = 0) {
		this->money = money;
		this->name = name;
	}
	void show() {
		cout << name << " 지갑에 " << money << "원 있어요." << endl;
	}

	Wallet& operator +=(int money);
	friend Wallet& operator-=(Wallet& p, int money);
	Wallet operator+(Wallet& p);
	friend Wallet operator+(Wallet p, int money);
	friend Wallet operator+(int money, Wallet p);
	Wallet& operator =(Wallet p);
};

Wallet& Wallet::operator+=(int money) {
	this->money += money;
	return *this;
}

Wallet& operator-=(Wallet& p, int money) {
	p.money -= money;
	return p;
}

Wallet Wallet::operator+(Wallet& p) {
	Wallet temp("임시객체");
	temp.money = this->money + p.money;
	return temp;
}

Wallet operator+(Wallet p, int money) {
	Wallet temp("임시객체");
	temp.money = p.money + money;
	return temp;
}

Wallet operator+(int money,Wallet p) {
	p.money += money;
	return p;
}

Wallet& Wallet::operator =(Wallet p) {
	this->money = p.money;
	return *this;
}

int main() {
	Wallet a("옥지윤", 2000), b("성주연", 100), c("박채원"); //박채원 지갑은 0원
	a += 1000; a.show();
	a -= 500; a.show();
	b = a + b + 100; // = 연산자는 금액만 복사
	b.show();
	c = 500 + b;
	c.show();

}