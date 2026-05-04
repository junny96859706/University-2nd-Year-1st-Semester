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

	Coffee operator+(Coffee op1);
	friend Coffee operator+(Coffee op1,int op2);
};

Coffee Coffee::operator+(Coffee op1) {
	Coffee tmp;
	tmp.water = water + op1.water;
	tmp.espresso = espresso + op1.espresso;
	tmp.sugar = sugar + op1.sugar;
	tmp.cream = cream + op1.cream;

	return tmp;
}

Coffee operator+(Coffee op1,int op2) {
	Coffee tmp;
	tmp.water = op1.water;
	tmp.espresso = op1.espresso + op2;
	tmp.sugar = op1.sugar;
	tmp.cream = op1.cream;

	return tmp;
}

int main() {
	Coffee black(2, 5, 0, 0), dabang(2, 2, 2, 2), c, d;
	c = black + dabang; //black.+(dabang);
	d = c + 1; //c.+(1); or +(c,1)
	c.show();
	d.show();
}