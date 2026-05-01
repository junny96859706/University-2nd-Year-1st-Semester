#include <iostream>
#include <string>
using namespace std;

int main() {
	string a;
	string b;
	cout << "문자열을 입력하세요>>";
	cin >> a;
	cout << "문자열을 입력하세요>>";
	cin >> b;
	
	if (a==b) cout << "yes";
	else cout << "no";
}