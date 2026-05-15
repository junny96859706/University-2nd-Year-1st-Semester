#include <iostream>
#include <string>
using namespace std;

#include "Platinum.h"

void Platinum::earn(int pay) {
	if (pay > baseMoney)
		point += (pay * highRatio) / 100;
	else
		point += (pay * lowRatio) / 100;
}

void Platinum::show() {
	cout << name << "님*** " << "적립 포인트는 " << getPoint() << "점 입니다." << endl;
}

void Platinum::combine(Platinum& p) {
	point += p.point;
	p.point = 0;
}