#include <iostream>
#include "Fitness.h"
using namespace std;

int main() {
	Fitness altong;
	altong.arrive("남", 3).arrive("여", 6).arrive("남", 9);

	int m = 0, w = 0;
	altong.count("남", m);
	altong.count("여", w);
	if (m != -1 && w != -1) {
		cout << "남자 회원" << m << "명, 여자회원" << w << "명" << endl;
	}

	altong.at("남") = 100;
	m = altong.at("남");
	w = altong.at("여");
	if (m != -1 && w != -1) {
		cout << "남자 회원" << m << "명, 여자회원" << w << "명" << endl;
	}
}