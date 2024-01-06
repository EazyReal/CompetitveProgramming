using namespace std;
#include <bits/stdc++.h>

typedef long long ll;

using namespace std;

int main()
{
  ll N = 2500000000000ll;
  ll maxv = 0ll;
  for(ll n = N; n <= N; n++)
  {
    ll cnt = 1ll;
    for(ll i = 1; i*i<=n;i++)
    {
      if (n%i == 0ll) cnt++;
    }
    maxv = max(maxv, cnt);
  }
  cout << maxv;
  return 0;
}
