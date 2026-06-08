#include <iostream>
using namespace std;

template <class G>
class G_array {
	G buf[100];
public:
	void set_val(int idx, G val) {
		buf[idx] = val;
	}

	G get_val(int idx) {
		return buf[idx];
	}
};


int main() {

	G_array<int> I;
	G_array<double> D;
	G_array<char> C;

	I.set_val(0, 100);
	D.set_val(0, 10.5);
	C.set_val(0, 'A');

	cout << C.get_val(0) << endl;
}