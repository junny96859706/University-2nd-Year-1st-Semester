#include <iostream>
#include <string>
using namespace std;

class Coffee {
	string coffee;
	int total;
public:
	Coffee() { total = 0; }
	void store();
	void print();
};

void Coffee::store() {
	while (1) {
		int money = 0, num = 0, price = 0;
		cout << "주문>>";
		cin >> coffee;
		if (coffee == "에스프레소")
			price = 3000;
		else if (coffee == "아메리카노")
			price = 3500;
		else if (coffee == "카푸치노")
			price = 4000;
		else {
			cout << "상품명을 제대로 입력해주세요" << endl;
			continue;
		}
		cin >> num;
		money = price * num;

		cout << money << "원입니다. 맛있게드세요." << endl;
		total += money;

		if (total > 30000)
			break;
	}
}

void Coffee::print() {
	cout << "오늘" << total << "원을 판매하여 카페를 닫습니다. 내일봐요~~~" << endl;
}

int main() {
	cout << "에스프레소3000원,아메리카노3500원,카푸치노 4000원 입니다." << endl;
	Coffee a;
	a.store();
	a.print();

}