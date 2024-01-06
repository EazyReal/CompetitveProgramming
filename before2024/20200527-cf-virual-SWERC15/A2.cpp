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
int dep[maxn][maxn];

void solve()
{
    vector<int> deg(n);
    //vector<set<int>> dep(n);

    queue<int> q;
    rep(i, 0, n)
    {
        deg[i] = Ginv[i].size();
        if(deg[i] == 0) q.push(i);
        dep[i][i] = 1;
    }
    while(!q.empty())
    {
        int u = q.front(); q.pop();
        for(int v: G[u])
        {
            /*for(int ele : dep[u])
            {
                //dep[v].insert(ele);
            }*/
            rep(i, 0, n) if(dep[u][i]) dep[v][i] = 1;
            deg[v]--;
            if(deg[v] == 0) q.push(v);
        }
    }
    int aa = 0, bb = 0, cc = 0;
    rep(s, 0, n)
    {
        int cango = 0;
        int relate = 0;
        rep(i, 0, n)
        {
            if(dep[i][s] == 0) cango++; // i require s
            if(dep[s][i] == 1) relate++; 
        }       
        if(cango < A) aa++;
        if(cango < B) bb++;
        if(relate > B) cc++; 
    }
    cout << aa << endl << bb << endl << cc << endl;

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

  solve();

  return 0;
}
