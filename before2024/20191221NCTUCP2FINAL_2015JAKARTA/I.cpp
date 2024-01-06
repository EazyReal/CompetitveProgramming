#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef pair<int, int> pii;
#define X first
#define Y second
#define pb push_back

int T;
int n;
const int maxn = 200+1;
const int maxn2 = maxn*maxn+1;
pii p[maxn];
bool l[maxn2];
bool G[maxn][maxn];
bool ps1[maxn2];

struct Report{
  int d, i, j;
};

//void setv() misunderstand thought that want liar min, actually want false report min

bool cmp(Report&lhs, Report&rhs)
{
  return lhs.d < rhs.d;
}

int dist(pii a, pii b)
{
  return (a.X-b.X)*(a.X-b.X)+(a.Y-b.Y)*(a.Y-b.Y);
}


int main(void) {
  ios::sync_with_stdio(0);
  cin.tie(0); cout.tie(0);
  cin >> T;
  for(int t = 1; t <= T; t++)
  {
    cin >> n;
    for(int i = 0; i < n; i++) cin >> p[i].X;
    for(int i = 0; i < n; i++) cin >> p[i].Y;
    for(int i = 0; i < n; i++)for(int j = 0; j < n; j++) cin >> G[i][j];
    vector<Report> rs;
    for(int i = 0; i < n; i++)for(int j = i+1; j < n; j++) rs.pb({dist(p[i],p[j]), i, j});
    sort(rs.begin(), rs.end(), cmp);
    int ansd = 0;
    int ansl = 0;
    for(Report x : rs)
    {
      int i = x.i; int j=x.j;
      if(x.d <= ansd) { if(G[i][j] != 1) ansl++; if(G[j][i] != 1) ansl++;}
      if(x.d > ansd) {if(G[i][j] != 0) ansl++; if(G[j][i] != 0) ansl++;}
    }
    for(Report r : rs)
    {
      int nv = r.d; //now Visibility
      int nl = 0; //now liar
      for(Report x : rs)
      {
        int i = x.i; int j=x.j;
        if(x.d <= nv) { if(G[i][j] != 1) nl++; if(G[j][i] != 1) nl++;}
        if(x.d > nv) {if(G[i][j] != 0) nl++; if(G[j][i] != 0) nl++;}
      }
      //for(int i = 0; i < n; i++) nl += l[i];
      if(nl < ansl) ansl = nl, ansd = nv;
    }

    cout << "Case #" << t << ": " << ansd << ' ' << ansl << '\n';
  }
}
