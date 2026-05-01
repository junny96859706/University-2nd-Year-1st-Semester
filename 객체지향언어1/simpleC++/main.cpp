#include <iostream>
//using std::cout; //std::cout에 대해서만 안쓸수 있다!!!
using namespace std;
int f(); //선언부

int main() {
	int width, height;
	cout << "너비는?";
	cin >> width;

	cout << "높이는?";
	cin >> height;

	int area = width * height;
	cout << "면적은" << area << endl;
	
}