#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef pair<int, int> pii;
#define X first
#define Y second
#define pb push_back
#define mkp make_pair

int T;
int n;
const int maxn = 200+1;
const int maxn2 = maxn*maxn+1;
pii p[maxn];
bool G[maxn][maxn];
int ps1[maxn2];
int ps0[maxn2];

//void setv() misunderstand thought that want liar min, actually want false report min

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
    int cnt1 = 0;
    for(int i = 0; i < n; i++)for(int j = 0; j < n; j++) cin >> G[i][j], cnt1 += G[i][j];
    cnt1 -= n; //diagnal
    set<int> ds;
    map<int, int> idx;
    map<int, pii> mp;//dis to 0,1 val cnt
    for(int i = 0; i < n; i++)for(int j = i+1; j < n; j++)
    {
      int di = dist(p[i],p[j]);
      ds.insert(di);
      if(mp.find(di) == mp.end()) mp[di] = mkp(0,0);
      mp[di].X += (G[i][j] == 1);
      mp[di].X += (G[j][i] == 1);
      mp[di].Y += (G[i][j] == 0);
      mp[di].Y += (G[j][i] == 0);
    }
    int ansd = 0;
    int ansfr = cnt1;
    int i = 0;
    memset(ps1, 0, sizeof(ps1));
    memset(ps0, 0, sizeof(ps0));
    for(int di : ds)
    {
      idx[di] = i;
      if(i == 0) {ps1[i] = mp[di].X, ps0[i] = mp[di].Y; i++; continue;}
      ps1[i] = ps1[i-1] + mp[di].X;
      ps0[i] = ps0[i-1] + mp[di].Y;
      i++;
    }
    for(int di : ds)
    {
      int curfr;
      if(idx[di] == 0) curfr = ps1[ds.size()-1]-ps1[0]+ps0[0];
      else curfr =  ps0[idx[di]] + ps1[ds.size()-1] - ps1[idx[di]];
      if(curfr < ansfr) ansd = di, ansfr = curfr;
    }

    cout << "Case #" << t << ": " << ansd << ' ' << ansfr << '\n';
  }
}
