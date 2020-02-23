#include <bits/stdc++.h>
//this no work
using namespace std;

#define X first
#define Y second
#define pb push_back
#define mp make_pair
#define all(a) a.begin(), a.end()
#define rep(i, st, n) for (int i = (st); i < (n); ++i)
#define repinv(i, st, n) for (int i = ((n)-1); i >= (st); --i)
#define MEM(a, b) memset(a, b, sizeof(a));

#define debug(x) std::cout << #x << ": " << x << endl
#define fastIO() ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0)
#define fileIO(in, out) freopen(in, "r", stdin); freopen(out, "w", stdout)

typedef long long ll;
typedef unsigned long long ull;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;
typedef long double ld;

mt19937 mrand(random_device{}());
const ll mod=1e9+7;
int rnd(int x) { return mrand() % x;}
ll powmod(ll a,ll b) {ll res=1;a%=mod; assert(b>=0); for(;b;b>>=1){if(b&1)res=res*a%mod;a=a*a%mod;}return res;}
ll gcd(ll a,ll b) { return b?gcd(b,a%b):a;}
//INT_MAX, ULLONG_MAX, LLONG_MAX or numeric_limits<int>::min()

inline ll read(){
	char ch=getchar();ll x=0,f=0;
	while(ch<'0' || ch>'9') f|=ch=='-',ch=getchar();
	while(ch>='0' && ch<='9') x=x*10+ch-'0',ch=getchar();
	return f?-x:x;
}

//------------------------------------------------------------------------//
int T;
const int maxn = 5e4+7;
int n;
//vector<int> es;
set<int> adjc[maxn];
set<int> dupc[maxn];
vector<pair<int,int>> G[maxn];
int tag[maxn];

void add_edge(int a, int b, int c)
{
  if(adjc[a].count(c)) dupc[a].insert(c);
  if(adjc[b].count(c)) dupc[b].insert(c);
  adjc[a].insert(c);
  adjc[b].insert(c);
  G[a].pb(mp(b, c));
  G[b].pb(mp(a, c));
}

bool dfs_dup(int u, int f, int c)
{
  bool ret = 1;
	if(tag[u] == 1) return 1;
  tag[u] = 1; //from dup edges => not solution, will not mark p btw
  for(pii& e: G[u])if(e.X != f) //if not checked by dup, should check
  {
    ret &= (e.Y != c); //bad in cut => no good points
    ret &= dfs_dup(e.X, u, e.Y);
  }
  return ret;
}

bool dfs_all(int u)
{
  bool ret = 1;
  //check dup color edges if wrong, should consider back to u so no mark tag here
  for(pii& e:G[u])if(dupc[u].count(e.Y)) ret &= dfs_dup(e.X, u, e.Y); //check vis 1 here : no check => bug
	if(!ret) return 0;
	tag[u] = 2; //2nd phase, check other O(n) on dfs(all)
	for(pii& e:G[u])if(!tag[e.X]) ret &= dfs_all(e.X);
  return ret;
}

signed main()
{
  fastIO();

  cin >> n;
  int a, b, c;
  rep(i, 0, n-1)
  {
    cin >> a >> b >> c;
    add_edge(--a, --b, c);
  }
  bool allnodup = 1;
  rep(i, 0, n) allnodup &= (dupc[i].size() == 0);
  if(allnodup)
  {
    cout << n;
    rep(i, 1, n+1) cout << i << endl;
  }
  else
  {
    memset(tag, 0, sizeof(tag));
		int start = -1;//dup point to start to ensure start point will be checked
		rep(i, 0, n)if(dupc[i].size()) start = i;
    bool ok = dfs_all(start);
    if(ok)
    {
      vector<int> ans;
      rep(i, 0, n) if(tag[i] == 2) ans.pb(i+1);
      //sort(all(ans));
      cout << ans.size() << endl;
      for(int x : ans) cout << x << endl;
    }
    else cout << 0 << endl;
  }

  return 0;
}

/*
//#include<bits/stdc++.h>

#include<iostream>
#include<algorithm>
#include<cstdio>
#include<string>
#include<cstring>
#include<vector>
#include<set>


using namespace std;
typedef long long ll;
typedef pair<int, int> P;

const int maxn = 5e4 + 7;
const int maxd = 1e9 + 7;

const ll mod = 998244353;
const int INF = 0x7f7f7f7f;

int n;

struct node {
    int v, c;
};
vector<node> vec[maxn];
set<int> st[maxn];
set<int> er[maxn];

int vis[maxn];
bool flag = true;

void init() {
    for(int i = 1; i <= n; ++i) {
        vec[i].clear();
        st[i].clear();
        vis[i] = 0;
    }
    flag = true;
}

void print1() {
    printf("%d\n", n);
    for(int i = 1; i <= n; ++i) {
        printf("%d\n", i);
    }
}

bool ER(int id, int f, int c) {
    if(vis[id] == 1) return false;
    vis[id] = 1;
    for(auto i : vec[id]) {
        if(i.v == f) continue;
        if(i.c == c) return true;
        if(ER(i.v, id, i.c)) return true;
    }
    return false;
}
void solve(int id) {
    for(auto i : er[id]) {
        for(auto j : vec[id]) {
            if(j.c == i) {
                if(ER(j.v, id, i)) {
                    printf("0\n");
                    flag = false;
                    return;
                }
            }
        }
    }
    vis[id] = 2;
    for(auto i : vec[id]) {
        if(!vis[i.v]) {
            solve(i.v);
        }
    }
}
void work() {
    vector<int> ans;
    for(int i = 1; i <= n; ++i) {
        if(vis[i] == 2) ans.push_back(i);
    }
    printf("%d\n", ans.size());
    for(auto i : ans) {
        printf("%d\n", i);
    }
}
int main() {
    scanf("%d", &n);
    init();
    for(int i = 1; i < n; ++i) {
        int a, b, c;
        scanf("%d%d%d", &a, &b, &c);
        vec[a].push_back(node{b, c});
        vec[b].push_back(node{a, c});

        if(st[a].count(c)) er[a].insert(c);
        else st[a].insert(c);
        if(st[b].count(c)) er[b].insert(c);
        else st[b].insert(c);
    }
    int x = -1;
    for(int i = 1; i <= n; ++i) {
        if(er[i].size()) {
            x = i;
            break;
        }
    }
//    cout << x << " =++= ==++ " << endl;
    if(x == -1) {
        print1();
    }
    else {
        solve(1);
        if(flag) {
            work();
        }
    }

    return 0;
}
*/
