#include <iostream>
#include <vector>
using namespace std;

//1. 데이터와 기능을 하나로 묶는 클래스 선언
class VectorManager {
    //원본 데이터는 외부로부터 철저히 보호.
    vector<int> array;
    vector<int>::iterator it;

    //내부에서만 쓰이는 보조 함수 (const를 붙여 원본 변형 방지)
    int getBiggest() const {
        int temp = array[0];
        for (int i = 0; i < array.size(); i++) {
            if (temp < array[i]) temp = array[i];
        }
        return temp;
    }

public:
    //2. 외부(main)에서 호출할 수 있는 공개 기능들 (인터페이스)

    // 초기 10개 입력받기
    void inputInitialData() {
        cout << "10개의 정수 입력>>";
        for (int i = 0; i < 10; i++) {
            int num; cin >> num;
            array.push_back(num);
        }
    }

    // 1번: 가장 큰 값 출력
    void printBiggest() const {
        // 내부 함수인 getBiggest()를 호출해서 결과를 보여줌.
        cout << "가장 큰 값 " << getBiggest() << endl;
    }

    // 2번: 평균 출력
    void printAverage() const {
        int sum = 0;
        for (int i = 0; i < array.size(); i++) {
            sum += array.at(i);
        }
        cout << "평균 " << (double)sum / array.size() << endl;
    }

    // 3번: 삽입
    void insertValue() {
        int add;
        cout << "삽입할 값>>";
        cin >> add;
        array.push_back(add);
    }

    // 4번: 삭제
    void deleteValue() {
        int delete_num;
        cout << "삭제할 값>>";
        cin >> delete_num;
        for (int i = 0; i < array.size(); i++) {
            if (array[i] == delete_num) {
                it = array.begin() + i;
                it = array.erase(it);
                i--;
            }
        }
        printAll(); // 삭제 후 결과 보여주기
    }

    // 5번: 몇 배로 증가
    void increaseValues() {
        int increase;
        cout << "몇배로 증가>>";
        cin >> increase;
        for (int i = 0; i < array.size(); i++) {
            array.at(i) *= increase;
        }
        printAll();
    }

    // 공통 출력 함수
    void printAll() const {
        for (int i = 0; i < array.size(); i++) {
            cout << array.at(i) << " ";
        }
        cout << endl;
    }
};

//3. main 함수는 흐름 제어만 담당 (매우 직관적이고 깔끔해짐)
int main() {
    VectorManager manager; // 관리자 객체 생성
    manager.inputInitialData();

    while (true) {
        int choise;
        cout << "가장 큰 값:1, 평균:2, 삽입:3, 삭제:4, 증가:5, 종료:6>>";
        cin >> choise;

        switch (choise) {
        case 1: manager.printBiggest(); break;
        case 2: manager.printAverage(); break;
        case 3: manager.insertValue();  break;
        case 4: manager.deleteValue();  break;
        case 5: manager.increaseValues(); break;
        case 6: cout << "시스템을 종료합니다" << endl; return 0;
        }
    }
    return 0;
}