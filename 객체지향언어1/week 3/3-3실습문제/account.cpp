#include <iostream>
#include <string>
using namespace std;

class Account {
	int money = 0;
	int allmoney = 0;
	string name;
public:
	string getOwner();
	int inquiry();
	int withdraw(int w);
	int deposit(int d);
	Account(string a);
};

Account::Account(string a) { //생성자구현부
	name = a;
}

int Account::deposit(int d) { //저금
	allmoney = d;
	return allmoney;
}

int Account::inquiry() { //잔액
	allmoney = allmoney - money;
	return allmoney;
}

int Account::withdraw(int w) { //출금시도
	money = w;
	return money;
}

string Account::getOwner() { //계좌소유주이름
	return name;
}

int main() {
	Account a("황수희");
	a.deposit(20000);
	cout << a.getOwner() << "잔액은 " << a.inquiry() << endl;
	int money = a.withdraw(15000);
	cout << money << "원 출금,";
	cout << a.getOwner() << "잔액은 " << a.inquiry() << endl;
	money = a.withdraw(5000);
	cout << money << "원 출금,";
	cout << a.getOwner() << "잔액은 " << a.inquiry() << endl;

}