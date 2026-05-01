#include <iostream>
#include <string>
using namespace std;

int main() {
	string line;
	string result;
	cout << "텍스트 입력>>";
	getline(cin, line, '\n');

	for (int i = 0; i < line.size(); i++) {
		if (line[i] != ' ')
			result.append(1, line[i]);
		else if (i > 0 && line[i - 1] != ' ')
			result.append(1, line[i]);
	}

	cout << result;


}