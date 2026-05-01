#include <iostream>
#include <string>
using namespace std;

//함수작성시 find()와 replace()함수 이용할것
string erase(string word) {
	string result;
	int len = word.size();
	for (int i = 0; i < len; i++) {
		if (word[i] != ' ')
			result[i] = word[i];
	}
	return result;
}
//문장에서 모든 11을 지운 결과;
string erase(string word, string eraseword) {
	string result;
	int point = word.find(eraseword);
	int wordlen = word.size();
	int eraselength = eraseword.size();

	if (point == string::npos) {
		result = word;
		return result;
	}
	
	for (int i = 0; i < wordlen; i++) {
		if (i == point) {
			word.replace(point, eraselength, "");
			point= word.find(eraseword,i);
		}
		else
			result[i] = word[i];
	}
	return result;
}

//문장에서 모든 o를 77로 바꾼것
string erase(string word, string eraseword, string replaceword) {
	string result;
	int point = word.find(eraseword);
	int wordlen = word.size();
	int eraselength = eraseword.size();

	if (point == string::npos) {
		result = word;
		return result;
	}

	for (int i = 0; i < wordlen; i++) {
		if (i == point) {
			word.replace(point, eraselength,replaceword);
			point = word.find(eraseword, i);
		}
		else
			result[i] = word[i];
	}
	return result;
}


int main() {
	string a = erase("He11o   world,  yaho");
	cout << "모든 빈칸 지운 결과\t" << a << endl;
	string b = erase("He11o   world,  yaho", "11");
	cout << "모든 11을 지운결과\t" << b << endl;
	string c = erase("He11o   world,  yaho", "o", "77");

	cout << "모든 o를 77로 바꾼결과\n" << c << endl;
}
