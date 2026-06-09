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
		cout << "{ " << x1 << " " << x2 << " " << x3 << " " << x4 << " }" << endl;
	}

	Matrix operator+(Matrix& p);
	Matrix& operator+=(Matrix& p);
	friend bool operator==(const Matrix& p,const Matrix& q);
};

Matrix Matrix::operator+(Matrix& p) {
	Matrix temp;
	temp.x1 = this->x1 + p.x1;
	temp.x2 = this->x2 + p.x2;
	temp.x3 = this->x3 + p.x3;
	temp.x4 = this->x4 + p.x4;
	return temp;
}

Matrix& Matrix::operator+=(Matrix& p) {
	this->x1 += p.x1;
	this->x2 += p.x2;
	this->x3 += p.x3;
	this->x4 += p.x4;
	return *this;
}

bool operator==(const Matrix& p,const Matrix& q) {
	if (p.x1 == q.x1 && p.x2 == q.x2 && p.x3 == q.x3 && p.x4 == q.x4)
		return true;
	else
		return false;
}

int main() {
	Matrix a(1, 2, 3, 4), b(2, 3, 4, 5), c;
	c = a + b;
	a += b;
	a.show(); b.show(); c.show();
	if (a == c) {
		cout << "a와 c는 같습니다." << endl;
	}
}