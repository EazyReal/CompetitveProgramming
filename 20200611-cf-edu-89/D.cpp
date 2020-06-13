#include <bits/stdc++.h>

using namespace std;

#define X first
#define Y second
#define pb push_back
#define mp make_pair
#define all(a) a.begin(), a.end()
#define rep(i, st, n) for (int i = (st); i < (n); ++i)
#define fastIO() ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0)


//------------------------------------------------------------------------//

#define int long long

int T;
const int maxn = 2e5+5;
const int maxm = 5e5+5;
int n;
int ps[maxm];
vector<int> p;
int a[maxm];
pair<int,int> ans[maxm];

//check T
void solve()
{
  rep(i, 2, maxn)
  {
     if(!ps[i]) for(int x = i*2; x < maxn; x+=i) ps[x] = 1;
  }
  rep(i, 2, maxn) if(!ps[i]) p.push_back(i);
  cin >> n;
  rep(i, 0, n) cin >> a[i];
  rep(k, 0, n)
  {
    ans[k] = {-1, -1};
    if(a[k] <= 5) continue;
    for(int i : p)if(a[k]%i == 0)
    {
      if(i*i >= a[k]) break;
      if(gcd<int>(a[k]/i + i, a[k]) == 1) {ans[k] = {i, a[k]/i}; break;}
    }
  }

  rep(k, 0, n) cout << ans[k].first << " \n"[k==n-1];
  rep(k, 0, n) cout << ans[k].second << " \n"[k==n-1];
  return;
}


//g++ -o out -std=c++11 A.cpp


signed main()
{
  fastIO();
  T = 1;
  //cin >> T; //this
  rep(tc, 1, T+1)
  {
    //cout << "Case #" << tc << ": ";
    solve();
  }
  return 0;
}
