#include <iostream>
using namespace std;

bool compare(int a,int b,int&min,int&max) {
	if (a > b) {
		max = a;
		min = b;
		return false;
	}
	else if (a < b) {
		max = b;
		min = a;
		return false;
	}
	else
		return true;
}

int main() {
	int a, b, min, max;
	while (1) {
		cout << "두 수 입력>>";
		cin >> a >> b;
		bool res = compare(a, b, min, max);
		if (res == true) {
			cout << "두 수는 같습니다." << endl;
			break;
		}
		else
			cout << "작은 수는 " << min << ", 큰수는 " << max << endl;;
	}
}