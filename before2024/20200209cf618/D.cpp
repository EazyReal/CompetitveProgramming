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

pii add(pii a, pii b)
{
  return mp(a.X+b.X, a.Y+b.Y);
}

signed main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    //freopen("in", "r", stdin);
    cin >> n;
    vector<pii> a(n);
    for(auto &ai : a) cin >> ai.X >> ai.Y;
    if(n%2 == 1) cout << "NO" << endl;
    else //even n and point-symmetric => YES, else => NO
    {
      pii axis;
      axis = add(a[0], a[n/2]); //ignore/2
      bool flag = 1;
      rep(i, 1, n/2) flag &= (add(a[i], a[i+n/2]) == axis);
      if(flag) cout << "YES" << endl;
      else cout << "NO" << endl;
    }
    return 0;
}
