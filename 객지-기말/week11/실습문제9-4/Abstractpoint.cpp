#include <iostream> //표준 입출력기능을 활용하기위한 라이브러리
#include <string>  //회원의 이름을 string형태로 처리하기 위한 헤더
using namespace std; //std 이름공간에 선언된 모든 이름에 std생략

#include "AbstractPoint.h" //Abstractpoint.h 헤더파일 호출

//회원의 이름과 차등적립률을 저장하는 부모클래스의 생성자 구현부
AbstractPoint::AbstractPoint(string name, int lowRatio,int highRatio) {
	this->name = name; //매개변수로 들어온 이름을 클래스변수로 저장
	this->lowRatio = lowRatio; //기준금액 이하일때 적용할 일반적립율을 클래스변수에 저장
	this->highRatio = highRatio; //기준금액 초과일대 적용할 우대적립율을 클래스 변수에 저장
} //생성자 구현 종료