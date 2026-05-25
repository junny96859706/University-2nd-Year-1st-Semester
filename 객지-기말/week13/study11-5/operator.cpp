#include <iostream>
using namespace std;

class Point {
	int x, y;
public:
	Point(int x=0, int y=0) {
		this->x = x;
		this->y = y;
	}

	friend ostream& operator <<(ostream& s, Point p);
	friend istream& operator >> (istream& s, Point& p);
};

ostream& operator <<(ostream& s, Point p) {
	s << "(" << p.x << "," << p.y << ")" << endl;
	return s;
}

istream& operator >> (istream& s, Point& p) {
	cout << "x좌표:";
	s >> p.x;
	cout << "y좌표:";
	s >> p.y;

	return s;
}

int main() {
	//Point p(3, 4), q(5, 6);
	Point p, q;
	cin >> p;  //>>(cin, p);
	cin >> q;  //>>(cin,q);
	cout << p << q;  //<<(cout,p)
}