#include <bits/stdc++.h>

#define pb push_back
#define X first
#define Y second
#define mkp make_pair

using namespace std;
typedef long long ll;
typedef pair<int, int> pii;
typedef pair<int, ll> pil;

const int maxn = 100+5;
map<string, int> mp;
vector<pil>G[maxn];
int n, m;
int rt;
int d[maxn];
ll e[maxn];
const int maxm = 4505;
//bool v[maxm];

void bfs(int s)
{
  memset(d, -1, sizeof(d));
  memset(e, -1ll, sizeof(e));
  //memset(v, 0, sizeof(v));
  //priority_queue<pii> pq;
  queue<int> q;
  q.push(s);
  d[s] = 0;
  e[s] = 0ll;
  while(!q.empty())
  {
    int u = q.front(); q.pop();
    for(auto v: G[u])
    {
      if(d[v.X] == -1) d[v.X] = d[u]+1, e[v.X] = v.Y, q.push(v.X);
      if(d[u]+1 == d[v.X]) e[v.X] = min(e[v.X], v.Y);
    }
  }
}

int main()
{
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);
  cin >> n >> m;
  string s, s1, s2;
  int a, b;
  ll c;
  mp["English"] = 0;
  for(int i = 1; i <= n; i++)
  {
    cin >> s, mp[s] = i;
  }
  for(int i = 0; i < m; i++)
  {
    cin >> s1 >> s2 >> c;
    a = mp[s1], b = mp[s2];
    G[a].pb(mkp(b,c));
    G[b].pb(mkp(a,c));
  }
  bfs(0);
  //for(int i = 1; i <= n; i++, cout << endl) cout << e[i] << ' ';
  ll ans = 0ll;
  for(int i = 1; i <= n; i++)
  {
    if(d[i] == -1) {cout << "Impossible" << endl; return 0;}
    ans += e[i];
  }
  cout << ans << endl;
	return 0;
}
