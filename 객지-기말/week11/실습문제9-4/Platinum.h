#ifndef PLATINUM_H
#define PLATINUM_H

#include "Abstractpoint.h"

class Platinum : public AbstractPoint {
protected:
	int baseMoney = 0;
public:
	Platinum(string name, int lowRatio, int baseMoney, int highRatio)
		: AbstractPoint(name, lowRatio, highRatio) {
		this->baseMoney = baseMoney;
	}
	virtual void earn(int pay); //순수가상함수. pay금액에 대한 포인트 적립
	virtual void show();
	void combine(Platinum& p);
};

#endif