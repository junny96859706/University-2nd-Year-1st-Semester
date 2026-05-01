#include <iostream>
#include "Fitness.h"
using namespace std;


Fitness& Fitness::arrive(string Gender,int mw) {
	if (Gender == "남") {
		man += mw;
	}
	else if(Gender == "여") {
		woman += mw;
	}
	else 
		cout << "오류입니다. 성별을 다시 입력해주세요." << endl;
	return *this;
}

int& Fitness::at(string Gender) {
	if (Gender == "남") {
		return man;
	}
	else if(Gender == "여") {
		return woman;
	}
	else {
		cout << "오류입니다. 성별을 다시 입력해주세요." << endl;
		error = -1;
		return error;
	}
}

void Fitness::count(string Gender, int &mw) {
	if (Gender == "남") {
		mw = man;
	}
	else if (Gender == "여") {
		mw = woman;
	}
	else {
		cout << "오류입니다. 성별을 다시 입력해주세요." << endl;
		mw = -1;
	}
}