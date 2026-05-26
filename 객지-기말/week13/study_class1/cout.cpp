#include <iostream>
using namespace std;

void get() {
	cout << "입력하세요>>";
	int ch;
	int n = 1;
	cout << "1:";                  

	while ((ch = cin.get()) != EOF) {
		cout.put(ch);
		if (ch == '\n') {
			n++;
			cout << n << ": ";
		}
	}
}

void get2() {
	cout << "입력하세요>>";
	char ch;

	while (true){
		cin.get(ch);
		if (cin.eof())
			break;
		cout.put(ch);
		if (ch == '\n')
			break;
	}
}

int main() {
	get();
	get2();

}