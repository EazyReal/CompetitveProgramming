#include <bits/stdc++.h>

using namespace std;

#define X first
#define Y second
#define pb push_back
#define mp make_pair
#define all(a) a.begin(), a.end()
#define rep(i, st, n) for (int i = (st); i < (n); ++i)
#define debug(x) std::cout << #x << ": " << x << endl
#define fastIO() ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0)

typedef long long ll;
typedef unsigned long long ull;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;
typedef long double ld;

int T, n;
const int maxn = 1e6+5;
int a[maxn];
//double ad[maxn];
double pre[maxn];
double ans[maxn];


//lemma: disjoint segments
//from head to tall git min
//how to do this fast for 1e6 n

signed main()
{
    fastIO();
    //freopen("in", "r", stdin);
    cin >> n;
    rep(i, 1, n+1) cin >> a[i];
    pre[0] = 0.0;
    rep(i, 1, n+1) pre[i] = pre[i-1] + a[i];
    int s = 1;
    while(s <= n)
    {
      double mm = 1e7;
      int mi = s;
      rep(t, s, n+1)
      {
        double now = (pre[t]-pre[s-1])/(t-s+1);
        mm = min(mm, now);
        if(now == mm) mi = t;
      }
      rep(si, s, mi+1) ans[si] = mm;
      s = mi+1;
    }
    rep(i, 1, n+1) cout << std::setprecision(10) << ans[i] << " \n"[i==n];
    return 0;
}
