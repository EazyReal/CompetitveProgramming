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
#define fileIO(in, out) freopen(in, "r", stdin); freopen(out, "w", stdout)

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
    cin >> n;
    rep(i, 1, n+1) cin >> a[i];
    pre[0] = 0.0;
    rep(i, 1, n+1) pre[i] = pre[i-1] + a[i];
    int stk[maxn], top = 0;
    rep(i, 1, n+1)
    {
      while(top && (pre[i]-pre[stk[top-1]])/(i-stk[top-1]) ) top--;
      stk[top++] = i;
    }
    rep(i, 0, top)
    {
      
    }

    rep(i, 1, n+1) cout << std::setprecision(10) << ans[i] << " \n"[i==n];
    return 0;
}
