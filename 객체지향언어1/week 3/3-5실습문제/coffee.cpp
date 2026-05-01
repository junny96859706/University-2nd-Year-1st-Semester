#include <iostream>
using namespace std;

class CoffeeMachine { //클래스이름 대문자로 시작안하면 감점시킨다.
	int coffee;
	int water;
	int sugar;
public:
	CoffeeMachine(int c, int w, int s);
	void drinkEspresso();
	void drinkAmericano();
	void drinkSugarCoffee();
	void show();
	void fill() {coffee = water = sugar = 10;} //간단한식은 구현부를 같이 구현해도 된다!
};

//구현부-----------------------------//
CoffeeMachine::CoffeeMachine(int c, int w, int s) {
	coffee = c; water = w; sugar = s;
}

void CoffeeMachine::drinkEspresso() {
	if (coffee == 0 || water == 0) {
		cout << "원료가 부족합니다. 에스프레소 다음에 오세요~" << endl;
		return;
	}
	coffee--; water--;
	cout << "에스프레소 나왔습니다~~" << endl;
}

void CoffeeMachine::drinkAmericano() {
	if (coffee <1 || water < 2) {
		cout << "원료가 부족합니다. 아메리카노 다음에 오세요~" << endl;
		return;
	}
	coffee--; water-=2;
	cout << "아메리카노 나왔습니다~~" << endl;
}

void CoffeeMachine::drinkSugarCoffee() {
	if (coffee <1 || water <2 || sugar < 1) {
		cout << "원료가 부족합니다. 설탕커피 다음에 오세요~" << endl;
		return;
	}
	coffee--; water -= 2; sugar--;
	cout << "설탕커피 나왔습니다~~" << endl;
}

void CoffeeMachine::show() {
	cout << "[머신상태]:";
	cout << "커피." << coffee << "\t"; //\t는 탭하기 기능이다!
	cout << "물" << water << "\t";
	cout << "설탕" << sugar << endl;
}

//-----------------------------------//
int main() {
	CoffeeMachine java(5, 10, 6); //커피5,물10,설탕6으로 초기화
	
	java.drinkEspresso(); //커피1 물1 소비
	java.show();
	java.drinkAmericano(); //커피1,물2소비
	java.show();
	java.drinkSugarCoffee(); //커피1,물2,설탕1소비
	java.show();
	java.fill(); //커피10,물10,설탕10으로 채우기
	java.show(); //현재 커피머신의 상태출력

/*직접 숫자버튼을 클릭해보기
	while (true) {
		cout << "에1, 아2, 설3 show4 fill5 끝6>>";
		int menu;
		cin >> menu;
		switch (menu) {
		case 1:java.drinkEspresso(); break;
		case 2:java.drinkAmericano(); break;
		case 3:java.drinkSugarCoffee(); break;
		case 4:java.fill(); break;
		case 6: return 0;
		}
	}
*/
}