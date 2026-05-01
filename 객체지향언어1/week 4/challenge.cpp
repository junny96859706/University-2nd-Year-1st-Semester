#include <iostream>
using namespace std;

#include "Exp.h"
#include "Exp.h"
int main() {
	Exp a(3, 2); //3의2승
	Exp b(9); //9의1승
	Exp c; //1의1승

	cout << a.getValue() << ' ';
	cout << b.getValue() << ' ';
	cout << c.getValue() << endl;

	cout << "a의 베이스" << a.getBase() << ' ';
	cout << "a의 지수" << a.getExp() << endl;

	if (a.equals(b))
		cout << "same" << endl;
	else
		cout << "not same" << endl;
}