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
vector<pair<pll, pll>> arr;
vector<pll> pos;
const ll M = 1e9;
const ll mM = -1e9;

signed main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    cin >> n >> m;
    arr.resize(m);
    pos.resize(n);
    ll ai, bi, dx, dy;
    rep(i, 0, m)
    {
      cin >> ai >> bi >> dx >> dy;
      if(ai > bi) swap(ai, bi);
      arr[i].X.X = --ai;
      arr[i].X.Y = --bi;
      arr[i].Y.X = dx;
      arr[i].Y.Y = dy;
    }
    sort(all(arr));
    pos[0].X = 0; pos[0].Y = 0;
    ll minxcor = std::numeric_limits<ll>::max();
    ll maxxcor = std::numeric_limits<ll>::min();
    ll minycor = std::numeric_limits<ll>::max();
    ll maxycor =  std::numeric_limits<ll>::min();
    rep(i, 0, m)
    {
      pos[arr[i].X.Y].X = pos[arr[i].X.X].X + arr[i].Y.X;
      pos[arr[i].X.Y].Y = pos[arr[i].X.X].Y + arr[i].Y.Y;
      minxcor = min(minxcor, pos[arr[i].X.Y].X);
      maxxcor = max(maxxcor, pos[arr[i].X.Y].X);
      minycor = min(minycor, pos[arr[i].X.Y].Y);
      maxycor = max(maxycor, pos[arr[i].X.Y].Y);
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
