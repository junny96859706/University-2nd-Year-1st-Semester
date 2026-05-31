#include <iostream>
using namespace std;

class Schedule {
protected:
	int count; //jobs[]배열의 크기
	int* jobs; //방문한 아파트 동 번호를 저장할 배열
	int curLoc; //현재 택배 기사가 있는 동 번호
public:
	Schedule(int curloc, int n[], int count);
	~Schedule() {};
	int run(); //도착 순서대로 택배 처리
	int getJobs() { return count; }
	int getCurLoc() { return curLoc; }
};

Schedule::Schedule(int curloc, int n[], int count) {
	this->curLoc = curloc; this->jobs = n; this->count = count;
	cout << "현재 위치는 " << curloc << "동: " << "배달 시작 ..." << curloc;
	for (int i = 0; i < count; i++) {
		cout << " -> " << jobs[i];
	}
	cout << endl;
}

int Schedule::run() {
	int total = 0;
	total += ((jobs[0] - curLoc) > 0 ? (jobs[0] - curLoc) : -(jobs[0] - curLoc));
	curLoc = jobs[0];
	for (int i = 1; i < count; i++) {
		total += ((jobs[i] - curLoc)>0 ? (jobs[i] - curLoc) : -(jobs[i] - curLoc)); //삼항연산자 이용
		curLoc = jobs[i];
	}
	return total;
}

class ShortestFirst : public Schedule {
public:
	ShortestFirst(int curloc, int n[], int count); //생성자

	static int* change_array(int curloc,int n[], int count);
};

ShortestFirst::ShortestFirst(int curloc, int n[], int count) 
	: Schedule(curloc, change_array(curloc,n,count), count) {

}

//배열을 ShortestFirst방식에 맞춰서 배열을 재정렬시키는 함수
int* ShortestFirst::change_array(int curloc, int n[], int count) {
	//C++ 표준 문법에서 배열의 크기는 변수가 아니라 무조건 상수여야 함. 컴파일 시점에 크기를 알 수 없기 때문
	//컴파일 에러가 나지 않도록 변수(count) 크기만큼 메모리를 동적 할당.
	int* temp = new int[count];
	for (int i = 0; i < count; i++) {
		temp[i] = n[i];
	}
	int min = temp[0];
}

int main() {
	int jobs[6];
	cout << "택배를 픽업할 동을 요청 순서대로 6개 입력>>";
	for (int i = 0; i < 6; i++) 
		cin >> jobs[i]; //배달할 6개 동 번호 입력

	Schedule fcfs(10, jobs, 6); //현재 10동에 택배 기사 있음. 6은 jobs배열 크기
	cout << "전체 움직인 거리는" << fcfs.run() << ", ";
	cout << "현재 위치는 " << fcfs.getCurLoc() << "동" << endl;

	ShortestFirst sf(10, jobs, 6); //현재 10동에 택배기사 있음. 6은 jobs 배열 크기
	cout << "전체 움직인 거리는" << sf.run() << ", ";
	cout << "현재 위치는 " << sf.getCurLoc() << "동" << endl;

}

