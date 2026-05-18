#include <iostream>
#include <vector> //vector 컨테이터 선언
using namespace std;

int main() {
	vector<int> v; //v는 정수만 저장가능한 가변 배열(벡터)(컨테이너)

	v.push_back(1);
	v.push_back(2);
	v.push_back(3);
	v.push_back(30);

	cout << "현재 개수 = " << v.size() << endl;
	int n = v.size();
	for (int i = 0; i < n; i++)
		cout << v.at(i) << " ";
	cout << endl;

	v[0] = 10; //1->10으로 변경
	int m = v[2]; //v[2] = v.at(2)와 같다.
	cout << "2번째 원소는 " << m << endl;

	for(int i=0; i<v.size();i++)
		cout << v.at(i) << " ";
	cout << endl;
}