#include <iostream>
using namespace std;

template <class T>
bool add(T* array, int size, int push_size, T element) {
	if (push_size < size) {
		array[push_size] = element;
		return true;
	}
	else return false;
}

template <class T>
void print(T* array, int size) {
	for (int i = 0; i < size; i++) {
		cout << array[i] << ' ';
	}
	cout << endl;
}

int main() {
	int intArray[10] = { 1,2,3,4,5 };
	bool ret = add(intArray, 10, 5, 20); //intArray 크기가 10이고,원소5(여섯번째)에 20 저장
	if (ret == true)
		print(intArray, 6); //intArray에서 처음 6개의 원소 출력
	else
		cout << "삽입 실패" << endl;

	char charArray[6] = { 'C','+','+' };
	ret = add(charArray, 6, 3, '!'); //charArray크기가 6이고, 원소 3(4번째)에 '!' 문자 저장
	if (ret == true)
		print(charArray, 4); //charArray에서 4개의 원소 출력
	else
		cout << "삽입 실패" << endl;
}