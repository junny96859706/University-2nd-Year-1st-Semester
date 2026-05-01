#include <iostream>
using namespace std;

class Storage {
	double fever[10];
	double sum = 0, avg = 0;
	int num = 0;
public:
	void put(double tmp);
	void dump();
	double getAvg();
};

void Storage::put(double tmp) {
	if (num > 9) {
		cout << "온도는 최대 10개까지만 입력이 가능합니다";
		return;
	}
	fever[num] = tmp;
	num++;
}

void Storage::dump() {
	for (int i = 0; i < num; i++)
		cout << fever[i] << " ";
	cout << endl;
}

double Storage::getAvg() {
	for (int i = 0; i < num; i++)
		sum += fever[i];
	avg = sum / num;
	return avg;
}
int main() {
	Storage a;
	a.put(36.7);
	a.put(36.9);
	a.put(36.4);
	a.dump();
	cout << "수현이의 평균 체온은" << a.getAvg() << "입니다" << endl;

}