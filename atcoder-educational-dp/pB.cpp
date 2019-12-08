#include <bits/stdc++.h>
#define pb push_back
#define ll long long
using namespace std;

//can use O(K) memory actually

int T, n, k;
const int maxn = 100000+5;
const ll INF = 1000000000+5;
ll h[maxn];
ll dp[maxn];

int main(){
	ios::sync_with_stdio(false);
	cin.tie(0); cout.tie(0);
	cin >> n >> k;
	for(int i = 1; i <= n ; i++) {cin >> h[i]; dp[i] = INF;}
	dp[1] = 0LL;
	for(int i = 2; i <= n ; i++)for(int j = max(1, i-k); j < i; j++)
		dp[i]=min(dp[i], dp[j]+abs(h[i]-h[j]));
	cout << dp[n];
	return 0;
}
