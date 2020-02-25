#include <bits/stdc++.h>

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

template<class T>
struct fenwick {
    vector<T> t;

    fenwick(int n) : t(n) {}

    void add(int i, T value) {
        for (; i < t.size(); i |= i + 1)
            t[i] += value;
    }

    // sum[0..i]
    T sum(int i) {
        T res{};
        for (; i >= 0; i = (i & (i + 1)) - 1)
            res += t[i];
        return res;
    }

    // returns min(p | sum[0..p] >= sum)
    // requires non-negative tree values
    int lower_bound(T sum) {
        int highest_one_bit = 1;
        while (highest_one_bit << 1 <= t.size()) highest_one_bit <<= 1;
        int pos = 0;
        for (size_t blockSize = highest_one_bit; blockSize != 0; blockSize >>= 1) {
            int p = pos + blockSize - 1;
            if (p < t.size() && t[p] < sum) {
                sum -= t[p];
                pos += blockSize;
            }
        }
        return pos;
    }
};

int T;
const int maxn = 5e5+5;
int n, k;
vector<int> a;

#define x first
#define v second

void solve()
{
	cin >> n;
	vector<pii> ps(n);
	for(auto& pi:ps) cin >> pi.x;
	for(auto& pi:ps) cin >> pi.v;
	sort(all(ps));
	vector<pii> vs(n);
	rep(i, 0, n) vs[i] = mp(ps[i].v, i)); //used init + pb cause wa on 4
	//compress v
	sort(all(vs));
	int prev = -1, vn = 0;
	rep(i, 0, n)
	{
		if(vs[i].X != prev) vn++, prev = vs[i].X;
		ps[vs[i].Y].v = vn;
	}
	ll ans = 0ll;
	fenwick<ll> sum_tree(n*4);
	fenwick<ll> cnt_tree(n*4);
	rep(i, 0, n)
	{
		ll c = cnt_tree.sum(ps[i].v);
		ll s = sum_tree.sum(ps[i].v);
		ans += ll(ps[i].x)*c - s;
		cnt_tree.add(ps[i].v, 1ll);
		sum_tree.add(ps[i].v, ps[i].x);
	}
	cout << ans << endl;

  return;
}


signed main()
{
  fastIO();
  //cin >> T;
  T = 1;
  while(T--) solve();
  return 0;
}
