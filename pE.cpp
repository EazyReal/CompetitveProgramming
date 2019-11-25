#include <bits/stdc++.h>

using namespace std;

#define pb push_back
//typedef pair<int, int> pii;
#define X first
#define Y second

int T, n, m;
const int maxn = 1000000+5;
const int maxm = 1000000+5;
char *a[maxn];
int *vis[maxn];
int *d[maxn];

struct pii
{
  int X,Y;
  pii(){};
  pii(int x, int y): X(x), Y(y){}
  bool valid()
  {
    return X>0 && Y>0 && X<=n && Y<=m;
  }
};

const int dx[8]={0,0,1,1,1,-1,-1,-1};
const int dy[8]={1,-1,-1,0,1,-1,0,1};

void BFS1()
{
  queue<pii> q;
  for(int i = 1; i <= n; i++)for(int j = 1; j <= m; j++) vis[i][j] = -1;
  for(int i = 0; i < n+2; i++)for(int j = 0; j < m+2; j++)if(a[i][j] == '.')
    q.push(pii(i,j)), d[i][j] = 0, vis[i][j] = 0;

  pii u; int x,y;
  while(!q.empty())
  {
    //cout << 'j';
    u = q.front(); q.pop();
    for(int i = 0; i < 8 ; i++)
    {
      x = u.X+dx[i];
      y = u.Y+dy[i];
      pii v(x, y);
      if(v.valid() && !~vis[x][y])
      {
        d[x][y] = d[u.X][u.Y]+1;
        vis[x][y] = 0;
        q.push(v);
      }
    }
  }
  //for(int i = 0; i < n+2; i++, cout << endl)for(int j = 0; j < m+2; j++) cout << d[i][j] << ' ';
}

bool C(int val)
{
  queue<pii> q;
  for(int i = 1; i <= n; i++)for(int j = 1; j <= m; j++) vis[i][j] = -1;
  for(int i = 1; i <= n; i++)for(int j = 1; j <= m; j++)if(d[i][j] > val)
    q.push(pii(i,j)), vis[i][j] = 0;
  //for(int i = 0; i < n+2; i++, cout << endl)for(int j = 0; j < m+2; j++) cout << vis[i][j] << ' ';
  while(!q.empty())
  {
    pii u = q.front(); q.pop();
    //cout << u.X << ' ' << u.Y << endl;
    if(vis[u.X][u.Y] == val) continue;
    for(int i = 0; i < 8 ; i++)
    {
      int x = u.X+dx[i];
      int y = u.Y+dy[i];
      pii v(x,y);
      if(!v.valid()) return false;
      if(v.valid() && !~vis[x][y]) //debug
      {
        if(a[x][y] == '.') return false;
        vis[x][y] = vis[u.X][u.Y]+1;
        q.push(v);
      }
    }
  }
  //for(int i = 0; i < n+2; i++, cout << endl)for(int j = 0; j < m+2; j++) cout << vis[i][j] << ' ';

  for(int i = 1; i <= n; i++)for(int j = 1; j <= m; j++)
    if(a[i][j] == 'X' && !~vis[i][j]) return false;
  return true;
}

int main()
{
  ios::sync_with_stdio(false);
  cin.tie(0); cout.tie(0);
  cin >> n >> m;
  for(int i = 0; i < n+2; i++)
  {
    a[i] = new char[m+2];
    vis[i] = new int[m+2];
    d[i] = new int[m+2];
  }
  for(int i = 1; i <= n; i++)for(int j = 1; j <= m; j++) cin >> a[i][j];
  for(int i = 0; i < n+2; i++) a[i][0] = a[i][m+1] = '.';
  for(int i = 0; i < m+2; i++) a[0][i] = a[n+1][i] = '.';
  //for(int i = 0; i < n+2; i++, cout << endl)for(int j = 0; j < m+2; j++) cout << a[i][j] << ' ';


  if(n >= 500001 || m >= 500001)
  {
    cout << 0 << endl;
    for(int i = 1; i <= n; i++){for(int j = 1; j <= m; j++)cout << a[i][j]; cout << '\n';}
    return 0;
  }


  BFS1();

  //cout << "hihi";
  int L = 0; int R = min(n,m)/2+1; //debug2, testcase 3
  while(L+1 < R)
  {
    int M = L + (R-L)/2;
    if(C(M)) L = M;
    else R = M;
  }
  cout << L << endl;
  for(int i = 1; i <= n; i++, cout << endl)for(int j = 1; j <= m; j++)
    cout << ".X"[d[i][j]>L];

  return 0;
}
