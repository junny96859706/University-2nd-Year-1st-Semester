#include <iostream>
#include <string>
using namespace std;

class StringTokenizer {
	string* tokens;
	int size = 0;
	int nextTokenIndex = 0;
public:
	StringTokenizer(string text, string delimiter);
	~StringTokenizer();
	int length() { return size; }
	string next();
	bool hasNext();
};

StringTokenizer::StringTokenizer(string text, string delimiter) {
	size = text.size();
	tokens = new string[size];
	tokens = text;
}


int main() {
	StringTokenizer code("i++;for();sum+=1;", " ");

	for (int i = 0; i < code.length(); i++)
		cout << code.next() << endl;

	StringTokenizer text("모짜르트,베토벤,공주와왕자,황기태",",");

	while(text.hasNext()) //분리된 단어 하나씩 출력
		cout << code.next() << endl;
}