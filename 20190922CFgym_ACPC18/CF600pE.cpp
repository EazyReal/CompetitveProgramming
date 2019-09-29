#include <bits/stdc++.h>
using namespace std;

#define pb push_back

typedef long long LL;
typedef vector<LL> VL;
//for (auto& x : xs)

LL n;
const LL MN = 100000+5;
LL c[MN];
LL sz[MN];
LL cnt[MN]; //n of the number in current subtree
LL ans[MN];
bool is_big[MN];
VL g[MN];
LL csum, maxn;

LL get_sz(LL x, LL p)
{
  LL ret = 1;
  for(auto s : g[x])if(s != p) ret += get_sz(s, x);
  return sz[x] = ret;
}

void add(LL x, LL p, LL val)
{
  cnt[c[x]] += val;
  if(cnt[c[x]] > maxn) {maxn = cnt[c[x]]; csum = c[x];}
  else if (cnt[c[x]] == maxn) {csum += c[x];}
  for(auto c : g[x]) if(c != p && !is_big[c])
  {
      add(c, x, val);
  }
}

void dfs(LL x, LL p, bool keep)
{
  LL bigc = -1;
  LL maxsz = -1;
  for(auto c : g[x]) if(c != p && sz[c] > maxsz) maxsz = sz[c], bigc = c;

  for(auto c : g[x]) if(c != p && c != bigc) dfs(c, x, 0);
  if(bigc != -1) dfs(bigc, x, 1), is_big[bigc] = 1;
  add(x, p, 1);
  /*
  do something
  */
  ans[x] = csum; //cout<<"hi"<<endl;

  if(bigc != -1) is_big[bigc] = 0;
  if(keep == 0) {add(x, p , -1); csum = 0; maxn = 0;}
}

int main()
{
  std::ios::sync_with_stdio(false);
  //std::cin.tie(0);

  cin >> n;
  for(int i = 0; i < n; i++) cin >> c[i];
  for(int i = 0; i < n-1; i++)
  {
    LL a, b;
    cin >> a >> b;//the bug, not 0-indexed
    g[a-1].pb(b-1);
    g[b-1].pb(a-1);
  }

  LL root = 0;
  get_sz(root, -1);
  for(int i = 0; i < n; i++) cnt[c[i]] = 0;
  for(int i = 0; i < n; i++) is_big[i] = 0;
  csum = 0;
  dfs(root, -1, 0);
  for(int i = 0; i < n; i++) cout << ans[i] << ((i==n-1) ? '\n' : ' ');

  return 0;
}
