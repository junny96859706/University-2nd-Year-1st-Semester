#include <iostream>
using namespace std;

class Bubble {
public:
	int radius; //combineBubble()함수에서 쓰기위해서 radius도 pravite형식이 아닌 public형식으로 작성했다!
	Bubble(int radius) { this->radius = radius; }
	int getRadius() { return radius; }
	void setRadius(int radius) { this->radius = radius; }
	Bubble& addBubble(Bubble y) 
	{
		radius += y.getRadius();
		return *this;
	}
};

bool combineBubble(Bubble& x, Bubble& y) {  //함수를 main에서 그냥 선언했으므로 객체밖에 두었다.
	if (x.getRadius() > y.getRadius()) {
		x.radius = x.getRadius() + y.getRadius();
		y.setRadius(0);
		return true;
	}
	else if (x.getRadius() < y.getRadius()) {
		y.radius = x.getRadius() + y.getRadius();
		x.setRadius(0);
		return true;
	}
	else //else에는 조건문이 올수없다!!!!!
		return false;
}


int main() {
	Bubble a(5), b(10), c(130);
	c.addBubble(a).addBubble(b).addBubble(Bubble(200));
	cout << c.getRadius() << endl;

	if (combineBubble(a,b) == false)
		cout << "두버블의 크기가 같음" << endl;
	else
		cout << "큰 쪽으로 병합됨" << endl;
	cout << "버블 a의 반지름 " << a.getRadius() << endl;
	cout << "버블 b의 반지름 " << b.getRadius() << endl;
}