#include <bits/stdc++.h>
#define LOCAL
using namespace std;

#define X first
#define Y second
#define pb push_back
#define mp make_pair
#define all(a) a.begin(), a.end()
#define rep(i, st, n) for (int i = (st); i < (n); ++i)
#define repinv(i, st, n) for (int i = ((n)-1); i >= (st); --i)
#define MEM(a, b) memset(a, b, sizeof(a));
#ifdef LOCAL
#define debug(x) std::cerr << #x << ": " << x << endl
#else
#define debug(x) 860111
#endif
#define fastIO() ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0)
#define fileIO(in, out) freopen(in, "r", stdin); freopen(out, "w", stdout)

typedef long long ll;
typedef unsigned long long ull;
typedef vector<int> vi;
typedef vector<ll> vll;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;
typedef long double ld;

//mt19937 mrand(random_device{}());
//mt19937_64 rng(chrono::steady_clock::now().time_since_epoch().count());
const ll mod=1e9+7;
//int rnd(int x) { return mrand() % x;}
ll powmod(ll a,ll b) {ll res=1;a%=mod; assert(b>=0); for(;b;b>>=1){if(b&1)res=res*a%mod;a=a*a%mod;}return res;}
ll gcd(ll a,ll b) { return b?gcd(b,a%b):a;}
pii operator+(const pii&x, const pii&y) { return mp(x.X+y.X, x.Y+y.Y);}
pii operator-(const pii&x, const pii&y) { return mp(x.X-y.X, x.Y-y.Y);}
//INT_MAX, ULLONG_MAX, LLONG_MAX or numeric_limits<int>::min()

inline ll read(){
	char ch=getchar();ll x=0,f=0;
	while(ch<'0' || ch>'9') f|=ch=='-',ch=getchar();
	while(ch>='0' && ch<='9') x=x*10+ch-'0',ch=getchar();
	return f?-x:x;
}

//------------------------------------------------------------------------//
int T;
const int maxn = 2e5+7;
int n;

//f(a,b)[i] = true => a, b is ok to concat at i
vector<bool> f(string &a, string &b) {
    int la = a.size(), lb = b.size();
    vector<bool> ret(la+1, true);
    for (int i = 0; i < la; i++) {
        for (int j = i, k = 0; j < la && k < lb; j++, k++) {
            if (a[j] != '?' && b[k] != '?' && a[j] != b[k]) {
                ret[i] = false;
                break;
            }
        }
    }
    return ret;
}

int calc(string &a, string &b, string &c) {
    vector<bool> ab = f(a, b), bc = f(b, c), ac = f(a, c);
    int la = a.size(), lb = b.size(), lc = c.size(), ans = la+lb+lc;
    for (int i = 0; i <= la; i++) { //a b contact
        for (int j = 0; j <= max(la, lb); j++) { //b c contact
            if (ab[i] && (j >= lb || bc[j]) && (i + j >= la || ac[i+j])) { //ok-ness
                ans = min(ans, max(max(la, i + lb), i + j + lc)); //update
            }
        }
    }
    return ans;
}

void solve()
{
	string a[3];
	cin >> a[0] >> a[1] >> a[2];
	//sort(all(a), cmp);

	int per[] = {0, 1, 2};
  int best = INT_MAX;
	do {
		string a1 = a[per[0]];
		string a2 = a[per[1]];
		string a3 = a[per[2]];
    best = min(best, calc(a1, a2, a3));
	} while ( std::next_permutation(per,per+3) );
	cout << best << endl;
	//debug(best);
  return;
}


signed main()
{
  fastIO();
  T = 1;
  //cin >> T; //this
  while(T--) solve();
  return 0;
}

/*
??? aaa bbb 6
?aa b?? aab 4
abcd bc cde 5
*/
