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

  //observation : union is still 45 square, how to calc union
  //linear programming expression of ok area
  //d(a, b) = max of abs(x1-x2 + y1-y2) = abs(x1+y1 -(x2+y2))and abs(x1-x2+ y2-y1)
  //=> to <= k
  // abs((x1+-y1) - (x2+-y2)) <= k
  //  -k <= (x1+-y1) - (x2+-y2) <= k
  //  x1+y1+k   >= (x2+-y2) >= x1+y1-k
  int mxpy = -100000000, mxmy = -100000000;
  int Mxpy =  100000000, Mxmy = 100000000;

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
        if(dis[nxt.X][nxt.Y] > x)
        {
          bigs.pb(nxt);
          int x1 = nxt.X, y1 = nxt.Y;
          mxpy = max(mxpy, x1+y1-x);
          Mxpy = min(Mxpy, x1+y1+x);
          mxmy = max(mxmy, x1-y1-x);
          Mxmy = min(Mxmy, x1-y1+x);
        }
      }
    }
  }
  if(bigs.size() == 0) return 1;
  rep(i, 0, n)rep(j, 0, m)
  {
    if(i-j >= mxmy && i-j <= Mxmy && i+j >= mxpy && i+j <=  Mxpy) return 1;  
  }
  return 0;
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

    while(L<R)
    {
      //cout << M << endl;
      M = L+R >> 1;
      if(C(M)) R = M;
      else L = M+1;
    }

    printf("Case #%d: %d\n", tc, L);
  }
	return 0;
}
