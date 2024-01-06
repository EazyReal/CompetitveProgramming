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

int T, n;
const int maxn = 1e5+5;
bool consider[maxn];
//dp[ith bit][0/1] = down min;
//int dp[i][][];

//thought notice that X can be decompite
//use iterartion to cross out max until cant (ie: presence of 0)
//cross out upper bit of the max each turn? no

//dfs notice the case of all 0; (no need dp actually)

//after contest : my solution is ok
//remain time complexity analysis and can improve the deviding part with binary search!!(less memory)
// complexity is low due to each element is visit only at most 30 times down the search tree

//one time AC 2020/1/11 morning, so sad:(,  shouldnt waste time on false solution, and analysis more

int dfs(vector<int> arr, int bit, int val)
{
  int xi = 1 << bit;
  if(val == 0) xi = 0;
  assert(bit >= 0);
  assert(xi >= 0);
  int ii = 1 << bit;
  //if(arr.size() == 1 ){return arr[0]^xi;}
  if(bit == 0)
  {
    int maxv = 0;
    for(int ele: arr) maxv = max(maxv, ele^xi);
    return maxv;
  }
  vector<int> a0;
  vector<int> a1;
  for(int ele : arr)
  {
    ele ^= xi;
    if(ele&ii) a1.pb(ele);
    else a0.pb(ele);
  }
  --bit;
  //all zero is possible
  if(a1.size() == 0) return min(dfs(a0, bit, 0), dfs(a0, bit, 1));
  if(a0.size() == 0) return INT_MAX;
  //else only care 1 side
  return min(dfs(a1, bit, 0), dfs(a1, bit, 1));
}

signed main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    cin >> n;
    vector<int> a;
    set<int> s;
    int tmp;//at most 30bit 11111111..111
    //rep(i, 0, 30) debug((1<<i));
    rep(i, 0, n)
    {
      cin >> tmp;
      if(s.find(tmp) == s.end()) a.push_back(tmp);
      s.insert(tmp);
    }
    n = a.size();
    //rep(i, 0, n) cout << a[i] << ' '; cout << endl;
    //0-indexed bit
    int minv = min(dfs(a, 29, 0), dfs(a, 29, 1));
    cout << minv << endl;
    /*
    for(int bit = 29; bit >= 0; --bit)
    {
      int max0, max1;
      max0 = max1 = 0;
      rep(i, 0, n)
      {
        a0[i] = a[i], a1[i] = a[i]^(1<<bit);
        sort(a0);
        sort(a1);
      }

    }
    */

    return 0;
}
