#include <iostream>
#include <cmath>
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
	jobs = new int[count]; //동적배열할당
	for (int i = 0; i < count; i++) {
		jobs[i] = n[i];
	}

	this->curLoc = curloc;  this->count = count;
	cout << "현재 위치는 " << curloc << "동: " << "배달 시작 ..." << curloc;
	for (int i = 0; i < count; i++) {
		cout << " -> " << jobs[i];
	}
	cout << endl;
}

int Schedule::run() {
	int total = 0;
	total += abs(jobs[0] - curLoc);
	curLoc = jobs[0];
	for (int i = 1; i < count; i++) {
		total += (jobs[i] - curLoc); 
		curLoc = jobs[i];
	}
	return total;
}

//--------------------------------------------------------------------------------//

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
	int* temp = new int[count+1]; //curloc포함 7개변수 저장 가능한 동적배열
	
	//1.최솟값으로 정렬하고 curloc값 넣기
	//이중for문으로 제일 작은값을 배열 처음에 넣어가기
	for (int i = 0; i < count; i++) {
		int min = n[i];
		int index = i;
		for (int j = i; j < count; j++) {
			if (n[j] < min) {
				min = n[j];
				index = j;
			}
		}

		int temp = n[i];
		n[i] = n[index];
		n[index] = temp;
	}
	// n= {3,7,9,12,16,25} 이렇게 최솟값부터 정렬시키고 curloc값을 중앙에 넣은다음 양옆을 비교하는 알고리즘
	//주혁이:배열 하나 만들어서 curLoc - n[i] 뺀값들을 넣어, 그다음에 최소값을 찾아 배열 돌아서 그다음에 그 인덱스를 curLoc으로 하고 jobs에 넣음 이렇게 했음


	//2.curloc과 가까운 값을 다음 목적지로 설정하고, 해당목적지를 curloc으로 설정
	// n= {3,7,9,  [10]  ,12,16,25}


	 
	
	//3.재정렬된 배열을 기존배열에 복사하고 주소리턴
	int min = temp[0];



	for (int i = 0; i < count; i++) {
		temp[i] = n[i]; //배열복사
	}
	return n;
}

//------------------------------------------------------------------------------------------------//

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

