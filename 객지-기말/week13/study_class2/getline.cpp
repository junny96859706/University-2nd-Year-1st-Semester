#include <iostream>
using namespace std;

int main() {
	while (true) {
		cout << "암호입력>>";
		char pw[80];
		cin.getline(pw, 80);
		if (strcmp(pw, "Good Morning") == 0) {
			cout << "통과" << endl;
			break;
		}
	}
}