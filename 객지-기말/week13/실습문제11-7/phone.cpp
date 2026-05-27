#include <iostream>
#include <string>
using namespace std;

class Phone { //전화번호를 표현하는 클래스
	string name, telnum, address; //이름,전화번호,주소
public:
	Phone(string name = "", string telnum = "", string address = "") {
		this->name = name;
		this->telnum = telnum;
		this->address = address;
	}

	friend istream& operator >>(istream& in, Phone& p);
	friend ostream& operator << (ostream & out, Phone& p);
};

istream& operator >>(istream& in,Phone& p) {
	cout << "이름:";
	in >> p.name;
	cout << "전화번호:";
	in >> p.telnum;
	cout << "주소:";
	in.ignore(); //앞서 남아있을지 모르는 엔터 버퍼를 한 칸 지우기
	getline(in, p.address); //주소에 공백이 있어도 한 줄을 통째로 안전하게 읽음.
	return in;
}

ostream& operator <<(ostream& out, Phone& p) {
	out << "(" << p.name << "," << p.telnum << "," << p.address << ")";
	return out;
}

int main() {
	Phone queen, prince;
	cin >> queen >> prince; //키보드로 부터 queen과 prince 객체 읽기 // >>(cin,queen);
	cout << queen << endl << prince << endl; //queen과 prince 객체 출력
}