#include <iostream>
#include <string>
#include <map>
using namespace std;

int main() {
	map<string, string> dic;

	dic.insert(make_pair("love", "사랑"));
	dic.insert(make_pair("apple", "사과"));
	dic["cherry"] = "체리";

	cout << "저장된 단어 개수: " << dic.size() << endl;

	while (true) {
		string word;
		cout << "찾고 싶은 단어>> ";
		getline(cin, word); //<string>헤더파일 있어야 한다!!!
		if (word == "exit") {
			break;
		}

		if (dic.find(word) == dic.end())
			cout << "없음" << endl;
		else
			cout << dic[word] << endl;
	}
	cout << "종료합니다..." << endl;
}