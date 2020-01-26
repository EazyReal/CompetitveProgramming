//69516549	Jan/25/2020 20:10UTC+8	NCTU_Oimo: baili0411, maxwill#	L - Lazyland	GNU C++17	Accepted	78 ms	2000 KB
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

int T, n, k;
const int maxn = 1e5+5;
//job 1-indexed
pll a[maxn];
int cnt[maxn];

signed main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);

    cin >> n >> k;
    memset(cnt, 0, sizeof(cnt));
    ll done = 0ll;
    rep(i, 0, n)
    {
      cin >> a[i].Y;
      ++cnt[a[i].Y];
      if(cnt[a[i].Y] == 1) ++done;
    }
    rep(i, 0, n) cin >> a[i].X;
    sort(a, a+n);
    ll sum = 0ll;
    for(int i = 0; i < n && done != k; ++i)
    {
      if(cnt[a[i].Y] > 1) --cnt[a[i].Y], ++done, sum+=a[i].X;
    }
    cout << sum << endl;

    return 0;
}
