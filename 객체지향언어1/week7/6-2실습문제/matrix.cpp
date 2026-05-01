#include <iostream>
using namespace std;

void printMatrix(int h=2,int w=2,char a='*') {
	for (int i = 0; i < h; i++) {
		for (int j = 0; j < w; j++)
			cout << a;
		cout << endl;
	}
}

int main() {
	printMatrix();
	printMatrix(2,5,'a');
	printMatrix(1,10);
}