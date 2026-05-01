#include <iostream>
using namespace std;

class Circle {
	int radius;
public:
	Circle() { this->radius = 1; }
	Circle(int radius) { this->radius = radius; }
	double getArea();
	void setRadius(int radius) { this->radius = radius; }
};

double Circle::getArea() {
	return 3.14 * radius * radius;
}

class CircleManager {
	int n; //원의 개수
	Circle* p;//Circle배열에 대한 포인터
	void input();
	void show();
	void decide();
public:
	void run();

};

void CircleManager::input() {
	//원개수를 입력받아 동적 할당
	cout << "생성하고자 하는 원의 개수?";
	cin >> n;
	p = new Circle[n];
	if (p == NULL)
		exit(0);

	//원 배열 입력
	for (int i = 0; i < n; i++) {
		cout << "원" << (i + 1) << ": ";
		int radius;
		cin >> radius;
		p[i].setRadius(radius);
	}
}

void CircleManager::show() {
	for (int i = 0; i < n; i++) {
		cout << p[i].getArea() << "\t";
	}
	cout << endl;
}

void CircleManager::decide() {
	for (int i = 0; i < n; i++) {
		double d = p[i].getArea();
		if (d > 100 && d < 200)
			cout << d << "\t";
	}
	cout << endl;
}

void CircleManager::run() {
	input();
	show();
	decide();
}

int main() {
	CircleManager* pMan = new CircleManager();
	pMan->run();
	delete pMan;
}