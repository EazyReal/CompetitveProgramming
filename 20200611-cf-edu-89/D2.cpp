#include <bits/stdc++.h>

using namespace std;

#define X first
#define Y second
#define pb push_back
#define all(a) a.begin(), a.end()
#define rep(i, st, n) for (int i = (st); i < (n); ++i)
#define fastIO() ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0)


//------------------------------------------------------------------------//

#define int long long

int T;
const int maxn = 2e7+5;
const int maxm = 5e5+5;
int n;
int mp[maxn];
int a[maxm];
pair<int,int> ans[maxm];

//check T
// AC
void solve()
{
  rep(i, 2, maxn)if(!mp[i])
  {
    //mp[i] = i;
    for(int j = i; j < maxn; j+=i) mp[j] = i;
  }
  cin >> n;
  rep(i, 0, n) cin >> a[i];
  rep(k, 0, n)
  {
    int p = mp[a[k]], q = 1;
		while(a[k]%p==0) a[k] /= p, q *= p; // depart into min p divisor and other part
		if(a[k]==1) ans[k] = {-1,-1};
		else ans[k] = {a[k], q};
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
