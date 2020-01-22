//69346699	Jan/22/2020 23:45UTC+8	maxwill	D - MEX maximizing	GNU C++17	Accepted	1591 ms	15876 KB
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
ll q, x;
const ll maxq = 4*1e5+5;
const ll maxx = 4*1e5+5;
ll cnt[maxx];


signed main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);

    cin >> q >> x;
    //cout << "JII";
    ll yi;
    set<ll> s;
    ll iter = 0ll;
    ll mexv = 0ll;
    memset(cnt, 0ll, sizeof(cnt));
    rep(i, 1, q+1)
    {
      //cout << "JII";
      cin >> yi;
      yi = yi%x;
      cnt[yi]++;
      s.insert(yi);
      if(yi == mexv)
      {
        int it = yi;
        while(cnt[it]) it++;
        mexv = it;
      }
      if(s.size() == x)
      {
        iter++;
        mexv = maxx;
        rep(k, 0, x)
        {
          if(cnt[k] == 1) s.erase(k);
          cnt[k]--;
          if(!cnt[k]) mexv = min(mexv, ll(k));
        }
      }
      cout << min(ll(i), iter*x+mexv) << endl;
    }

    return 0;
}
