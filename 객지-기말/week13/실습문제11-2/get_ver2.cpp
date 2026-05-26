#include <iostream>
using namespace std;

//istream& get(char& ch)함수 이용하여 숫자가 몇개인지 알아보기
int main() {
	char ch;
	int count = 0;

	cout << "입력하세요>>";
	while (true) {
		cin.get(ch);
		if (cin.eof()) 
			break; //EOF를 만나면 읽기 종료
		cout.put(ch);
		if (ch-'0' >= 0 && ch-'0' <= 9)
			count++;
		if (ch == '\n')
			break;
	}

	cout << "숫자는 모두 " << count << "개 입력됨" << endl;

}