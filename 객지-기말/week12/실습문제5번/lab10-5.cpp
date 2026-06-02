#include <iostream>
#include <vector>
using namespace std;

double score_avg(vector<string> &v, double n) { //참조로 받는거 잊지 않기!!!(효울성)
	double sum = 0, myscore;
	for (int i = 0; i < n; i++) {
		if (v[i] == "A+") myscore = 4.5;
		else if (v[i] == "A") myscore = 4.0;
		else if (v[i] == "B+") myscore = 3.5;
		else if (v[i] == "B") myscore = 3.0;
		else if (v[i] == "C+") myscore = 2.5;
		else if (v[i] == "C") myscore = 2.0;
		else if (v[i] == "D+") myscore = 1.5;
		else if (v[i] == "D") myscore = 1.0;
		else if (v[i] == "F") myscore = 0;
		else myscore = 0; //안해주면 오타시에 이전 myscore값이 합산 될수 있다!!!

		sum += myscore;
	}
	return sum / n;
}

int main() {
	vector<string> score;
	string temp;
	
	cout << "6과목의 학점 입력>>";
	for (int i = 0; i < 6; i++) {
		cin >> temp;
		score.push_back(temp);
	}

	cout << "학점 평균은 " << score_avg(score,6) << endl;
}