/*
By NCTU_Oimo, contest: 2018 Benelux Algorithm Programming Contest (BAPC 18), problem: (J) Janitor Troubles, Accepted
*/

#include <bits\stdc++.h>
using namespace std;
int main() {
    long double s1, s2, s3, s4;
    cin >> s1 >> s2 >> s3 >> s4;
    long double mxA = 0;
    long double cosA = (s1*s1+s2*s2-s3*s3-s4*s4)/2./(s1*s2+s3*s4);
    if (fabs(cosA) <= 1.0) {
        mxA = max(mxA, (s1*s2+s3*s4)*sqrt(1-cosA*cosA));
    }
    cosA = (s1*s1+s3*s3-s2*s2-s4*s4)/2./(s1*s3+s2*s4);
    if (fabs(cosA) <= 1.0) {
        mxA = max(mxA, (s1*s3+s2*s4)*sqrt(1-cosA*cosA));
    }
    cout.precision(15);
    cout << fixed << mxA / 2. << endl;
}
