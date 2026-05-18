#ifndef PLATINUM_H //PLATINUM_H가 정의되어있지않다면 헤더를 포함
#define PLATINUM_H //PLATINUM_H 헤더파일 정의

#include "AbstractPoint.h" //부모클래스의 성질을 상속받기 위해 부모클래스 헤더파일 포함

class Platinum : public AbstractPoint { //AbstractPoint클래스를 상속받아 고유속성을 확장한 자식클래스
protected: //상속관계의 하위클래스에서만 접근이 가능하도록 허용하는 접근 지정자
	int highRatio = 0, baseMoney = 0; //적립율을 결정하기 위한 결재금액을 나타내는 변수선언 및 초기화
public: //모두가 접근할수 있도록 하는 public 접근 지정자

	//부모클래스의 생성자를 명시적으로 호출함과 더불어 기준금액을 설정하는 자식클래스 생성자선언
	Platinum(string name, int Ratio, int baseMoney, int highRatio);
	virtual void earn(int pay); //추상클래스의 순수가상함수 구현,pay금액에 대한 포인트 적립(오버라이딩)
	virtual void show(); //추상클래스의 순수가상함수 구현,현재까지의 적립금액을 출력(오버라이딩)
	//두객체의 포인트를 한쪽으로 완전히 병합하고, 병합당한 객체의 포인트를 초기화 하는 함수
	void combine(Platinum& p); //회원간 포인트를 한쪽으로 완전히 병합하는 함수
};

#endif //PLATINUM_H조건부 헤더파일 구역의 끝