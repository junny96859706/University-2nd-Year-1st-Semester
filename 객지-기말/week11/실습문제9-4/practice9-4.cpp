#include <iostream>
using namespace std;

class AbstractPoint {
protected:
	string name; //회원 명
	int point = 0; //초기포인트0
	int ratio; //포인트 적립률. 단위%
public:
	AbstractPoint(string name, int ratio);
	virtual void earn(int pay) = 0; //순수가상함수. pay금액에 대한 포인트 적립
	virtual void show() = 0; //순수가상함수. 이름과 포인트 출력
	int getPoint() { return point; } //현재 포인트 리턴
};