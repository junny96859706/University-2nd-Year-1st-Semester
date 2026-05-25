#include <iostream> //여기에 cin,cout,clog ...
using namespace std;

int main() {
	cout.put('H');
	cout.put('i');
	cout.put(33); //put은 문자를 출력하는 멤버함수.
	//33을 문자코드로 해석 -> !문자의 ASCII코드
	cout.put('\n');

	cout.put('C').put('+').put('+');

	char str[] = "i love programming";
	cout.write(str, 6);
	cout.flush(); 

}