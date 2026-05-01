#include <iostream>
using namespace std;

int twice(int& number) {
	number = number * 2;
	return number;
}

int main() {
	int n = 12;
	twice(n);
	cout << n;
}
