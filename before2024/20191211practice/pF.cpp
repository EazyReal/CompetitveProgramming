#include <bits/stdc++.h>

using namespace std;
#define pb push_back

typedef long long ll;

int n;
const int maxn = 10000+5;
vector<int> G[maxn];
ll sz[maxn];
vector<ll> SZ[maxn];

ll dfs(int u, int p)
{
  sz[u] = 1ll;
  for(auto v : G[u]) if(v!=p)
  {
    ll tmp = dfs(v, u);
    SZ[u].pb(tmp);
    sz[u] += tmp;
  }
  return sz[u];
}

ll calc(int u)
{
  ll s = 0ll;
  ll s2 = 0ll;
  for(auto x: SZ[u])
  {
    s += x;
    s2 += x*x;
  }
  if(u!=0) s2+= (n-sz[u])*(n-sz[u]);
  return ((n-1)*(n-1)-s2)/2;
}

int main()
{
  ios::sync_with_stdio(false);
  cin.tie(0); cout.tie(0);
  cin >> n;
  n = n+1;

  int u, v;
  for(int i = 0; i < n-1; i++)
  {
    cin >> u >> v;
    G[u].pb(v);
    G[v].pb(u);
  }
  dfs(0, -1);
  ll maxv = 0;
  int maxnode = -1;
  for(int i = 0; i < n; i++)
  {
    ll val = calc(i);
    //cout <<  i << " = " << val << endl;
    if(val > maxv) maxv = val, maxnode = i;
  }
  cout << maxv << endl;
  if(maxnode != 0) SZ[maxnode].pb(n-sz[maxnode]);
  sort(SZ[maxnode].begin(), SZ[maxnode].end(), greater<ll>());
  cout << (maxv-SZ[maxnode][0]*SZ[maxnode][1]) << endl;

  return 0;
}
