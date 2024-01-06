#include <bits/stdc++.h>

using namespace std;
typedef long long ll;
typedef pair<int, int> pii;


int T;
int n, m;
const int maxn = 100000+5;
const int maxm = 100000+5;
ll a[maxn];
ll d[maxn];
ll b[maxn];

int main()
{
  cin >> T;
  while(T--)
  {
    cin >> n >> m;
    for(int i = 1; i <= n; i++) cin >> a[i], d[a[i]]=i;
    for(int i = 1; i <= m; i++) cin >> b[i];
    int maxd = 0;
    ll ans = 0; //why this WA 3, didnt this of worst case?
    for(int i = 1; i <= m; i++)
    {
      if(d[b[i]]>maxd)
      {
        maxd=d[b[i]];
        ans += 2*((d[b[i]]-1)-(i-1))+1;
        //if(i != m) ans += 2*((maxd-1)-(i-1))+1;
        //else ans += (maxd-1)-(i-1)+1;
      }
      else ans += 1;
    }
    cout << ans << endl;
  }
  return 0;
}
