#include <iostream>
#include <string>
using namespace std;

void star(int n=5) { //n에 아무값도 넘어오지 않으면 5가 넘어온것으로 하라
	for (int i = 0; i < n; i++) cout << "#";
	cout << endl;
}

void msg(int id=1, string text="blank") {
	cout << id << ' ' << text << endl;
}

int main() {
	star(10); //#를 10개 출력
	star(); //5개의 #출력. star(5)와 동일

	msg(10, "hello");
	msg(10); //msg(10,")와 동일
	msg(); //msg(1,"blank")와 동일
}