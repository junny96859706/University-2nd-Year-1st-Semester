#include <iostream> //입출력기능을 위한 <iostream>해더파일 호출
using namespace std; //std 이름공간에 선언된 모든 이름에 std생략

//생성부------------------------------------------//
class Coffee { //물,커피,설탕의 양을 관리하는 Coffee클래스 생성
	int coffee; int sugar; int milk; int water;  //현재 남아있는 커피,설탕,우유,물의 양을 나타내는 변수
public: ////외부에 공개하기 위해서 public접근지정자를 지정
	void show(); //재료의 상태를 화면에 보여주는 show함수 생성 
	Coffee(); //기본상태로 생성되는 생성자1을 생성
	Coffee(int c, int s, int m, int w); //직접 재료를 입력받아서 생성하는 생성자2 생성
};

//구현부-------------------------------------------//
Coffee::Coffee() { //기본상태일때 재료의값을 받는 생성자1을 구현하는 함수
	coffee = 10; sugar = 0; milk = 0; water = 0; //생성자1 작동시 커피10 설탕0 우유0 물0으로 변수공간할당
}

Coffee::Coffee(int c, int s, int m, int w) { //재료의 값을 직접입력받아서 재료상태를 설정하는 생성자2 구현
	coffee = c; sugar = s; milk = m; water = w; //생성자2 작동시 커피c 설탕s 우유m 물w으로 변수공간할당
}

void Coffee::show() { //현재재료의 양을 시작적으로 표현해주는 show()함수 구현
	int i; //for문 사용을 위해서 변수i 지정
	cout << "coffee"; //"Coffee"라는 단어를 출력
	for (i = 0; i < coffee;  i++) { //i를 1씩늘려가며 sugar보다 작을때까지for 반복문 구동
		cout << "*"; //반복문 실행시 "*"단어를 출력
	}
	cout << endl; //줄바꿈을 출력

	cout << "sugar"; //"sugar"라는 단어를 출력
	for (i = 0; i < sugar; i++) { //i를 1씩늘려가며 sugar보다 작을때까지for 반복문 구동
		cout << "*"; //반복문 실행시 "*"단어를 출력
	}
	cout << endl; //줄바꿈을 출력

	cout << "milk"; //"milk"라는 단어를 출력
	for (i = 0; i < milk; i++) { //i를 1씩늘려가며 sugar보다 작을때까지for 반복문 구동
		cout << "*"; //반복문 실행시 "*"단어를 출력
	}
	cout << endl; //줄바꿈을 출력
	
	cout << "water"; //"water"라는 단어를 출력
	for (i = 0; i < water; i++) { //i를 1씩늘려가며 sugar보다 작을때까지for 반복문 구동
		cout << "*"; //반복문 실행시 "*"단어를 출력
	}
	cout << endl; //줄바꿈을 출력
}

//메인함수-------------------------------------------//
int main() {
	Coffee espresso; //커피10 설탕0 우유0 물0으로 만든 커피
	Coffee americano(5, 0, 0, 10); //커피5 물10으로 만든 커피
	Coffee cappucchino(5, 1, 5, 2); //커피5 설탕1 우유5 물2로 만든 커피
	Coffee mySweet(3, 7, 5, 5); //커피3 설탕7 우유5 물5로 만든커피

	espresso.show(); //기본커피의 상태를 시각적으로출력
	cout << endl; //출력을 구분하기위해서 줄바꿈
	mySweet.show(); //mysweet객체의 커피상태를 시작적으로 출력
}