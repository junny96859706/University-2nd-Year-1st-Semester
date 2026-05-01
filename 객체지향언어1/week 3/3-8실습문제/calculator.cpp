#include <iostream>
#include <string>
using namespace std;

class Calculator {
	int value;
	void calc(string op, int number);
public:
	Calculator() { value = 0; }
	int getValue() {return value;}
	void loop();
};

void Calculator::loop() {
	while (1) {
		string op;
		int number = 0;

		cout << "연산입력>>";
		cin >> op;
		if (op == "그만")
			break;
		cin>> number;
		calc(op,number);
	}
}

void Calculator::calc(string op, int number) {
	if (op == "/" && number == 0)
		return;

	if (op == "+")
		value += number;
	else if (op == "-")
		value -= number;
	else if (op == "*")
		value *= number;
	else if (op == "/")
		value /= number;
	else if (op == "%")
		value %= number;
}

int main() {
	Calculator jane;
	jane.loop();
	cout << "연산 결과는" << jane.getValue() << endl;
}