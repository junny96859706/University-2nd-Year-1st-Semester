#include "Exp.h"

Exp::Exp(int b, int e) {
	base = b;
	exp = e;
}

Exp::Exp(int b) {
	base = b;
	exp = 1;
}

Exp::Exp() {
	base = 1;
	exp = 1;
}

int Exp::getValue() {
	int sum = 1;
	for (int i = 0; i < exp; i++) {
		sum *= base;
	}
	return sum;
}

bool Exp::equals(Exp b) {
	if (getValue() == b.getValue())
		return true;
	else
		return false;
}