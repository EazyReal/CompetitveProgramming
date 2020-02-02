#include <bits/stdc++.h>

using namespace std;

#define X first
#define Y second
#define pb push_back
#define mp make_pair
#define all(a) a.begin(), a.end()
#define rep(i, st, n) for (int i = (st); i < (n); ++i)
#define debug(x) std::cout << #x << ": " << x << endl

typedef long long ll;
typedef unsigned long long ull;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;
typedef long double ld;

int T, n;
int m, k;
const int maxn = 3505;
int a[maxn];



signed main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    //freopen("in", "r", stdin);
    cin >> T;
    while(T--)
    {
      cin >> n >> m >> k;
      rep(i, 0, n) cin >> a[i];

      k = min(k, m-1);
      int x = -1;
      rep(kl, 0, k+1)
      {
        int xk = 1e9+5;
        rep(kpl, 0, (m-1-k)+1) //not controlled
        {
          int l_all = kl+kpl;
          int r_all = m-1-l_all;
          int cur = max(a[l_all], a[n-1-(r_all)]);
          xk = min(xk, cur);
        }
        x = max(x, xk);
      }
      cout << x << endl;
    }
    return 0;
}


/*
aaabce
aaaabceaaabce
6

!?
*/
