#include <iostream>
using namespace std;

int main() {
	double* p = new double[5];
	double sum = 0;
	if (!p)
		return 0;
	cout << "온도 5개 입력>>";
	for (int i = 0; i < 5; i++) {
		cin >> p[i];
		sum += p[i];
	}
	cout << endl;

	double avg = sum / 5;
	cout << "평균은" << avg;
	
	delete[]p;
}