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

//디폴트 매개변수는 함수 선언부에만 적어야 한다. 구현부에는 적지 않는 것이 원칙!!!
AbstractPoint::AbstractPoint(string name, int ratio) { 
	this->name = name;
	this->ratio = ratio;
}

class Silver : public AbstractPoint {
public:
	Silver(string name, int ratio = 3) : AbstractPoint(name, ratio) { }
	virtual void earn(int pay);
	virtual void show();
};

void Silver:: earn(int pay) {
	point += (pay * ratio) / 100;
}

void Silver::show() {
	cout << name << "님*" << "적립 포인트는 " << getPoint() << "점 입니다." << endl;
}

int main() {
	Silver hwang("황기태"), ok("옥지윤", 4);
	//생성자 의미:황기태 적립률 3%, 옥지윤 적립률 4%

	hwang.earn(10000); //10000원을 지출한 경우, 포인트 300적립
	hwang.earn(20000); //20000원을 지출한 경우, 포인트 600적립
	hwang.earn(5000);  //5000원을 지출한 경우, 포인트 150적립
	ok.earn(5000); //5000원을 지출한 경우, 포인트 200적립
	hwang.show();
	ok.show(); //현재 누적 포인트 출력
}