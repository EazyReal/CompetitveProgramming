#include <bits/stdc++.h>

using namespace std;

#define X first
#define Y second
#define pb push_back
#define mp make_pair
#define all(a) a.begin(), a.end()
#define rep(i, st, n) for (ll i = (st); i < (n); ++i)
#define debug(x) std::cout << #x << ": " << x << endl

typedef long long ll;
typedef unsigned long long ull;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;
typedef long double ld;

int T;
ll A, B;

signed main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    cin >> T;
    while(T--)
    {
      cin >> A >> B;
      //construct code
      /*
      rep(i, 1ll, A+1) rep(j, 1ll, B+1)
      {
        if(ll(i*j+i+j) == stoll(to_string(i)+to_string(j)))
        cout << i << ' '<< j << endl;
      }*/
      int cnt = 0;
      rep(i, 1, 11) {/*debug(stoll(string("9",i)));*/ if(stoll(string(i, '9')) <= B) cnt++;}
      //debug(cnt);
      cout << A*cnt << endl;
    }
    return 0;
}
