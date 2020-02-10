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
const int maxn = 1e5+5;
const int maxbit = 35; //1e9
int a[maxn];
pii b[maxn];
int cnt[maxbit];


//observation any same => 0


signed main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    //freopen("in", "r", stdin);
    cin >> n;
    rep(i, 0, n) cin >> a[i];
    rep(bi, 0, maxbit) cnt[bi] = 0;
    //sorted by most significant bit
    //sort(a, a+n, greater<int>());
    rep(i, 0, n)
      rep(bi, 0, maxbit)
        if(a[i]&(1<<bi)) ++cnt[bi];
    rep(i, 0, n)
    {
      int uniq = 0;
      rep(bi, 0, maxbit)
      {
        if(a[i]&(1<<bi) && cnt[bi] == 1) uniq |= 1<<bi;
      }
      b[i] = mp(uniq, i);
    }
    sort(b, b+n, greater<pii>());
    rep(i, 0, n) cout << a[b[i].Y] << " \n"[i==n-1];
    /*
    int i = 0;
    while(i < n-1 && a[i] == a[i+1])
    {
      i++;
      if(i < n-1 && a[i] != a[i+1]) i++;
    }
    cout << a[i] << " \n"[i==n-1];
    rep(j, 0, n)if(j != i) cout << a[j] << " \n"[j==n-1 || (i==n-1&&j==n-2)];
    */
    //int res = a[0];
    //rep(i, 1, n) res = (res|a[i])-a[i];
    //cout << res << endl;
    return 0;
}
