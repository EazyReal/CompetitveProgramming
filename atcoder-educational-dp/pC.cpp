#include <bits/stdc++.h>
#define pb push_back
#define ll long long
using namespace std;

//can use O(1) memory 

int T, n;
const int maxn = 100000+5;

int dpa, dpb, dpc, a, b, c;
int ta, tb, tc;

int main(){
	ios::sync_with_stdio(false);
	cin.tie(0); cout.tie(0);
	cin >> n;
	dpa = dpb = dpc = 0;
	for(int i = 0; i < n; i++)
	{
		cin >> a >> b >> c;
		ta = max(dpb, dpc)+a;
		tb = max(dpa, dpc)+b;
		tc = max(dpb, dpa)+c;
		dpa = ta;
		dpb = tb;
		dpc = tc;
	}
	cout << max(max(dpa, dpb), dpc);
	return 0;
}
