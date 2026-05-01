#include <iostream>
using namespace std;

int main() {
	int n = 2;
	int& ref = n; //변수n에 대한 참조변수 ref선언
	n++;
	ref++;

	cout << ref << ' ' << n << endl;

	int m = 6;
	ref = m;
	cout << ref << ' ' << n << endl;

	int* p = &ref; //&n
	*p = 20;

	cout << ref << ' ' << n << endl;
}