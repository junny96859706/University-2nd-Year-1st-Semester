#ifndef ABSTRACTPOINT_H //ABSTRACTPOINT_H가 정의되어있지않다면 헤더를 포함
#define ABSTRACTPOINT_H //ABSTRACTPOINT_H 헤더파일 정의

#include <string> //name변수타입을 사용하기 위한 string 헤더선언

class AbstractPoint { //각 회원객체가 가지는 이름과 포인트,적립률을 정의하는 클래스
protected: //상속관계의 하위클래스에서만 접근이 가능하도록 허용하는 접근 지정자
	std::string name; //포인트를 적립받는 회원의 이름을 저장할 string형식의 변수
	int point = 0; //누적포인트를 저장할 point변수를 만들고 초기포인트를 0으로 설정
	int lowRatio = 0, highRatio = 0; //결재금액별로 차등 적용될 적립비율 변수(%) 설정
public: //모두가 접근할수 있도록 하는 public 접근 지정자
	//회원정보및 적립비율을 초기화하는 매개변수 생성자
	AbstractPoint(std::string name, int lowRatio, int highRatio);
	virtual void earn(int pay) = 0; //순수가상함수. pay금액에 대한 포인트를 적립
	virtual void show() = 0; //순수가상함수. 이름과 포인트 출력하는 함수
	int getPoint() { return point; } //외부에서 현재의 포인트를 리턴하여 전달하기 위한 접근 함수
};

#endif //헤더파일 구역의 끝