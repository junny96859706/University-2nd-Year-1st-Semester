#include <iostream>
#include <string>
using namespace std;

int main() {

	string alpha, beta;
	cout << "텍스트입력(한글안됨)>>";
	getline(cin, alpha);

	for (int i = 0; i < alpha.size(); i++) {
		if (isalpha(alpha[i]))
			beta.append(1, alpha[i]);
		else if (alpha[i] == ' ')
			beta.append(1, alpha[i]);
	}

	cout << endl;
	cout << beta;
}