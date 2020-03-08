#include <bits/stdc++.h>

using namespace std;

#define X first
#define Y second
#define pb push_back
#define all(a) a.begin(), a.end()
#define rep(i, st, n) for (int i = (st); i < (n); ++i)
#define repinv(i, st, n) for (int i = ((n)-1); i >= (st); --i)
#define fastIO() ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0)

typedef long long ll;
typedef unsigned long long ull;

int T;
const int maxn = 5e5+7;
int n, m;

ll a[maxn];
ull r[maxn];
map<ull, ll> lsum;
vector<int> G[maxn];

mt19937_64 rng(chrono::steady_clock::now().time_since_epoch().count());

//fastIO still a lot slower then scanf IO

void solve()
{
	scanf("%d%d", &n, &m);
  lsum.clear();
	rep(i, 0, n) scanf("%lld", a+i), G[i].clear(), r[i]=rng();
	int u, v;
	rep(i, 0, m)
	{
		scanf("%d%d", &u, &v);
		G[v-1].pb(u-1);
	}
	rep(i, 0, n)
  {
    if(G[i].size() == 0) continue;
    ull lset = 0;
    for(int &x : G[i]) lset ^= r[x];
    lsum[lset] += a[i];
  }
	//ll ans = lsum.begin()->Y; //m>=1
	ll ans = 0;
	for(auto &s : lsum) ans = __gcd(ans , s.Y);
	printf("%lld\n", ans);

  return;
}


signed main()
{
  scanf("%d", &T);
  while(T--) solve();
  return 0;
}
