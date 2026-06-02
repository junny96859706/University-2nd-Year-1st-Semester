#include <iostream>
#include <vector>
using namespace std;

int biggest(vector<int> &v) {
	int temp = v[0];

	for (int i = 0; i < v.size(); i++) {
		if (temp < v[i])
			temp = v[i];
	}
	return temp;
}

int main() {
	vector<int> array;
	vector<int>::iterator it;
	int num;

	cout << "10개의 정수 입력>>";
	for (int i = 0; i < 10; i++) {
		cin >> num;
		array.push_back(num);
	}

	while (true) {
		int choise;
		cout << "가장 큰 값:1, 평균:2, 삽입:3, 삭제:4, 증가:5, 종료:6>>";
		cin >> choise;

		switch(choise){
		case 1: {//가장큰값
			cout << "가장 큰 값 " << biggest(array) << endl;
		}
		case 2: { //평균
			int sum = 0;
			for (int i = 0; i < array.size(); i++) {
				sum += array.at(i);
			}
			cout << "평균 " << double(sum / array.size()) << endl;
		}
		case 3: { //삽입
			int add;
			cout << "삽입할 값>>";
			cin >> add;
			array.push_back(add);
		}
		case 4: { //삭제 
			int delete_num;
			cout << "삭제할 값>>";
			cin >> delete_num;
			for (int i = 0; i < array.size(); i++) {
				if (array[i] == delete_num) {
					it = array.begin() + i;
					it = array.erase(it); //v.erase(it)은 it이 가르키는 원소를 삭제한후 다음원도에 대한 포인터리턴
				}
			}

			for (int i = 0; i < array.size(); i++) {
				cout << array.at(i) << " ";
			}
			cout << endl;
		}
		case 5: { //증가
			int increase;
			cout << "몇배로 증가>>";
			cin >> increase;
			for (int i = 0; i < array.size(); i++) {
				array.at(i) *= increase;
			}
			for (int i = 0; i < array.size(); i++) {
				cout << array.at(i) << " ";
			}
			cout << endl;
		}
		case 6: { //종료
			break;
		}
		}
	}
	return 0;
}