#include <iostream>
using namespace std;

template <class T> T bigger(T a, T b) {
	if (a > b) return a;
	else return b;
}

template <class T>
T add(T data[], int n) {
	T sum = 0;
	for (int i = 0; i < n; i++) {
		sum += data[i];
	}
	return sum;
}

int main() {

	int a = 20, b = 50;
	char c = 'a', d = 'z';
	cout << bigger(a, b) << endl;
	cout << bigger(c, d) << endl;


	int x[] = { 1,2,3,4,5 };
	double y[] = { 1.2,2.3,3.4,4.5,5.6,6.7 };
	cout << add(x, 5) << endl;
	cout << add(y, 6) << endl;
	
}