#include <iostream>
#include <string>
using namespace std;

ostream& beep(ostream& s) {
	s << '\a';
	return s;
}

ostream& rightarrow(ostream& s) {
	s << "<---------";
	return s;
}

istream& question(istream& s) {
	cout << "거울아 거울아 누가 제일 멋있니?: ";
	return s;
}

int main() {
	cout << "벨이 울립니다." << beep << endl;
	cout << rightarrow << endl;

	string answer;
	cin >> question >> answer;
	cout << "그사람은 " << answer;
}