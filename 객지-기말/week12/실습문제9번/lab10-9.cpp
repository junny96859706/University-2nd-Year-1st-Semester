#include <iostream>
#include <map>
#include <string>
using namespace std;

void print_order(map<string,int>& map,string menu,int num) {
	if (map.find(menu) == map.end()) {
		cout << "없는 메뉴입니다" << endl;
	}
	else
		cout << "가격은 " << (map[menu] * num) << "원 입니다." << endl;
}

int main() {
	map<string, int> menuMap;
	menuMap["짜장면"] = 5000;
	menuMap["짬뽕"] = 6000;
	menuMap.insert(make_pair("볶음밥", 8000));
	menuMap.insert({ "탕수육",25000 });

	while (true) {
		string menu;
		int num;
		cout << "주문>>";
		cin >> menu;
		if (menu == "그만")
			return 0;
		cin >> num;
		print_order(menuMap,menu,num);
	}
}
