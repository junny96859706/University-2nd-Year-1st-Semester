#include <iostream>
#include <string>
using namespace std;

// ==================== 1. 부모 클래스 (기본 회원 담당) ====================
class Member {
protected:
	string name;
	int point = 0;
	int ratio;
public:
	Member(string name, int ratio = 1) {
		this->name = name; this->ratio = ratio;
	}

	// 💡 부모는 오직 자기가 해야 할 '기본 1% 적립'만 딱 신경쓴다!
	void earn(int pay) {
		point += (pay * ratio) / 100; 
	}

	int getPoint() { return point; }
	void show() {
		cout << name << "의 포인트 " << point << endl;
	}
};

// ==================== 2. 자식 클래스 (골드 회원 전담마크) ====================
class GoldMember : public Member {
public:
	GoldMember(string name, int ratio = 3) : Member(name, ratio) {}

	// 🌟 [오버라이딩] 부모의 earn을 무시하고, 골드만의 복잡한 규칙을 여기서 재정의
	void earn(int pay) {
		int current_ratio = ratio; // 기본 3%

		// 금액대별 적립률 변동 규칙 적용
		if (pay >= 100000) {
			current_ratio = 5;
		}
		else if (pay >= 20000) {
			current_ratio = 4;
		}

		point += (pay * current_ratio) / 100;
	}
};