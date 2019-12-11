#include <bits/stdc++.h>

using namespace std;
#define pb push_back

typedef long long ll;

//O(n^2logn) atmost => try to build up some state and transition
//try to consider the first i numbers end with j(with j <= i)
//dp[i+1][j] = {
// if(s[i+1] == '>') sigma dp[i][j..i] (use j => all the front >= j +=1)
// else sigma dp[i][1...j-1]
//}
//O(n^3) => O(n^2) by prefix sum

int n, k;
string s;
const int maxn = 3000+5;
const ll MOD = 1e9+7;
ll C[maxn][maxn];//MOD Combination
ll fac[maxn];// MOD factorial
ll dp[maxn][maxn];

inline void add(ll& a, ll b){ a+=b; a%=MOD;};

ll dfs(int l, int r) // 1 index, for i , left char = s[i-2],right char s[i-1]
{
  //cout << "enter dfs " << l << ' ' << r  << endl;
  if(dp[l][r] != -1ll) return dp[l][r];
  if(l == r) return dp[l][r] = 1ll;
  ll ret = 0ll;
  int len = r-l+1;
  if(s[l-1] == '<') add(ret, dfs(l+1, r)); //min goes to l, all other right
  if(s[r-2] == '>') add(ret, dfs(l, r-1)); //min goes to r, all other left
  for(int i = l+1; i <= r-1; i++) if(s[i-2] == '>' && s[i-1] == '<')
  {
    ret += (C[len-1][i-l]*dfs(l, i-1)%MOD)*dfs(i+1,r)%MOD;
    ret %= MOD;
  }
  return dp[l][r] = ret;
}

int main()
{
  ios::sync_with_stdio(false);
  cin.tie(0); cout.tie(0);
  cin >> n;
  fac[0] = 0ll;
  for(ll i = 1ll; i <= n; i++)  fac[i] = (fac[i-1]*i)%MOD;
  C[0][0] = 1ll;
  for(int i = 0; i <= n; i++) C[i][0] = C[i][i] = 1ll, C[i][i+1] = 0ll;
  for(int i = 2; i <= n; i++)for(int j = 1; j < i; j++) C[i][j] = (C[i-1][j-1] + C[i-1][j])%MOD;
  for(int i = 2; i <= n; i++)for(int j = 1; j < i; j++) C[i][j] = (C[i-1][j-1] + C[i-1][j])%MOD;
  //for(int i = 0; i <= n; i++, cout << endl)for(int j = 0; j <= i; j++) cout << C[i][j] << ' ';

  cin >> s;//'<' + s + '>'; cout << s << endl;
  memset(dp, -1ll, sizeof(dp));
  ll ans = dfs(1,n);
  cout <<  ans << endl;

  return 0;
}
