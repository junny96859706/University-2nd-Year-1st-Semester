#include <iostream>
#include <fstream>
#include <vector>
#include <string>
using namespace std;

void echo(vector<string>& v) {
	int n = v.size();
	for (int i = 0; i < n; i++) {
		string s = v[i];
		cout << s << endl;
	}
}

void search(vector<string>& v, string word) {
	int n = v.size();
	for (int i = 0; i < n; i++) {
		string s = v[i]; 
		int index = s.find(word); //찾으면 1리턴
		if (index != -1) //found!!!
			cout << s << endl;
	}
}

int main() {
	vector<string> wordVector;
	ifstream fin("words.txt"); //프로그램과 같은 파일에 저장하면 경로지정 안써도 된다
	if (!fin) {
		cout << "open error" << endl;
		return 0;
	}

	//파일읽기
	int count = 0; //라인숫자 카운트
	string line;
	while (getline(fin, line)) {
		wordVector.push_back(line);
		count++;
	}

	cout << count << "라인수의 words.txt 파일을 모두 읽었습니다." << endl;

	//echo(wordVector);
	
	while (true) {
		cout << "검색할 단어 입력>>";
		string word;
		getline(cin, word); //사용자의 단어 입력
		if (word == "exit")
			break; //반복문 종료
		search(wordVector, word);
	}

	cout << "프로그램 종료합니다...." << endl;

	fin.close();
}