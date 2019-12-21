#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef pair<int, int> pii;
#define X first
#define Y second
#define pb push_back
#define mkp make_pair

const int maxn = 101;
const int INF = 100*100*9+1000;
int T;
int n, m;
char as[maxn][maxn];
bool vis[maxn][maxn];
int d[maxn][maxn];
pii s, t;

int d[2][4] =
{
  1, 0, 0, -1,
  0, 1, -1, 0
}

int bfs(int maxv)
{
  priority_queue<pii, vector<pii>, greater<pii> > pq;
  for(int i = 0; i < n; i++)for(int j = 0; j < m; j++) d[i][j] = INF, p[i][j] = mkp(-1,-1);
  pq.push(0, s);
}

int main(void) {
  ios::sync_with_stdio(0);
  cin.tie(0); cout.tie(0);
  cin >> T;
  for(int ti = 1; ti <= T; ti++)
  {
    cin >> n >> m;
    for(int i = 0; i < n; i++)
    for(int j = 0; j < m; j++)
    {
      cin >> as[i][j];
      if('0' <= a[i][j] && a[i][j] <= '9') a[i][j] = as[i][j] - '0';
      else if(a[i][j] == 'A') s = mkp(i,j);
      else if(a[i][j] == 'B') t = mkp(i,j);
    }
    int ans = INF;
    for(int maxv = 1; maxv <= 9; maxv++)
    {
      ans = min(ans, bfs(maxv));
    }
    ans = total - ans;

    cout << "Case #" << ti << ": " << ans << '\n';
  }
}
