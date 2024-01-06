using namespace std;
#include <bits/stdc++.h>

typedef long long ll;

using namespace std;

int T;
int n;
const int maxn = 50+2; //maxm = maxn
int m[maxn];
ll rowr[maxn];
ll a[maxn][maxn];
ll ans;

bool test(ll d)
{
  for(int i = 0; i < n; i++)
  {
    rowr[i] = a[i][0]%d;
    for(int j = 1; j < m[i]; j++) if(a[i][j]%d != rowr[i]) return false;
  }
  ll sum = 0ll;
  for(int i = 0; i < n; i++) sum += rowr[i];
  return sum%d == 0;
}

int main()
{
  ios::sync_with_stdio(0);
  cin.tie(0); cout.tie(0);
  cin >> T;
  for(int t = 1; t <= T; t++)
  {
    cin >> n;
    for(int i = 0; i < n; i++)
    {
      cin >> m[i];
      for(int j = 0; j < m[i]; j++) cin >> a[i][j];
    }
    ll sum = 0ll;
    for(int i = 0; i < n; i++) sum += a[i][0];
    ans = 1ll;
    for(ll d = 1ll; d*d <= sum; d++)if(sum%d == 0ll)
    {
      if(test(sum/d)) { ans=sum/d; break;}
      if(test(d)){ans = d;} //no need max
    }
    cout << "Case #" << t <<  ": " << ans << endl;
  }
  return 0;
}
