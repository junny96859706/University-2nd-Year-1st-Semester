#include <iostream>
using namespace std;

class Chart {
	int* chart;
	int num, count = 0;
public:
	Chart(int num) {
		this->num = num;
		chart = new int[num]; //() 동적배열할당시 ()붙이면 내부 값이 0으로 초기화 된다!!
		for (int i = 0; i < num; i++) {
			chart[i] = NULL;
		}
	}

	~Chart() {
		delete[] chart; //동적 배열 안전하게 반납!
	}

	void show() { 
		for (int i = 0; i < count; i++) {
			cout << chart[i] << "\t";
		}
	}

	bool operator!();
	friend Chart& operator<<(Chart& p, int n);
	int operator~();
};

bool Chart::operator!() {
	for (int i = 0; i < num; i++) {
		if (chart[i] != NULL)
			return false;
	}
	return true;
}

Chart& operator<<(Chart& p, int n) {
	p.chart[p.count] = n;
	p.count++;
	return p;
}

int Chart::operator~() {
	int sum = 0;
	for (int i = 0; i < count; i++) {
		sum += chart[i];
	}
	return (sum / count);
}

int main() {
	Chart chart(100); //100개의 정수 저장이 가능한 차트 객체 //여기서 chart는 객체이름!!
	if (!chart) //chart.operator!();
		cout << "차트가 비었습니다" << endl;

	int n;
	cout << "정수 4개 입력>>";
	for (int i = 0; i < 4; i++) {
		cin >> n; //정수 입력
		chart << n; //chart에 입력받은 정수 저장 //operator<<(chart,n)으로 해석
	}
	int avg = ~chart; //chart 데이터의 평균값 리턴
	cout << "평균은" << avg << endl;
	chart.show(); //현재 저장된 차트 데이터 출력

}