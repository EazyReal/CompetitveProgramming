#include <bits/stdc++.h>

using namespace std;
#define ll long long


int T;

signed main()
{
	scanf("%d", &T);
	for(int tc = 1; tc <= T; tc++)
	{
		int n, p;
		scanf("%d%d", &n, &p);
		vector<ll> a(n+1);
		for(int i = 1; i <= n ; i++) scanf("%lld", &a[i]);
		sort(a.begin()+1, a.end());
		//for(int i = 1; i <= n ; i++) printf("%lld", a[i]);
		vector<ll> pre(n+1, 0);
		for(int i = 0; i < n ; i++) pre[i+1] = pre[i] + a[i+1];
		ll best = 1000000000000;
		for(int i = p; i <= n; i++)
		{
			ll cur = a[i]*p - (pre[i]-pre[i-p]);
			//cout << cur << endl;
			best = min(best, cur);
		}
		printf("Case #%d: %lld\n", tc, best);
	}

	return 0;
}
