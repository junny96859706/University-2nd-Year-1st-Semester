#include <iostream>
#include <string>
#include <vector>
using namespace std;

class Moving { //location과 distance를 멤버로 가진 Moving클래스
public:
	string location;
	int distance;
	Moving(string location, int distance) {
		this->location = location;
		this->distance = distance;
	}
};

void print_move(vector<Moving>& v) {
	//안전장치 추가: 벡터가 비어있으면 접근하지 않고 함수를 종료!
	if (v.empty()) {
		cout << "이동 경로 데이터가 없습니다." << endl;
		return;
	}

	int total = 0;
	for (int i = 0; i < v.size(); i++) {
		cout << v[i].location << ":" << v[i].distance << "km";
		
		//만약 현재 인덱스가 '마지막 원소'가 아니라면 화살표를 붙여준다!
		if (i < v.size() - 1) {
			cout << "-> ";
		}

		total += v[i].distance;
	}
	cout << endl;
	cout << "총 이동 거리는 " << total << "km" << endl;
}

int main() {
	vector<Moving> v;
	string location;
	int distance;

	while (true) {
		cout << "목적지와 이동거리 입력>>";
		cin >> location >> distance;
		v.push_back(Moving(location, distance));
		if (location == "우리집")
			break;
	}

	print_move(v);
}