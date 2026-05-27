#include <iostream>
using namespace std;

istream& promptName(istream& in) {
	cout << "이름입력>>";
	return in;
}

istream& promptAge(istream& in) {
	cout << "나이 입력>>";
	return in;
}

int main() {
	string name;
	int age;
	cin >> promptName >> name;  //cin.>>(promptName)으로 해석!!!
	cin >> promptAge >> age;
	cout << "이름은 " << name << "," << "나이는 " << age << endl;
}