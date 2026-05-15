#ifndef ABSTRACTPOINT_H
#define ABSTRACTPOINT_H

#include <string> //name변수타입을 사용하기 위한 string 헤더선언

class AbstractPoint {
protected:
	std::string name; //회원 명
	int point = 0; //초기포인트0
	int lowRatio = 0, highRatio = 0; //포인트 적립률. 단위:%
public:
	AbstractPoint(std::string name, int lowRatio, int highRatio);
	virtual void earn(int pay) = 0; //순수가상함수. pay금액에 대한 포인트 적립
	virtual void show() = 0; //순수가상함수. 이름과 포인트 출력
	int getPoint() { return point; } //현재 포인트 리턴
};

#endif