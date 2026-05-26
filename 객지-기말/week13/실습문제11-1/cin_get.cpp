#include <iostream>
using namespace std;

int main() {
	int ch;
	cout << "입력하세요>>";
	while ((ch = cin.get()) != EOF) {
		if (ch == ';')
			break;
		cout.put(ch);

	}
	cin.ignore(100, '\n');
}