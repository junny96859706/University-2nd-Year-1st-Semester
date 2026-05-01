#include <iostream>
#include <string>
using namespace std;

int main() {
	string text;
	cout << "빈칸없이 문자열을 입력하세요>>";
	cin >> text;
	int num = text.length();

	for (int i = 0; i < num; i++)
		cout << text[i] << " ";
}