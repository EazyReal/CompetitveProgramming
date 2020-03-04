#include <bits/stdc++.h>
using namespace std;
#define X first
#define Y second
#define pb push_back
#define mp make_pair
#define all(a) a.begin(), a.end()
#define rep(i, st, n) for (int i = (st); i < (n); ++i)
#define repinv(i, st, n) for (int i = ((n)-1); i >= (st); --i)
#define debug(x) std::cout << #x << ": " << x << endl
typedef long long ll;
//INT_MAX, ULLONG_MAX, LLONG_MAX or numeric_limits<int>::min()

//------------------------------------------------------------------------//
int T;
const int maxn = 2e5+7;
int n;
ll c;
ll h[maxn];
ll dp[maxn];
ll dq[maxn], l, r;

inline ll m(int j) {return -2*h[j];}
inline ll b(int j) {return dp[j]+h[j]*h[j];}

bool is_cross_before(int newl, int dq1, int dq2)
{
  if ( (b(dq1)-b(newl)) * (m(dq1)-m(dq2)) <= (b(dq2)-b(dq1)) * (m(newl)-m(dq1)) ) return 1;
  //if(contact_pont(newl, dq1) <= contact_pont(dq1, dq2)) return 1;
  return 0;
}

ll f(int x, int id)
{
  return m(id)*x + b(id);
}

bool nxt_is_better(int x, int f1, int f2)
{
  //cout << f(x, f1) << " " << f(x, f2) << endl;
  return f(x, f1) >=  f(x, f2);
}

void solve()
{
  cin >> n >> c;
  rep(i, 1, n+1) cin >> h[i];

  l = 0, r = 0; //l is front, r is back+1
  //sz =
  dp[1] = 0;
  dq[r++] = 1;
  rep(i, 2, n+1)
  {
    //cout << "the deque" << endl;
    //rep(ii, l, r) cout << dq[ii]<< " \n"[ii == r-1];
    while(r-l > 1 && nxt_is_better(h[i], dq[l], dq[l+1])) //pop off useless of cur convex(=>) //type dq[l+1]=>dp[l+1]
    {
      l++;
    }
    int cur = dq[l];
    //cout << i << "th use " << cur << endl;
    dp[i] = dp[cur] + (h[i]-h[cur])*(h[i]-h[cur]) + c; //update dp
    dq[r++] = i; //add new line for i

    while(r-l > 2 && is_cross_before(dq[r-1], dq[r-2], dq[r-3])) //sz >= 3, cross off useless line
    {
      dq[r-2] = dq[r-1]; //mistake line
      r--;
    }

  }
  cout << dp[n] << endl;
  return;
}

/*
rep(j, 1, i)
{
  dp[i] = min(dp[j] + i*i-2*i*j+j*j + c); // c+i*i+ (dp[j] -2*i*j)
}
*/

signed main()
{
  ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
  T = 1;
  //cin >> T; //this
  while(T--) solve();
  return 0;
}
