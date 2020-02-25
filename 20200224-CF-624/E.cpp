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
int T;
const int maxn = 5e5+5;
int n, k;
vector<int> a;


void solve()
{
	cin >> n >> k;
	a.resize(k);
	rep(i, 0, k) cin >> a[i];
  return;
}


signed main()
{
  fastIO();
  cin >> T;
  //T = 1;
  while(T--) solve();
  return 0;
}

/*
#include <iostream>

using namespace std;

const int kMaxN = 5001;

int c[kMaxN], a[kMaxN][kMaxN], f[kMaxN];
int t, n, d;

bool Check() {
  d = n * (n - 1) / 2 - d;
  if (d < 0) {
    return 0;
  }
  for (int i = n - 1, j = 1, k; i > j && d; i--) {
    k = min(i - j, d);
    d -= k;
    k = i - k;
    f[i + 1] = a[k - 1][c[k] / 2];
    a[k][c[k]++] = i + 1;
    if (c[j] >= (1 << j)) {
      j++;
    }
  }
  return !d;
}

int main() {
  cin >> t;
  while (t--) {
    cin >> n >> d;
    for (int i = 0; i < n; i++) {
      c[i] = 1;
      a[i][0] = i + 1;
      f[i + 1] = i;
    }
    if (Check()) {
      cout << "YES" << endl;
      for (int i = 2; i <= n; i++) {
        cout << f[i] << " ";
      }
      cout << endl;
    } else {
      cout << "NO" << endl;
    }
  }
  return 0;
}
*/
