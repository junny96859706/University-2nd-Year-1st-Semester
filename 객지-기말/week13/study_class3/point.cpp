#include <iostream>
#include <string>
using namespace std;

class Point {
	int x, y;
public:
	Point(int x, int y) { this->x = x; this->y = y; }
	friend ostream& operator << (ostream& out, Point p);
	friend istream& operator >> (istream& in, Point& p);
};

ostream& operator << (ostream& out, Point p) {
	out << "(" << p.x << "," << p.y << ")" << endl;
	return out;
}

istream& operator >> (istream& in, Point& p) {
	cout << "x=";
	in >> p.x;
	cout << "y=";
	in >> p.y;

	return in;
}

void show(string x) {
	cout << x << endl;
}

void print() {
	cout << "hello2" << endl;
}

ostream& fivestar(ostream& out) {
	out << "*****";
	return out;
}

ostream& beep(ostream& out) {
	out << '\a';
	return out;
}

istream& question(istream& in) {
	cout << "거울아거울아 누가 제일 예쁘니>> ";
	return in;
}

int main() {
	string answer;
	cin >> question >> answer;
	cout << "제일 예쁜건 " << answer << endl;
	cout << fivestar << beep << endl;
}