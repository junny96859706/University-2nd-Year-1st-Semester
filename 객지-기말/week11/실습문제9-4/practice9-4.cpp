#include <iostream>
using namespace std;

class AbstractPoint {
protected:
	string name; //회원 명
	int point = 0; //초기포인트0
	int ratio; //포인트 적립률. 단위%
public:
	AbstractPoint(string name,int ratio1,int ratio2);
	virtual void earn(int pay) = 0; //순수가상함수. pay금액에 대한 포인트 적립
	virtual void show() = 0; //순수가상함수. 이름과 포인트 출력
	int getPoint() { return point; } //현재 포인트 리턴
};

AbstractPoint::AbstractPoint(string name,int ratio1,int ratio2) {
	this->name = name;
} 

class Platinum : public AbstractPoint {
public:
	Platinum(string name, int ratio1, int money, int ratio2) : AbstractPoint(name,ratio1,ratio2) {

	}
	virtual void earn(int pay); //순수가상함수. pay금액에 대한 포인트 적립
	virtual void show();
	void combine(Platinum p);
};

void Platinum::earn(int pay){

}

void Platinum::show() {

}

void Platinum::combine(Platinum p) {

}

int main(){
	Platinum hwang("황기태", 5, 100000, 7), park("박채원", 5, 100000, 7);
	//생성자 의미:100000원 까지는 5%, 그보다 큰경우 7%

	hwang.earn(50000); //50000원 지출경우, 2500원 포인트 적립
	hwang.earn(200000); //200000원 지출경우, 14000원 포인트 적립
	park.earn(500000); //500000원 지출경우, 3500원 포인트 적립
	hwang.show();
	park.show(); //현재 누적 포인트 출력

	hwang.combine(park); //hwang회원에 park의 포인트 결합
	hwang.show();
	park.show();
}