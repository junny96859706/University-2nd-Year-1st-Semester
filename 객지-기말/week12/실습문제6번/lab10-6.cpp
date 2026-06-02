#include <iostream>
#include <vector>
#include <ctime> //랜덤함수 사용하기 위한 해더
#include <cstdlib> //랜덤함수 사용하기 위한 해더
#include <string>
using namespace std;

int main() {
	vector<string> left; //성을 저장하는 벡터배열
	vector<string> mid; //중간이름을 저장하는 벡터배열
	vector<string> right; //끝 이름을 저장하는 벡터배열
	vector<string> name; //생성한 이름들을 임의의 벡터에 저장하기 위한 기능

	string temp;
	cout << "성으로 사용될 글자들 입력>>";
	while (true) {
		cin >> temp;
		if (temp == "\n")
			break;
		left.push_back(temp);
	}
}