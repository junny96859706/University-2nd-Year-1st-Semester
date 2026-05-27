#include <iostream>
#include <iomanip>
#include <cmath>
using namespace std;

int main() {
	cout << setw(15) << left << "Number";
	cout << setw(15) << left << "Square";
	cout << setw(15) << left << "Square root" << endl;


	for (int i = 0; i < 46; i += 5) {
		cout << setfill('_') << setw(15) << left << i;
		cout << setw(15) << i*i;
		cout << setprecision(3) << setw(15) << sqrt((double)i) << endl;
	}
}