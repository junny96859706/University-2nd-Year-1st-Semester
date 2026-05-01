#include <iostream>
using namespace std;


class Player {
	string name;
public:
	Player(){}
	void setName(string name) { this->name = name; }
	string getName() { return name; }

};

class GameManager {
	int n;
	Player* players;
public:
	GameManager(){}
	void run();

};

void GameManager::run() {
	cout << "시작" << endl;
	cout << "인원>>";
	cin >> n;
	players = new Player[n];
	for (int i = 0; i < n; i++) {
		string name;
		cout << "이름";
		cin >> name;
		players[i].setName(name);

	}
	cout << "단어:아버지" << endl;
	string lastWord = "아버지";
	int index = 0;
	while (true) {
		cout << players[index].getName() << ">>";
		string word;
		cin >> word;
		char first1 = word.at(0);
		char first2 = word.at(1);

		int len = lastWord.length();
		char last1 = lastWord.at(len - 2);
		char last2 = lastWord.at(len - 1);

		if (first1 == last1 && first2 == last2) {//성공
			index++;
			index %= n;
			lastWord = word;
			continue;

		}
		else {
			cout << players[index].getName() << "님이 졌습니다." << endl;
			break;
		}
	}
}

int main() {
	GameManager* p = new GameManager();
	p->run();
	delete p;

}