//69317950	Jan/22/2020 22:53UTC+8	maxwill	B - Collecting Packages	GNU C++17	Accepted	15 ms	8 KB
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

signed main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);

    cin >> T;
    while(T--)
    {
      cin >> n;
      vector<pii> a(n+1);
      rep(i, 1, n+1) cin >> a[i].X >> a[i].Y;
      sort(all(a));
      bool flag = false;
      rep(i, 0, n+1) rep(j, 0, n+1)
      {
        if(i == j) continue;
        if(a[i].X+a[i].Y <= a[j].X+a[j].Y && (a[i].X > a[j].X || a[i].Y > a[j].Y)) flag = true;
      }
      if(flag) cout << "NO\n";
      else{
        cout << "YES\n";
        rep(i, 1, n+1)
        {
          rep(k, 0, a[i].X-a[i-1].X) cout << "R";
          rep(k, 0, a[i].Y-a[i-1].Y) cout << "U";
        }
        cout << endl;
      }
    }

    return 0;
}
