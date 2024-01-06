//care has first go
//care self loop has
//=> notice    s -----h---> t
//             s -----i---> t

//my solution O(input+n*query)
//standard = variation of floyd-warshall O(input+n^3+1*query)
//author = yt lin, 0712238@NCTU
//time = 2019.12.11 23:35
//codeforces verdict:
//66642982	04:00:15	NCTU_Oimo: baili0411, supremeyu, maxwill04:00	E - Is-A? Has-A? Who Knowz-A?
//GNU C++17	Accepted	62 ms	300 KB
#include <bits/stdc++.h>

using namespace std;
#define pb push_back

typedef long long ll;

int n, m, q;
const int maxn = 500+5;
vector<int> G[maxn];
vector<int> Ginv[maxn];
vector<int> Gh[maxn];

bool vis[maxn];
bool vish[maxn];

map<string, int> dict;


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

bool has_a(int u, int item, bool hadhas)
{
  if(u == item && hadhas) return true;
  for(auto v:Gh[u])if(!vish[v]) //has may have loop
  {
    vish[v] = 1;
    if(has_a(v, item, true)) return true;
  }
  for(auto v:Ginv[u])if(!vis[v] || (hadhas&&!vish[v]))
  {
    vis[v] = 1;
    if(hadhas) vish[v] = 1;
    if(has_a(v, item, hadhas)) return true;
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
    }else{
      Gh[u].pb(v);
    }
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
      memset(vish, 0, sizeof(vish));
      cout << "Query " << i+1 << ": " << (has_a(dict[s1], dict[s2], false)?"true\n":"false\n");
    }
  }

  return 0;
}
