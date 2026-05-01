#include <iostream>
using namespace std;

int main() {
	int num = 1;

	for (int i = 0; i < 6; i++) {
		for (int j = 0; j < 10; j++) {
			if (num < 56) {
				cout << num << "\t";
				num++;
			}
		}
		cout << endl;
	}
}