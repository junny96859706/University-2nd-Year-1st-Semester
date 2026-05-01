#include <iostream> //입출력기능을 위한 <iostream>해더파일 호출
#include <string> //문자열 처리를 위해 <string>호출
using namespace std; //std 이름공간에 선언된 모든 이름에 std생략

//생성부---------------------------------------------------------//
class Memo { //날짜와 장소를 저장하는 Memo클래스 생성
	string date; //문자열 변수에 날짜를 저장하는
	string content; //문자열 변수에 장소를 저장
public: //외부에 공개하기 위해서 public접근지정자 지정
	Memo(string d, string c); //날짜와 장소를 쓸수있도록하는 생성자생성
	void show(); //날짜와 내용을 출력하도록 show함수 지정
	string getDate(); //날짜를 변환하도록하는 기능의 getDate함수 지정
	string getContent(); //장소를 저장하도록하는 기능의 gerContent함수 지정
	bool isSameDate(Memo b); //다른 Memo와 날짜가 같은지 비교는 함수 지정 
};

//구현부---------------------------------------------------------//
Memo::Memo(string d,string c) { //객체생성시 작동하는 생성자를 구현
	date = d; //입력된 날짜를 멤버변수 date에 저장
	content = c; //입력된 장소를 멤버변수 content에 저장
}


void Memo::show(){ //날짜와 장소을 보여주는 함수를 구현하는 구현부
	cout << date << "," << content << endl; //날짜와 장소를 둘다 출력 
}

string Memo::getDate() { //입력된 날짜를 반환하여 저장하는 함수구현
	return date; //날짜를 date 문자열타입으로 반환
}

string Memo::getContent() { //입력된 장소를 반환하여 저장하는 함수구현
	return content; //장소를 content 문자열타입으로 반환
}

bool Memo::isSameDate(Memo b) { //두날짜를 비교해서 참거짓을 도출하도록하는 함수
	if (date == b.date) { //만약 두개의 날짜가 같을경우의 조건일시
		return true; //같은 날짜임을 참으로 결과값을 반환
	}
	else { //두날짜를 비교해서 거짓이라면
		return false; //다른날짜임을 거짓으로 결과값을 반환
	}
}

//메인함수---------------------------------------------------------//
int main() {
	Memo a("1:20", "동계 프로그래밍 캠프"); //첫번째 객체a생성
	Memo b("2:20", "김경미 독일 송별회"); //두번째 객체b 생성
	Memo c("2:21", "박채원 졸업식. 대학원 간대"); //세번째 객체c생성

	a.show(); //a객체의 날짜와 장소를 출력하도록 클래스함수호출
	if (a.isSameDate(b)) cout << "같은 날입니다." << endl;  //날짜가 같을 경우의 메세지출력
	else cout << "다른날입니다." << endl; //날짜가 다를경우의 메세지출력
	cout << b.getDate() << "에 " << b.getContent() << endl; //b객체의 날짜와내용을 불러와 출력
}