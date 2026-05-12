#include <iostream>
using namespace std;

class Converter {
private:
	string srcUnit, destUnit; //단위를 나타내는 문자열(예:"원","달러")
protected:
	double ratio;
	virtual double convert(double src) {
		return 0.0;
	}
public:
	Converter(string sUnit, string dUnit, double ratio) { //생성자
		srcUnit = sUnit;
		destUnit = dUnit;
		this->ratio = ratio;
	}

	void run() {
		cout << srcUnit << "을" << destUnit << "로 바꿉니다, ";
		cout << srcUnit << "을 입력하세요>>";
		double src;
		cin >> src;
		cout << convert(src) << destUnit << "입니다." << endl;
	}
};

class Inch2Centimeter : public Converter {
protected:
	virtual double convert(double src) {
		return src * ratio;
	}
public:
	Inch2Centimeter(string sUnit, string dUnit, double ratio)
		: Converter(sUnit,dUnit,ratio){ }
};

int main() {
	Inch2Centimeter i2m("inch", "cm", 2.54); //1 inch는 2.54cm
	i2m.run();
}	