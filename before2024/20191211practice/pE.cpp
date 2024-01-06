#include <bits/stdc++.h>

//21:14-21:17
//21:17-19
//21:28-

using namespace std;
#define pb push_back

typedef long long ll;

int n, m, q;
const int maxn = 500+5;
vector<int> G[maxn];
vector<int> Ginv[maxn];
bitset<maxn> H[maxn];
bool vis[maxn];

map<string, int> dict;

void dfs(int u, bitset<maxn> vars) //DAG no need to check
{
  H[u] |= vars;
  for(auto v:G[u])if(!vis[v])
  {
    vis[v] = 1;
    dfs(v, vars);
  }
}
void dfs2(int u, bitset<maxn> vars) //DAG no need to check
{
  H[u] |= vars;
  for(auto v:Ginv[u])if(!vis[v])
  {
    vis[v] = 1;
    dfs(v, vars);
  }
}

bool is_a(int u, int target)
{
  if(u == target) return true;
  for(auto v:Ginv[u])if(!vis[v])
  {
    vis[v] = 1;
    if(is_a(v, target)) return true;
  }
  return false;
}

bool has_a(int u, int item)
{
  if(H[u].test(item)) return true;
  for(auto v:G[item])if(!vis[v])
  {
    vis[v] = 1;
    if(has_a(u, v)) return true;
  }
  return false;
}

int main()
{
  ios::sync_with_stdio(false);
  cin.tie(0); cout.tie(0);
  cin >> m >> q;
  string s1, s2, cp;
  int u, v;
  n = 0;
  for(int i = 0; i < m; i++)
  {
    cin >> s1 >> cp >> s2;
    if(dict.find(s1)==dict.end())  dict[s1] = n++;
    if(dict.find(s2)==dict.end())  dict[s2] = n++;
    u = dict[s1], v = dict[s2];
    if(cp == "is-a")
    {
      if(u == v) continue; // X is-a X
      G[v].pb(u), Ginv[u].pb(v); //means u is-a v => v is a father of u
    }
    else H[u].set(v); //means u has a v;
  }
  int cur;
  for(int i = 0; i < n; i++)
  {
    memset(vis, 0, sizeof(vis));
    dfs(i, H[i]); //mark
    memset(vis, 0, sizeof(vis));
    dfs2(i, H[i]);
  }
  for(int i = 0; i < q; i++)
  {
    cin >> s1 >> cp >> s2;
    if(cp == "is-a")
    {
      memset(vis, 0, sizeof(vis));
      cout << "Query " << i+1 << ": " << (is_a(dict[s1], dict[s2])?"true\n":"false\n");
    }else{
      memset(vis, 0, sizeof(vis));
      cout << "Query " << i+1 << ": " << (has_a(dict[s1], dict[s2])?"true\n":"false\n");
    }
  }

  return 0;
}
