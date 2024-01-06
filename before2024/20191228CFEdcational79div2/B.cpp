#include <bits/stdc++.h>

using namespace std;
typedef long long ll;

int T;
int n, t;
const int maxn = 100000+5;
ll a;

int main()
{
  cin >> T;
  while(T--)
  {
    cin >> n >> t;
    ll maxv = 0ll;
    ll s = 0ll;
    int idx = 0;
    bool flag = 0;
    for(int i = 1; i <= n; i++)
    {
      cin >> a;
      s += a;
      if(!flag){if(a > maxv && s-a<=t) maxv = a, idx = i;}
      if(s-maxv > t) {flag = 1; continue;}//can update or not
    }
    if(s>t) flag = 1;//use or not
    if(!flag) cout << 0 << endl;
    else cout << idx << endl;
  }
  return 0;
}
