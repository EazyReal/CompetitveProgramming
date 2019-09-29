/*
By NCTU_Oimo, contest: 2018 Benelux Algorithm Programming Contest (BAPC 18), problem: (A) A Prize No One Can Win, Accepted, #
*/

#include <bits\stdc++.h>
using namespace std;
int main() {
    int n, X; cin >> n >> X;
    vector<int> items(n);
    for (int i = 0; i < n; i++) cin >> items[i];
    sort(items.begin(), items.end());
    int i = 0;
    for (i = 0; i < n; i++) {
        if (i == 0) continue;
        else if (i >= 1 and items[i]+items[i-1]<=X) continue;
        else break;
    }
    cout << i << endl;
}
