#include <iostream>
#include <string>
using namespace std;

//선언부----------------------------------------------//
class picture {
	int width;
	int height;
	string place;
public:
	picture();
	picture(int w, int h, string pl);
	int getwidth();
	int getheight();
	string getplace();
};

//구현부------------------------------------------//
picture::picture() {
	width = 5; height = 7; place = "모름";
}

picture::picture(int w, int h, string pl) {
	width = w; height = h; place = pl;
}

int picture::getwidth() { return width; }
int picture::getheight() { return height; }
string picture::getplace() { return place; }

//메인함수-------------------------------------------//

int main() {
	picture pic; //5x7크기, 촬영장소"모름"
	picture mt(10, 14, "한라산"); //10x14크기,촬영장소"한라산
	cout << pic.getwidth() << "x" << pic.getheight() << " " << pic.getplace() << endl;
	cout << mt.getwidth() << "x" << mt.getheight() << " " << mt.getplace() << endl;
}