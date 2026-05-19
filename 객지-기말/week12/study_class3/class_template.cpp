#include <iostream>
#include <string>
using namespace std;

template <class T>
class MyStack {
	T data[100];
	int tos; //(top of stack)
public:
	MyStack();
	void push(T element);
	T pop();
};

template <class T>
MyStack<T>::MyStack() {
	tos = -1;
}

template <class T>
void MyStack<T>::push(T element) {
	if (tos == 99) {
		cout << "full" << endl;
		return;
	}
	tos++;
	data[tos] = element;
}

template <class T>
T MyStack<T>::pop() {
	if (tos == -1) {
		cout << "empty" << endl;
		return 0;
	}
	T ret = data[tos];
	tos--;
	return ret;
}

int main() {
	MyStack<int> iStack;
	iStack.push(3);
	iStack.push(5);
	iStack.push(8);

	for (int i = 0; i < 3; i++) {
		int x = iStack.pop();
		cout << x << endl;
	}

	MyStack<string> sStack;
	sStack.push("I");
	sStack.push("love you");

	for (int i = 0; i < 2; i++) {
		string x = sStack.pop();
		cout << x << endl;
	}
}