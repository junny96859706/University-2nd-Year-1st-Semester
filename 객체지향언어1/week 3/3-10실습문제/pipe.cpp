#include <iostream>
using namespace std;

class Pipe{
	int data[10]; //파이프 내 저장공간
	int index; //도착하는 정수를 저장할 위치를 나타내는 data[]배열의 인텍스
	int del = 0;;
public:
	Pipe();
	int arrive(int n);
	int shift();
	void show();
};

Pipe::Pipe() {
	for (int i = 0; i < 10; i++)
		data[i] = 0;
	index = 0;
}

int Pipe::arrive(int n) {

	if (index == 10) {
		del = data[0];
		for (int i = 0; i < 9; i++) {
			data[i] = data[i + 1];
		}
			data[9] = n;
			return del;
	}
	data[index] = n;
	index++;
	return -1;
}

int Pipe::shift() {
	del = data[0];
	for (int i = 0; i < 9; i++) {
		data[i] = data[i + 1];
	}
	data[9] = 0;
	index--;
	return del; 
}

void Pipe::show() {
	cout << "파이프내부 [";
	for (int i = 0; i < 10; i++) {
		cout << data[i] << " ";
	}
	cout << "]" << endl;
}

int main() {
	Pipe pipe;
	for (int i = 0; i < 6; i++)
		pipe.arrive(i);
	pipe.show();
	for (int i = 6; i < 12; i++)
		pipe.arrive(i);
	pipe.show();
	int front = pipe.shift();
	cout << "shift()로 제거된 맨 앞 데이터:  " << front << endl;
	pipe.show();
	front = pipe.arrive(50);

	cout << "arrive(50)로 제거된 맨 앞 데이터" << front << endl;
	pipe.show();
}