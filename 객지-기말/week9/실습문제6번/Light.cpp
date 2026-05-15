#include <iostream> //표준 입출력기능을 활용하기위한 라이브러리
using namespace std; //std 이름공간에 선언된 모든 이름에 std생략

#include "Light.h" // 작성한 Light 클래스의 선언부인 헤더파일을 불러옴

Light::Light(int light) { //매개변수를 가지는 생성자 구현부
	this->light = light; //입력된 값을 해당객체의 빛의세기로 할당
}

Light::Light() { //클래스의 기본생성자 구현부 
	light = 1; //기본 에너지 상태를 1로 설정
}

//객체참조리턴을 통해 합산된 자기자신을 리턴하는 +=연산자 중복 구현부
Light& Light::operator+=(Light& p) { 
	light += p.light; //두 빛의 세기를 합산하여 자신의 값으로 저장
	p.light = 0; //합산당한 객체의 빛의세기를 0으로 설정함
	return *this; //수정된 객체자신을 반환하여 연쇄적인 연산을 가능하게 함
}

Light& Light::operator+=(int light) { //정수형태의 빛의 형태를 자신에게 합산하는 +=연산자 중복 구현부
	this->light += light; //두 빛의 세기를 합산하여 자신의 값으로 저장
	return *this; //수정된 객체자신을 반환하여 연쇄적인 연산을 가능하게 함
}

void Light::operator ~() { //a.operator~()형태로 컴파일러가 변환,빛의크기를 출력하는 ~ 연산자중복
	cout << "빛 크기 " << light << endl; //현재 빛의 세기를 텍스트로 출력함
}

Light Light::operator--(int x) { //후위연산자로서 전위연산자와 비교하기위해 매개변수값을 포함
	Light temp; //세기가 줄어들기전의 밝기를 임시로 보관할 임시객체 생성
	temp = *this; //임시객체의 기존 자신의 값을 저장함
	--light; //빛의세기를 1단계 줄임
	return temp; //참조리턴을 할시 소멸되는 객체를 리턴하기에 객체리턴 실시.
}

bool operator ==(Light p, int x) { //operator==(p,x)형태로 컴파일러가 변환,객체외부에 friend형태로 선언
	if (p.light == x) //객체p의 빛의 세기와 x가 같은지 판단
		return true; //수치가 일치한다면 true값을 리턴
	else //객체p의 빛의 세기와 x가 같지 않은 경우
		return false; //수치가 일치하지 않으므로 false값을 리턴
}