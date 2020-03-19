#include <bits/stdc++.h>

using namespace std;

using ll = long long; 
typedef pair<int, int > pii;
#define pb push_back
#define X first
#define Y second
#define mp make_pair

int n, m;

int a[300][300];
int dis[300][300];

pii operator+(pii &a, pii &b)
{
  pii t;
  t.X = a.X+b.X;
  t.Y = a.Y+b.Y;
  return t;
}

pii dd[] = {mp(1,0), mp(0, 1), {-1, 0}, {0, -1}};


#define rep(i, s, t) for(int i = (s), _t = (t); i < _t; ++i)

char tmp[300];

bool C(int x)
{
  queue<pii> q;
  rep(i, 0, n)rep(j, 0, m) dis[i][j] = INT_MAX;
  rep(i, 0, n)rep(j, 0, m) if(a[i][j] != 0)
  {
    q.push({i,j});
    dis[i][j] = 0;
  }

  vector<pii> bigs;
  while(!q.empty())
  {
    pii cur = q.front(); q.pop();
    rep(i, 0, 4)
    {
      pii nxt = cur + dd[i];
      if(dis[nxt.X][nxt.Y] == INT_MAX)
      {
        dis[nxt.X][nxt.Y] = dis[cur.X][cur.Y]+1;
        q.push(nxt);
        if(dis[nxt.X][nxt.Y] > x) bigs.pb(nxt);
      }
    }
  }
  if(bigs.size() == 0) return 1;
  rep(i, 0, n)rep(j, 0, m) cnt[i][j] = 0;
  //snd bfs
  rep(i, 0, n)rep(j, 0, m) if(a[i][j] != 0)
  {
    q.push({i,j});
    dis[i][j] = 0;
  }
  q.push(maxp); dis[maxp.X][maxp.Y] = 0;
  maxv = 0;
  while(!q.empty())
  {
    pii cur = q.front(); q.pop();
    rep(i, 0, 4)
    {
      pii nxt = cur + dd[i];
      if(dis[nxt.X][nxt.Y] == -1)
      {
        dis[nxt.X][nxt.Y] = dis[cur.X][cur.Y]+1;
        q.push(nxt);
        if(dis[nxt.X][nxt.Y] > maxv) maxv = dis[nxt.X][nxt.Y];
      }
    }
  }
}

signed main()
{
  int T;
  scanf("%d", &T);
  rep(tc, 1, T+1)
  {
    scanf("%d%d", &n, &m);
    rep(i, 0, n)
    {
      scanf("%s", tmp);
      rep(j, 0, m) a[i][j] = tmp[j]-'0';
    }

    int L = 0, R = n+m+1, M;

    while(L+1<R)
    {
      M = L+R >> 1;
      if(C(M)) R = M;
      else L = M;
    }

    printf("Case #%d: %d\n", tc, L);
  }
	return 0;
}
