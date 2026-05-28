#include <iostream>
using namespace std;

class Matrix {
	int x1, x2, x3, x4;
public:
	Matrix(int x1 = 0, int x2 = 0, int x3 = 0, int x4 = 0) {
		this->x1 = x1;  this->x2 = x2;
		this->x3 = x3;  this->x4 = x4;
	}
	void show() {
		cout << "Matrix = " << "{ " << x1 << " " << x2 << " " << x3 << " " << x4 << " }" << endl;
	}

	Matrix& operator>>(int* x);
	friend Matrix& operator<<(Matrix& p, int* y);
};

Matrix& Matrix::operator>>(int* x) {
	x[0] = x1; x[1] = x2;
	x[2] = x3; x[3] = x4;
	return *this;
}

Matrix& operator<<(Matrix& p, int* y) {
	p.x1 = y[0]; p.x2 = y[1];
	p.x3 = y[2]; p.x4 = y[3];
	return p;
}


int main() {
	Matrix a(4, 3, 2, 1), b;
	int x[4], y[4] = { 1,2,3,4 }; //2차원 행렬의 4개의 원소값
	a >> x; //a의 각 원소를 배열 x에 복사, x[]는 {4,3,2,1}
	b << y; //배열y의 원소값을 b의 각 원소에 설정

	for (int i = 0; i < 4; i++) {
		cout << x[i] << ' '; //x[]출력
	}

	cout << endl;
	b.show();
}