#include <bits/stdc++.h>

#define rep(i,s,t) for(int i = s; i < t; ++i)
#define ll long long
#define X first 
#define Y second
#define pb push_back

using namespace std;

using pii = pair<int,int>;

const int maxn = 5e3+5;
int A, B;
int n, m;
vector<int> G[maxn];
vector<int> Ginv[maxn];
int mask[maxn];
//bool vis[maxn];
//int dp[maxn];

int acc(int u)
{
  int ret = 1;
  for(int v: G[u])
  {
    if(mask[v] == 0) {mask[v] = 1; ret += acc(v);}
  }
  return ret;
}

void mark(int u)
{
  for(int v: G[u])
  {
    if(mask[v] == 0) {mask[v] = 1; mark(v);}
  }
  return;
}


int solve(int A)
{
  int cnt = 0;
  rep(s, 0, n) //source
  {
    memset(mask, 0, sizeof(mask));
    mask[s] = 1;
    mark(s);
    int cango = 0;
    rep(i, 0, n)if(!mask[i])
    {
      mask[i] = 1;
      cango += acc(i);
    }
    if(cango < A) cnt++;
  }
  return cnt;
}


int dfs(int u)
{
  int ret = 1;
  for(int v: Ginv[u])
  {
    if(mask[v] == 0) {mask[v] = 1; ret += dfs(v);}
  }
  return ret;
}



signed main()
{
  ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
  cin >> A >> B >> n >> m;
  int u, v;
  rep(i, 0, m)
  {
    cin >> u >> v;
    G[u].pb(v);
    Ginv[v].pb(u);
  }
  int aa = solve(A);
  int bb = solve(B);

  int cnt = 0;
  rep(i, 0, n)
  {
    memset(mask, 0, sizeof(mask));
    mask[i] = 1;
    if(dfs(i) > B) cnt++;
  }

  //cnt
  cout << aa << endl;
  cout << bb << endl;
  cout << cnt << endl;

  return 0;
}
