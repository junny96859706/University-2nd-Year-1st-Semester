#include <iostream>
#include <string>
using namespace std;

bool equals(string x,string y,int num=0,string z="") {
	if (z == "") { //z가 입력되어있지 않다면
		if (num == 0) { //전체를 비교한다면
			if (x == y)
				return true;
			else
				return false;
		}
		else { //특정글자수만 비교한다면
			for (int i = 0; i < num; i++) {
				if (x[i] != y[i])
					return false;
			}
			return true;
		}
	}
	else {  //z가 입력되어있다면
		for (int i = 0; i < num; i++) {
			if (x[i] != y[i] || y[i]!=z[i] || x[i]!=z[i]) {
				return false;
			}
		}
		return true;
	}

}

int main() {
	string x = "Prof. Hwang";
	string y = "Prof. Kim";
	string z = "Prof. Lee";

	if (equals(x, y))
		cout << "같음" << endl;
	if (equals(x, y,3))
		cout << "앞 3글자 같음" << endl;
	if (equals(x, y,5,z))
		cout << "앞 5글자 같음" << endl;
}