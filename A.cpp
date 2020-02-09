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
    //freopen("in", "r", stdin);
    cin >> T;
    while(T--)
    {
      cin >> n;
      int ai;
      int sum = 0;
      int cnt0 = 0;
      bool allm1 = 1;
      rep(i, 0, n)
      {
        cin >> ai;
        sum += ai;
        if(ai == 0) cnt0++;
        allm1 |= (ai == -1);
      }
      if(cnt0 + sum == 0)
      {
        cout << cnt0 + 1 << endl;
      }else{
        cout << cnt0 << endl;
      }
    }
    return 0;
}
