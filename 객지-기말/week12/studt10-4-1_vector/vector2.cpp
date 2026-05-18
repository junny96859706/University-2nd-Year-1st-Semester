#include <iostream>
#include <vector>
using namespace std;

void showALL(vector<string> &v) {
	for (int i = 0; i < v.size(); i++)
		cout << v.at(i) << " ";
	cout << endl;
}

int main() {
	vector<string> sv;
	string name;

	cout << "5개의 이름을 입력하세요" << endl;
	for (int i = 0; i < 5; i++) {
		cout << i + 1 << ">>";
		cin >> name;

		sv.push_back(name);
	}

	showALL(sv); 

	name = sv[0]; //첫번째 저장된 이름이 제일 길다고 가정
	for (int i = 1; i < sv.size(); i++) {
		if (name < sv[i]) //크면 사전에서 뒤에 나온다.
			name = sv[i];
	}

	cout << "사전에서 제일 뒤에 나오는 이름은" << name << endl;
}