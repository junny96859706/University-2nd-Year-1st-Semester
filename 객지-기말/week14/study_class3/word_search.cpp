//기말고사 그대로 나오면 쓸줄 알아야한다!!!!!
#include <iostream>
#include <fstream>
#include <string>
#include <vector>
using namespace std;

void read(ifstream& fin, vector<string>& v) {
	int count = 0;
	string line;
	while (getline(fin, line)) {
		v.push_back(line);
		count++;
	}
	cout << "파일 읽기 완료..라인 " << count << endl;
}

void echo(vector<string>& v) {
	int no = 1;
	for (int i = 0; i < v.size(); i++) {
		string line = v[i];
		cout << no << "\t" << line << endl;
		no++;
	}
}

void search(vector<string>& v, string word) { 
	for (int i = 0; i < v.size(); i++) {
		string line = v[i];
		int index = line.find(word);
		if (index != -1) {
			cout << line << endl;
		}
	}
}

int main() {
	vector<string> wordVec;
	ifstream fin;
	fin.open("c:\\temp\\words.txt");
	if (!fin) {
		cout << "열기 실패" << endl;
		exit(0);
	}
	read(fin, wordVec);
	fin.close();

	//echo(wordVec);

	while (true) {
		cout << "단어 입력>>";
		string word;
		cin >> word;
		search(wordVec, word);
		
	}
}