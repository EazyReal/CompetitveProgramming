#include <bits/stdc++.h>

using namespace std;

#define X first
#define Y second
#define pb push_back
#define mp make_pair
#define all(a) a.begin(), a.end()
#define rep(i, st, n) for (int i = (st); i < (n); ++i)
#define debug(x) std::cout << #x << ": " << x << endl

typedef long long ll;
typedef unsigned long long ull;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;
typedef long double ld;

int n, m;
vector<vector<pair<ll, pll>>> G;
vector<pll> pos;
vector<bool> vis;
const ll M = 1e9;
const ll mM = -1e9;

signed main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    cin >> n >> m;
    pos.resize(n);
    G.resize(n);
    vis.resize(n);
    ll ai, bi, dx, dy;
    rep(i, 0, m)
    {
      cin >> ai >> bi >> dx >> dy;
      G[--ai].pb(mp(--bi, mp(dx,dy)));
      G[bi].pb(mp(ai, mp(-dx,-dy)));
    }
    pos[0].X = 0ll; pos[0].Y = 0ll;
    ll minxcor = std::numeric_limits<ll>::max();
    ll maxxcor = std::numeric_limits<ll>::min();
    ll minycor = std::numeric_limits<ll>::max();
    ll maxycor =  std::numeric_limits<ll>::min();
    rep(i, 1, n) vis[i] = 0;
    queue<ll> q;
    q.push(0);
    vis[0] = true;
    while(!q.empty())
    {
      ll cur = q.front(); q.pop();
      for(auto item:G[cur])
      {
        ll nxt = item.X;
        if(vis[nxt]) continue;
        vis[nxt] = 1;
        q.push(nxt);
        pos[nxt].X = pos[cur].X + item.Y.X;
        pos[nxt].Y = pos[cur].Y + item.Y.Y;
        minxcor = min(minxcor, pos[nxt].X);
        maxxcor = max(maxxcor, pos[nxt].X);
        minycor = min(minycor, pos[nxt].Y);
        maxycor = max(maxycor, pos[nxt].Y);
      }
    }
    ll adjx, adjx2, adjy, adjy2;
    adjx = max(0ll, mM - minxcor);
    adjx2 = max(0ll, maxxcor - M);
    adjy = max(0ll, mM - minycor);
    adjy2 = max(0ll, maxycor - M);
    rep(i, 0, n)
    {
      if(adjx > 0) pos[i].X += adjx;
      if(adjx2 > 0) pos[i].X -= adjx2;
      if(adjy > 0) pos[i].Y += adjy;
      if(adjy2 > 0) pos[i].Y -= adjy2;
      cout << pos[i].X  << ' ' << pos[i].Y << endl;
    }
    return 0;
}
