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

//#define delta[i-1] 0

int T;
int n, x;
int N = 1e5;

signed main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    //freopen("in", "r", stdin);
    cin >> T;
    while(T--)
    {
      cin >> n >> x;
      string s;
      cin >> s;
      vector<int> a(n);
      vector<int> delta(n);
      int cnt[2];
      cnt[0] = 0; cnt[1] = 0;
      bool has_sol = 0;
      rep(i, 0, n)
      {
         a[i] = s[i]-'0';
         ++cnt[a[i]];
         delta[i] = cnt[0] - cnt[1];
         if(delta[i] == x) has_sol = 1;
      }
      //all eq => inf
      if(cnt[0] == cnt[1]) {cout << (has_sol ? -1 : 0) << endl; continue;}
      int dall = cnt[0] - cnt[1];
      int ans = 0;
      //end with ith
      rep(i, 0, n)
      {
        int wanted = x-delta[i]; //wanted more(+)/less(-) 0 than 1 with full seq *n
        if(wanted%dall == 0 && ll(wanted)*ll(dall) >= 0ll) ans++;
      }
      if(x == 0) ans++;
      cout << ans << endl;

    }
    return 0;
}

/*
00111 0
(0011 001110 00111001)
00000111111 0
(more than 2 l, atmost n^2/2)
(a0(a+1)1)

-=> end with ith each O(1) ok

care empty string
*/
