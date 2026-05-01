#include <iostream>
using namespace std;

int main() {
	int n = 5;
	int m = 10;
	int* p = &n;
	int& ref = n; //n에 참조변수선언
	ref = m; //m값을 ref값에 넣어라.ㅠ 
	
	ref++;
	n = 20;

	p = &ref;

	cout << n << "," << ref << "," << *p << endl;
}