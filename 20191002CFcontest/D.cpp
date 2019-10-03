//By NCTU_Oimo, contest: NCTU PCCA [191002], problem: (D) Mushroom Scientists, Accepted, #

#include <iostream>
using namespace std;
int main() {
	long double S; cin >> S;
	long double a, b, c; cin >> a >> b >> c;
	cout.precision(20);
	cout << fixed;
	if (a + b + c == 0) cout << S << " " << 0 << " " << 0 << endl;
	else cout << a / (a + b + c) * S << " " << b / (a + b + c) * S << " " << c / (a + b + c) * S << endl;
}
