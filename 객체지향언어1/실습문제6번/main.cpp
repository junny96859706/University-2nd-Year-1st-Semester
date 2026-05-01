#include <iostream> //﻿입출력 기능을 위한 라이브러리
using namespace std; //﻿std 이름공간에 선언된 모든 이름에 std생략

#include "Polygon.h" //헤더파일 호출

int main() { //메인함수호출

	Polygon poly(6); //6개의 점을 가지는 육각형객체 생성
	poly.read(); //육각형의 각점의 좌표를 입력받아 저장
	int n = 3, x, y; //3번째좌표를 입력받기위한 int형공간을 생성
	bool res = poly.get(n, x, y); //객체의 3번째 좌표값을 x와y에 입력받고, 성공여부를 res에 저장

	if (res == true) //좌표값이 잘 입력받아졌을지의 조건문
		cout << n << "번째 점은" << "(" << x << "," << y << ")" << endl; //3번째 점의 좌표값을 출력
	else //요청한 좌표값이 존재하지 않을때의 조건문
		cout << n << "번째 점은 없습니다." << endl; //입력에 오류가 있음을 출력

}