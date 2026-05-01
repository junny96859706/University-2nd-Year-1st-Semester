#include <iostream>
using namespace std;

int main() {
	int n = 0;
	cout << "구입할 물품의 개수>>";
	cin >> n;

	int* p = new int[n];
	if (!p)
		return 0;
	cout << "물품 " << n << "개의 가격입력 >> ";
	for (int i = 0; i < n; i++) {
		cin >> p[i];
	}
	
	
	int high = p[0];
	int low = p[0];
		for (int i = 0; i < n; i++) {
			if (high < p[i])
				high = p[i];
			if (low > p[i])
				low = p[i];
		}
	
	cout << "제일 싼 가격은 " << low << endl;
	cout << "제일 비싼 가격은" << high;
	delete[]p;

	return 0;
}