#ifndef LIGHT_H //LIGHT_H가 정의되어 있지 않다면 아래 내용을 포함
#define LIGHT_H //LIGHT_H를 정의하여 이 파일이 중복으로 읽히는 것을 방지

class Light { //빛을 추상화하여 관리하고 제어하기위한 클래스 Light 선언
	int light; //객체가 가지고 있는 빛의세기를 표현하는 정수형 변수
public: //외부에 공개하기위한 public접근지정자 지정
	Light(int light); //입력된 빛의값으로 세기를 설정하여 객체를 생성하는 생성자 
	Light(); //별도의 입력이 없을경우 기본밝기 1을 가진 객체를 생성하는 기본생성자

	Light& operator+=(Light& p); //상대객체의 빛의세기를 흡수하고, 자신의 상태를 반환하는 연산자 중복 
	Light& operator+=(int light); //빛의 세기를 정수값으로 직접받아 현재세기에 합산하는 연산자 중복

	void operator~(); //현재 객체가 가진 빛의세기를 출력하는 연산자~ 연산자중복
	Light operator--(int x); //세기를 1낮추지만 낮추기전의 세기를 반환하는 후위연산자 연산자중복

	friend bool operator ==(Light p, int x); //빛의 세기가 일치하는지 friend형태로 외부에서 판별하는 연산자중복 
};

#endif // LIGHT_H 정의의 끝