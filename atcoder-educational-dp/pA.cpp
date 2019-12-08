#include <bits/stdc++.h>
#define pb push_back
#define ll long long
using namespace std;

//can use O(1) memory actually

int T, n;
const int maxn = 200000+5;
ll h[maxn];
ll dp[maxn];

int main(){
	ios::sync_with_stdio(false);
	cin.tie(0); cout.tie(0);
	cin >> n;
	for(int i = 1; i <= n ; i++) cin >> h[i];
	dp[1] = 0LL;
	dp[2] = abs(h[2]-h[1]);

	for(int i = 3; i <= n ; i++)
	{
		dp[i] = min(dp[i-1]+abs(h[i]-h[i-1]), dp[i-2]+abs(h[i]-h[i-2]));
	}
	cout << dp[n];
	return 0;
}
