#include <iostream>
#include <string>
using namespace std;

int main() {
	string name;
	int total = 0;

	cout << "에스프레소 3000원,아메리카노3500원,카푸치노4000원 입니다." << endl;

	while (1) {
		int num = 0, price = 0, money = 0;

		cout << "주문>>";
		cin >> name;
		
		if (name == "에스프레소")
			price = 3000;
		else if (name == "아메리카노")
			price = 3500;
		else if (name == "카푸치노")
			price = 4000;
		else {
			cout << "오타입니다! 메뉴를 다시 입력해주세요." << endl;
			continue;
		}

		cin >> num;
		money = price * num;
		total += money;
		cout << money << "원 입니다. 맛있게 드세요" << endl;

		if (total > 30000)
			break;
	}

	cout << "오늘" << total << "원을 판매하여 카페를 닫습니다. 내일 봐요~~";

}