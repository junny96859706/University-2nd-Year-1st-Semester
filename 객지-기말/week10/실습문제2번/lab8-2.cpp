#include <iostream>
#include <string>
using namespace std;

class EspressoCoffee {
	string name;
	int espresso, water;
public:
	EspressoCoffee(string name, int espresso, int water) {
		this->name = name; this->espresso = espresso; this->water = water;
	}
	void recipe() {
		cout << name << "는 에스프레스 " << espresso << "스푼";
		cout << ", 물" << water << "스푼" << endl;
	}
	void get(string& name, int& espresso, int& water) {
		name = this->name; espresso = this->espresso; water = this->water;
	}
};

class Cappuccino : public EspressoCoffee {
	int milk;
	bool ice;
public:
	Cappuccino(string name, int espresso, int water, int milk, bool ice);
	void recipe() {
		string temp_name;
		int temp_espresso, temp_water;
		get(temp_name, temp_espresso, temp_water);

		cout << temp_name << "는 에스프레스 " << temp_espresso << "스푼";
		if (ice) {
			cout << ", 얼음물" << temp_water << "스푼";
			cout << ", 우유 " << milk << "스푼, 얼음 충분히" << endl;
		}
		else {
			cout << ", 따뜻한 물" << temp_water << "스푼";
			cout << ", 우유 " << milk << "스푼, 따뜻하게" << endl;
		}
	}
};

Cappuccino::Cappuccino(string name, int espresso, int water, int milk, bool ice)
	: EspressoCoffee(name, espresso, water) {
	this->milk = milk;
	this->ice = ice;
}

int main() {
	EspressoCoffee espresso("에스프레소", 2, 0); //물 없이 에스프레소만
	EspressoCoffee americano("아메리카노", 2, 5); //묽게
	americano.recipe(); //아메리카노 조리법 출력

	Cappuccino myHotCap("따뜻한 카푸치노", 2, 2, 4, false); //false는 따뜻한 의미
	myHotCap.recipe(); //따뜻한 카푸치노 조리법 출력
	Cappuccino myIceCap("아이스카푸치노", 2, 1, 5, true); //true는 아이스 의미
	myIceCap.recipe();
}