#include <iostream>
#include <cstring>
using namespace std;
//문장 입력후,단어의 갯수를 파악하는 프로그램

int main() {
	char word[100];

	
	while (1) {
		int count = 0;
		int i = 0;
		cout << "영문 텍스트를 입력하세요(빈칸포함 가능)>>";
		cin.getline(word, 100);
		if (strcmp(word, "exit") == 0)
			break;
		
		while (word[i] != '\0') {
			if (word[i] == ' ') {
				count++;
			}
			i++;
		}
		cout << "단어의 개수는 " << count+1 << "개이다." << endl;
	}
}