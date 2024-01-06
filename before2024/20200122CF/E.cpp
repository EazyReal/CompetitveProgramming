//By maxwill, contest: Codeforces Round #615 (Div. 3), problem: (E) Obtain a Permutation, Accepted, #, hack it!
//after contest, debug RE, AC
//69369216	Jan/23/2020 00:58UTC+8	maxwill	E - Obtain a Permutation	GNU C++17	Accepted	78 ms	6400 KB
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

int n, m;
const int maxn = 2*1e5+5;
vector<int> a[maxn];

signed main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    /*
    n = 2 m = 3
    1 2 3 a[0][0] a[]
    4 5 6 a[1][0] a[1][1] a[1][2]
    */
    cin >> n >> m;
    rep(i, 0, n) a[i].resize(m+1); //reverse
    rep(i, 0, n)rep(j, 0, m) cin >> a[i][j];
    int sum = 0;
    rep(j, 0, m)
    {
      vector<int> cnt(n);
      rep(i, 0, n)
      {
        if(a[i][j] > n*m) continue; //will get RE without this judge(id too big)
        if((a[i][j]-(j+1))%m == 0)
        {
          int id = (a[i][j]-(j+1))/m; //bug:j->j+1
          cnt[((i-id)+n)%n]++; //bug:id-i-<id-i
        }
      }
      int minv = n;
      rep(i, 0, n) minv = min(minv, i+(n-cnt[i]));
      sum += minv;
    }
    cout << sum << endl;
    return 0;
}
