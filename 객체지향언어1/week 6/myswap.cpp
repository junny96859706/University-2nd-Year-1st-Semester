#include <iostream>
using namespace std;

void myswap(int &a,int &b) { //int &a=m;
	int tmp;
	tmp = a; 
	a = b;
	b = tmp; 

	return;
}

int main() {
	int m = 2, n = 9;

	myswap(m, n); //함수호출
	cout << m << ' ' << n << endl;
}