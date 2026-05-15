#include <iostream> //표준 입출력기능을 활용하기위한 라이브러리
#include <string> //회원의 이름을 string형태로 처리하기 위한 헤더
using namespace std; //std 이름공간에 선언된 모든 이름에 std생략

#include "Platinum.h"

int main() {
	Platinum hwang("황기태", 5, 100000, 7), park("박채원", 5, 100000, 7);
	//생성자 의미:100000원 까지는 5%, 그보다 큰경우 7%

	hwang.earn(50000); //50000원 지출경우, 2500원 포인트 적립
	hwang.earn(200000); //200000원 지출경우, 14000원 포인트 적립
	park.earn(500000); //500000원 지출경우, 35000원 포인트 적립
	hwang.show();
	park.show(); //현재 누적 포인트 출력

	hwang.combine(park); //hwang회원에 park의 포인트 결합
	hwang.show();
	park.show();
}