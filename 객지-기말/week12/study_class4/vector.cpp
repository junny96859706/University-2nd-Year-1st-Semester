//기말고사 25~30점 문제로 출제가능성 높다!!!!!!!!!!!!!!!
#include <iostream>
#include <vector>
using namespace std;

void print(vector<int> &v) {
	vector<int>::iterator it;
	for (it = v.begin(); it != v.end(); it++) { //v.end()는 마지막 원소 다음이다!
		cout << *it << ' ';
	}
	cout << endl;
}

int biggest(vector<int>& v) {
	int big = v[0]; //v.[](0)
	for (int i = 0; i < v.size(); i++) {
		if (big < v[i])
			big = v[i];
	}
	return big;
}

int main() {
	vector<int> v;
	cout << ">>";
	while (true) { //시험때 while(1)하면 감점 시킨다!!!
		int n;
		cin >> n;
		if (n == -1) break;
		v.push_back(n);
	}

	vector<int>::iterator it;
	it = v.begin();
	v.erase(it + 2);

	print(v);
	int big = biggest(v);
	cout << "가장 큰 수는" << big << "입니다." << endl;
}