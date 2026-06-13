#include <iostream>
using namespace std;

template <class T>
class Mystack {
	int top;
	T data[100];
public:
	Mystack();
	void push(T element);
	T pop();
};

template <class T>
Mystack<T>::Mystack() {
	top = -1;
}

template <class T>
void Mystack<T>::push(T element) {
	if (top == 99)
		return;
	data[++top] = element;
}

template <class T>
T Mystack<T>::pop() {
	if (top == -1)
		return T(); //T의 기본값(0, NULL 등)을 생성해서 리턴하는 안전한 방법!
	return data[top--];
}

int main() {
	Mystack<int> iStack;
	iStack.push(3);
	cout << iStack.pop() << endl;

	Mystack<double> dStack;
	dStack.push(3.5);
	cout << dStack.pop() << endl;

	Mystack<char>* p = new Mystack<char>();
	p->push('a');
	cout << p->pop() << endl;
	delete p;
}