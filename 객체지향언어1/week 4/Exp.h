#ifndef EXP_H
#define EXP_H
class Exp {
	int base;
	int exp;
public:
	Exp(int b, int e);
	Exp(int b);
	Exp();
	int getValue();
	int getBase() { return base; }
	int getExp() { return exp; }
	bool equals(Exp b);
};
#endif
