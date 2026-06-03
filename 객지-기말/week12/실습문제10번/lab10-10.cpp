#include <iostream>
#include <map>
#include <string>
using namespace std;

void insert_vote(map<string, int>& map, string name) {
	int temp = 0;
	if (map.find(name) == map.end()) {
		map.insert(make_pair(name, 1)); //중복되면 무시한다!!(원본 보호) //처음이니까 1표!!!
		return;
	}
	else {
		temp = map[name];
		temp++;
		map[name] = temp; //덮어쓰기 방식
	}
}

void print_vote(map<string, int>& vote) {
	map<string, int>::iterator it;
	for (it = vote.begin(); it != vote.end();) {
		cout << it->first << ":" << it->second << ",  ";
		it++;
	}
	cout << endl;
}

void biggest_vote(map<string, int>& vote) {
	map<string, int>::iterator it;
	map<string, int>::iterator it2; //iterator를 여러개 만드는것도 문제 없다!!!!

	if (vote.empty()) { // 안전장치 추가
		cout << "투표 데이터가 없습니다." << endl;
		return;
	}

	it = vote.begin();
	it2 = vote.begin();
	int temp = it->second;
	for (it = vote.begin(); it != vote.end();) {
		if (temp < it->second) {
			temp = it->second;
			it2 = it;
		}
		it++;
	}
	cout << it2->first << "님이 회장으로 선출되었습니다." << endl;
}

int main() {
	string name;
	map<string, int> vote;

	while (true) {
		cout << "이름 3개>>";
		for (int i = 0; i < 3; i++) {
			cin >> name;
			if (name == "그만")
				break; //이 break은 for문만 탈출한다!!!!
			else
				insert_vote(vote, name);
		}
		if (name == "그만")
			break;  //이제 break문도 탈출
	}

	print_vote(vote);
	biggest_vote(vote);
	return 0;
}