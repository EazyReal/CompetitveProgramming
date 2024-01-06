//69519549	Jan/25/2020 21:02UTC+8	NCTU_Oimo: baili0411, maxwill#	F - Fractions	GNU C++17	Accepted	46 ms	0 KB
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

ll n;

//ax+by=n-1

//a > b
ll extgcd(ll a, ll b, ll &x, ll &y){
    if(b == 0ll) { x = 1ll; y = 0ll; return a;}
    ll ret = extgcd(b, a % b, y, x);
    y -= (a / b) * x;
    return ret;
}

signed main()
{
    ios::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);

    cin >> n;
    ll a, b, x, y;
    ll t1, t2;
    for(ll i = 2ll; i*i <= n; ++i)if(n%i == 0)
    {
      a = i, b = n/i; //a<b
      ll d = extgcd(a, b, x, y);
      if((n-1)%d != 0) continue;
      x = (x+b/d)*((n-1)/d);
      x = (x%(b/d)+b/d)%b/d; //limit to 0-b/d;
      y = (n-1-a*x)/b;
      cout << "YES" << endl << 2 << endl;
      ll dxb = extgcd(x, b, t1, t2);
      ll dya = extgcd(y, a, t1, t2);
      cout << x/dxb << ' ' << b/dxb << endl;
      cout << y/dya << ' ' << a/dya << endl;
      return 0;
    }
    cout << "NO" << endl;

    return 0;
}
