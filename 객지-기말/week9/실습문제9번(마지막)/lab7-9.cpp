#include <iostream>
using namespace std;

class Chart {

};

int main() {
	Chart chart(100); //100개의 정수 저장이 가능한 차트 객체
	if (!chart)
		cout << "차트가 비었습니다" << endl;

	int n;
	cout << "정수 4개 입력>>";
	for (int i = 0; i < 4; i++) {
		cin >> n; //정수 입력
		chart << n; //chart에 입력받은 정수 저장
	}
	int avg = ~chart; //chart 데이터의 평균값 리턴
	cout << "평균은" << avg << endl;
	chart.show(); //현재 저장된 차트 데이터 출력

}