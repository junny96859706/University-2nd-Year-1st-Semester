//예제10-9 - map으로 영한사전 만들기
#include <iostream>
#include <map>
using namespace std;

int main() {
	map<string, string> dic;
	
	dic.insert(make_pair("love", "사랑"));
	dic["apple"] = "사과"; //연산자 재정의
	dic["cherry"] = "체리";

	dic.erase("apple");

	cout << "저장된 단어 개수" << dic.size() << "개" << endl;
	while (true) { //while(1)로 쓰면 시험에서 많이 감점 시킨다!!!!!
		string eng;
		cout << "영단어>>";
		cin >> eng;
		if (eng == "exit") {
			cout << "사전을 종료합니다";
			break;
		}
		if (dic.find(eng) == dic.end()) { //찾는 단어가 없는 경우
			cout << "없음" << endl;
		}
		else {
			string kor = dic[eng];
			cout << kor << endl;
		}
	}

}