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
string s;
const int maxn = 3000+5;
int a[maxn];

signed main()
{
    ios::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    //freopen("in", "r", stdin);
    cin >> T;
    while(T--)
    {
      cin >> n;
      cin >> s;
      int sum = 0;
      rep(i, 0, n)
      {
        a[i] = s[i]-'0', sum += a[i];
      }
      if(sum %2 != 0)
      {
        rep(i, 0, n)
        {
          if(a[i]%2 == 1) {a[i] = -1; break;}
        }
      }
      for(int i = n-1; i >= 0; i--)
      {
        if(a[i] == -1) continue;
        if(a[i]%2==0) {a[i]=-1;}
      }
      bool flag = 0;
      rep(i, 0, n) flag |= (a[i]!=-1);
      if(flag){
         rep(i, 0, n) if(a[i]!=-1) cout << a[i];
         cout << endl;
      }else
      {
        cout << -1 << endl;
      }
    }
    return 0;
}
