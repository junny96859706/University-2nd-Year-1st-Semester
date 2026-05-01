#include <iostream> //입출력 기능을 위한 라이브러리
using namespace std; //std 이름공간에 선언된 모든 이름에 std생략

#include "Polygon.h" //헤더파일 호출

Polygon::Polygon(int size) { //다각형을 만들고 점을 주소를 저장하기위해 동적할당을 하는 생성자 
	this->size = size; //점의 총수량을 클래스에 저장
	xList = new int[size]; //x좌표값들을 보관할 동적배열을 생성
	if (!xList) //동적생성 과정에서의 오류를 검사
		return; //할당실패시 추가작업을 중단하고 리턴
	yList = new int[size]; //y좌표값들을 보관할 동적배열을 생성
	if (!yList) //동적생성 과정에서의 오류를 검사
		return; //할당실패시 추가작업을 중단하고 리턴
}

Polygon::~Polygon() { //객체의 동적할당을 반환할 소멸자
	delete[]xList; //x좌표의 동적배열을 시스템에 반납
	delete[]yList; //y좌표의 동적배열을 시스템에 반납
}

void Polygon::read() { //점의 좌표값을 입력받고 저장하는 함수생성
	cout << "아래에 x,y값으로 6개의 점을 입력하세요." << endl; //사용자가 좌표값을 입력
	for (int i = 0; i < size; i++) { //각좌표값을 배열에 순서대로 저장하기 위한 반복문
		cin >> xList[i]; //입력받은 값을 해당순번의 x좌표로 저장
		cin >> yList[i]; //입력받은 값을 해당순번의 y좌표로 저장
	}
}

bool Polygon::get(int n, int &x, int &y) { //특정좌표값을 외부에 전달하여 저장하고 참거짓을 도출하는 함수get()생성
	
	if (n < 1 || n>size) //점의위치가 1보다 작거나 size보다 크지않도록 검증함
		return false; //유효하지 않을시 실패값을 리턴
	
	x = xList[n - 1]; //참조를 사용해 x값 원본에 해당점의 x좌표를 추출 
	y = yList[n - 1]; //참조를 사용해 y값 원본에 해당점의 y좌표를 추출
	return true; //성공적으로 좌표값이 전달됐음을 리턴
}