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
};

int main() {
	Coffee blank(2, 5, 0, 0), dabang(2, 2, 2, 2);
	blank += dabang; 
	black += 1; //black커피에 에스프레소 1샷 추가
	black++; //black커피에 다시 에스프레소 1샷 추가
	black.show();
}