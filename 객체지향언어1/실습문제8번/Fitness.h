#ifndef FITNESS_H ﻿  //헤더파일의 중복사용 방지를 위한 조건문
#define FITNESS_H   ﻿//헤더의 식별자 등록
#include <string>

class Fitness { //헬스장 회원인원을 관리하는 클래스
	int man = 0, woman = 0, error = 0; //남성 및 여성인원수를 저장하는 내부변수 및 오류을 나타내는 변수 초기화
public: //외부에 공개하기위한 public 접근지정자 설정
	Fitness& arrive(std::string Gender, int mw); //회원을 추가하고 연속호출을 하기위해 객체참조리턴
	int& at(std::string Gender); //특정성별의 인원수를 직접 반환하기 위한 int형 참조함수
	void count(std::string Gender, int& mw); //현재인원수를 외부변수에 그대로 가져오기위한 함수
};

#endif ﻿//헤더 영역 종료