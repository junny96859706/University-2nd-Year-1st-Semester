#include <iostream>
using namespace std;

template <class T>
class MyStack {
	int tos; //(top of stack)
	T data[100];
public:
	MyStack();
	void push(T element);
	T pop();
	int size();
};

template<class T>
int MyStack<T>::size() {
	return tos + 1;
}

template <class T>
MyStack<T>::MyStack() {
	tos = -1; //tos는 현재 스택의에 저장된 데이터의 인덱스
}
template <class T>
void MyStack<T>::push(T element) {
	if (tos == 99) { //full
		cout << "full" << endl;
		return;
	}
	tos++;
	data[tos] = element;

}

template <class T>
T MyStack<T>::pop() {
	T ret;

	if (tos == -1) {
		cout << "empty" << endl;
		return 0;
	}
	ret = data[tos];
	tos--;
	return ret;
}

int main() {
	MyStack<int> iStack;
	iStack.push(3);
	cout << iStack.pop() << endl;

	MyStack<double> dStack;
	dStack.push(3.5);
	cout << dStack.pop() << endl;

	MyStack<string> sStack;
	sStack.push("여러분");
	sStack.push("어떻게 사는지");
	sStack.push("궁금해요");
	sStack.push("공부 잘하고 있겠죠");
	int n = sStack.size();
	for (int i = 0; i < n; i++) {
		cout << sStack.pop() << endl;
	}

}