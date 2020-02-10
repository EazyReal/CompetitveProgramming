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
int top;
double val[maxn];
pii stk[maxn];

//lemma: disjoint segments
//from head to tall git min
//how to do this fast for 1e6 n

//solved after contest
//not official optimization with convex property, should learn it

signed main()
{
    fastIO();
    cin >> n;
    rep(i, 1, n+1) cin >> a[i];
    pre[0] = 0.0;
    rep(i, 1, n+1) pre[i] = pre[i-1] + a[i];
    //note that this stack is 1-indexed;
    top = 0;
    rep(i, 1, n+1)
    {
      //compare cur segment with past segments
      double cur = a[i];
      pii seg = mp(i, i);
      while(top && cur < val[top]) //care eps?
      {
        cur = (pre[i]-pre[stk[top].X-1])/(i-stk[top].X+1); //merge now with past segment
        --top;
      }
      ++top;
      val[top] = cur;
      stk[top] = mp((top == 1 ? 1 : stk[top-1].Y+1), i);
    }
    rep(i, 1, top+1)
    {
      //debug(stk[i].Y);
      rep(j, stk[i].X, stk[i].Y+1) cout << std::setprecision(10) << val[i] << " \n"[j==n];
    }

    return 0;
}
