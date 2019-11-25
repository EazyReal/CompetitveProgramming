#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>

using namespace std;
using namespace __gnu_pbds;

#define pb push_back
typedef pair<int, int> pii;
typedef array<int, 3> Query; //queru (m,k,i) with m-size array, kth value, ith query
typedef tree<pii,null_type,less<pii>,rb_tree_tag,tree_order_statistics_node_update> RBTree;

const int maxn = 200000+5;
const int maxm = 200000+5;

int T, n, m;

int main()
{
  ios::sync_with_stdio(false);
  //cin.tie(0);
  cin >> n;
  vector<pii> a;
  for(int i = 0; i < n; i++)
  {
    int x; cin >> x;
    a.pb({x, -i}); //same val => greater i should be in the back
  }
  sort(a.begin(), a.end(), greater<pii> );

  cin >> m;
  vector<Query> q;
  for(int i = 0; i < m; i++)
  {
    int tm, tk;
    cin >> tm >> tk;
    q.pb({tm, tk, i});
  }
  sort(q.begin(), q.end(), less<Query> );

  RBTree rbt;
  int sz = 0;
  int ans[maxm];
  for(int i = 0; i < m; i++)
  {
    while(sz != q[i][0])
    {
      rbt.insert({-a[sz].second, a[sz].first});
      sz++;
    }
    ans[q[i][2]] = rbt.find_by_order(q[i][1]-1)->second;
  }

  for(int i = 0; i < m; i++) cout << ans[i] << endl;

  return 0;
}
