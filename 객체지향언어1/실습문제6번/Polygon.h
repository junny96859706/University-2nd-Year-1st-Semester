#ifndef POLYGON_H //헤더파일의 중복사용 방지를 위한 조건문
#define POLYGON_H //헤더의 식별자 등록

class Polygon { //다각형을 나타내는 클래스선언
	int size = 0; //다각형의 점의 갯수를 저장하는 size변수 생성 및 값 초기화
	int* xList, * yList; //각 점의 좌표를 보관할 주소생성
public: //외부에 공개하기위한 public접근지정자 지정
	Polygon(int size); //개수에 맞는 다각형 객체를 생성하는 생성자 
	~Polygon(); //동적할당반환을 위한 소멸자 지정
	void read(); //점의 좌표를 얻어 저장하는 함수
	bool get(int size, int& x, int& y); //특정위치의 정보를 저장하는 함수
};

#endif //헤더 영역 종료
