#include <iostream>
using namespace std;
#define MAX 10
//스택구현(last in first out)

class AbstractStack {
public:
	virtual bool push(int n) = 0; //스택에 n을 푸시한다. 스택이 full이면 false리턴
	virtual bool pop(int& n) = 0; //스택에서 팝한 정수를 n에 리턴한다. 스택에 empty이면 false리턴

	virtual int size() = 0; //현재 스택에 저장된 정수의 개수 리턴
};

class IntStack : public AbstractStack {
protected:
	int top = -1;
	int data[MAX];
public:
	IntStack() {
		for (int i = 0; i < MAX; i++) {
			data[i] = 0;
		}
	}
	virtual bool push(int n); //스택에 n을 푸시한다. 스택이 full이면 false리턴
	virtual bool pop(int& n); //스택에서 팝한 정수를 n에 리턴한다. 스택에 empty이면 false리턴
	virtual int size(); //현재 스택에 저장된 정수의 개수 리턴
};

bool IntStack::push(int n) {
	if (top >= MAX-1)
		return false;
	else {
		top++;
		data[top] = n;
		return true;
	}
}

bool IntStack::pop(int& n) {
	if (top == -1)
		return false;
	else {
		n = data[top];
		top--;
		return true;
	}
}

int IntStack::size() {
	int temp = top + 1;
	return temp;
}

int main() {
	IntStack a;
	for (int i = 0; i < 6; i++) {
		a.push(i + 5);
	}

	int n;
	a.pop(n);
	cout << "pop된 스택의 숫자는 " << n << "입니다." << endl;
	cout << "스택의 갯수는" << a.size() << "개 입니다." << endl;

}