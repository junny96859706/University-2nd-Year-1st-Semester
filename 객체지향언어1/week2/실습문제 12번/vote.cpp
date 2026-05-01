#include <iostream>
#include <string>
using namespace std;

int main() {

	string name;
	int num1 = 0;
	int num2 = 0;

	cout << "과대표 출마자: 황수희,장수희" << endl;
	while (1) {
		int vote = 0;
		cout << "이름과 투표수>>";
		cin >> name;
		if (name == "그만")
			break;
		cin	>> vote;

		if (name == "황수희")
			num1 += vote;
		else if (name == "장수희")
			num2 += vote;
		else
			cout << name << "은 출마자가 아닙니다." << endl;
	}

	cout << "최종집계: " << "황수희" << num1 << "," << "장수희" << num2 << endl;
	if (num1 > num2)
		cout << "과대표로 황수희가 선출되었습니다.";
	else if (num1 < num2)
		cout << "과대표로 장수희가 선출되었습니다.";
	else
		cout << "동표이므로 양측이 공동대표로 선출되었습니다.";
}