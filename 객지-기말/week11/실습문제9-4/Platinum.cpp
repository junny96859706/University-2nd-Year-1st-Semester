#include <iostream> //표준 입출력기능을 활용하기위한 라이브러리
#include <string> //회원의 이름을 string형태로 처리하기 위한 헤더
using namespace std; //std 이름공간에 선언된 모든 이름에 std생략

#include "Platinum.h" //Platinum.h 헤더파일 호출

//부모클래스의 생성자를 명시적으로 호출함으로서 기본생성자의 묵시적삽입을 방지+ 자식클래스 생성자구현
Platinum::Platinum(string name, int Ratio, int baseMoney, int highRatio)
	: AbstractPoint(name,Ratio) { 
	this->baseMoney = baseMoney; //적립률을 결정할수 있는 지출액 저장
	this->highRatio = highRatio; //기준금액 초과일대 적용할 우대적립율을 클래스 변수에 저장
}

void Platinum::earn(int pay) { //적립률을 결정한뒤 포인트를 저장해주는 earn함수 구현부
	if (pay > baseMoney) //지출액이 우대기준선을 넘을시, 우대적립률로 적립
		point += (pay * highRatio) / 100; //우대비율을 곱해 포인트를 계산하고 포인트에 누적
	else //지출액이 우대기준선을 넘지않을시, 일반적립률로 적립
		point += (pay * Ratio) / 100; //일반비율을 곱해 포인트를 계산하고 포인트에 누적
}

void Platinum::show() { //회원의 이름과 포인트 수치를 출력하는 함수 구현부
	//부모의 멤버 변수(point)에 직접 접근하여 값을 가져오는 대신,
	// 캡슐화 원칙을 지키기 위해 안전하게 데이터를 반환하는 getPoint() 함수를 호출하여 활용함
	cout << name << "님*** " << "적립 포인트는 " << getPoint() << "점 입니다." << endl;
}

//매개변수로 전달받은 회원의 포인트를 내 포인트로 병합하고, 상대방의 포인트는 소멸시키는 함수구현
void Platinum::combine(Platinum& p) { 
	point += p.point; // 참조를 통해 원본객체의 포인트를 현재 나의 수치에 합산
	p.point = 0; //참조를 통해 상대방 원본객체의 포인트를 복사본이 아닌 '실제 원본'에서 0으로 초기화함
}