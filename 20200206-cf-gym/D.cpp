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
const int maxn = 200+5;
int a[maxn][maxn];
int p[maxn];
int pos[maxn];
int simu[maxn];

signed main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    freopen("bubble.in", "r", stdin);
    freopen("bubble.out", "w", stdout);

    cin >> n;
    rep(i, 0, n-1)rep(j, 0, i+1) cin >> a[i][j];
    rep(i, 0, n) p[i] = i;
    rep(j, 0, n-1)
    {
      for(int i = n-2; i >= 0; i--)
      {
        if(j>i) continue;
        if(a[i][j] == 1) swap(p[i], p[i+1]);
      }
    }
    rep(i, 0, n) pos[p[i]] = i, simu[p[i]] = i;

    bool flag = true;
    rep(j, 0, n-1)
    {
      for(int i = n-2; i >= 0; i--)
      {
        if(j>i) continue;
        if(a[i][j] != simu[i] > simu[i+1]) flag = false;
        if(simu[i] > simu[i+1]) swap(simu[i], simu[i+1]);
      }
    }

    if(flag)
    {
      cout << "YES\n";
      rep(i, 0, n) cout << pos[i]+1 << " \n"[i==n-1];
    }else{
      cout << "NO\n";
    }


    return 0;
}
