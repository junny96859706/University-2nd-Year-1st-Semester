#include <iostream>
#include <vector>
using namespace std;

int biggest(vector<int>& v) {
	if (v.empty()) return 0; //혹시나 벡터가 비어있을때를 위한 방어코드
	int temp = v.at(0);
	for (int i = 0; i < v.size(); i++) {
		if (temp < v.at(i))
			temp = v.at(i);
	}
	return temp;
}

void print_array(vector<int>& v) {
	for (int i = 0; i < v.size(); i++) {
		cout << v.at(i) << ' ';
	}
}

bool check_array(vector<int>& v,int temp) {
	for (int i = 0; i < v.size(); i++) {
		if (temp == v.at(i))
			return true;
	}
	return false;
}

int main() {
	vector<int> array;

	while (true) {
		int temp;
		cout << "정수를 입력하세요. 0이면 종료>>";
		cin >> temp;

		if (temp == 0)
			return 0;

		if (check_array(array,temp)) {
			cout << "이미 있음" << endl;
			continue;
		}
		else array.push_back(temp);

		cout << "[";
		print_array(array);
		cout << "], 가장 큰 수" << biggest(array) << endl;
	}
}