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

ll X0, X, a, b;
map<ll, ll> pX;
bool is_p;
//ll is_p[1000000+5];

signed main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    cin >> X0;
    X = X0;
    pX.clear();
    for(ll i = 2; i*i <= X; ++i)
    {
      while(X%i == 0)
      {
        X /= i;
        pX[i]++;
      }
    }
    if(X > 1) pX[X]++;
    vector<ll> choices;
    for(auto it = pX.begin(); it != pX.end(); it++)
    {
      //cout << it->X << ' ' << it->Y << endl;
      choices.pb(pow(it->X, it->Y));
    }
    sort(all(choices));
    /*
    rep(i, 0, choices.size()) cout << choices[i] << ' ';
    cout << endl;
    for(int i = choices.size()-1; i >= 0; i--)
    {
      if(a>b) b*= choices[i];
      else a*= choices[i];
    }
    */
    a = 1ll; b = X0;
    ll n = choices.size();
    ll U = (1ll<<n)-1ll;
    for(ll S = 0ll; S <= U; S++)
    {
      ll tmp = 1ll;
      for(ll i = 0ll; i < n; i++)if(S&(1ll<<i)) tmp *= choices[i];
      //cout << tmp <<  ' ' << X0/tmp << endl;
      if(max(tmp, X0/tmp) < max(a, b)) {a = tmp, b = X0/tmp;}
    }

    cout << a << ' ' <<  b << endl;
    return 0;
}
