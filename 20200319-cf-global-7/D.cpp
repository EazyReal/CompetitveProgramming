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
//ll a[maxn];

int arr[100001];
/*
int solve_lpp(string s) {
	if(s.size() == 0) return 0;
    string res = s;
    int len;
    reverse(s.begin(), s.end());
    s = res + "$" + s;
    arr[0] = 0;

    int i=0, j=1;
    len = s.length();
    while(j < len){
        if(s[i] == s[j]){
            arr[j] = i+1;
            i++; j++;
        } else {
            if(i>=1){
                i = arr[i-1];
            }else{
                arr[j] = 0;
                j++;
            }
        }
    }
    return res.length() - arr[len-1];
}
*/


int solve_lpp(string s){
	string rev="",str=s;
    int m=s.size(),longestPalindromicPrefix=1;
    if(m==0 || m==1)    longestPalindromicPrefix=m;
    for(int i=m-1;i>=0;i--)
        rev+=s[i];
    s+='#';
    s+=rev;
    int n=s.size(),z[n+4],l=0,r=0;
    for(int i=1;i<n;i++){
        if(i>r){
            l=r=i;
            while(r<n && s[r-l]==s[r])
                r++;
            z[i]=r-l,r--;
        }
        else{
            int k=i-l;
            if(z[k]<r-i+1)
                z[i]=z[k];
            else{
                l=i;
                while(r<n && s[r-l]==s[r])
                    r++;
                z[i]=r-l,r--;
            }
        }
    }

    for(int i=m+1;i<n;i++){
        if(2*z[i]>=2*m-i && z[i]>longestPalindromicPrefix)
            longestPalindromicPrefix=z[i];
    }
		return longestPalindromicPrefix;
}

bool is_palin(string s)
{
	int n = s.size();
	rep(i, 0, n/2+1) if(s[i] != s[n-1-i]) return false;
	return true;
}

//check T
void solve()
{
	//cin >> n; rep(i, 0, n) cin >> a[i];
	string s;
	cin >> s;
	if(is_palin(s)) {cout << s << endl; return;}
	n = s.size();
	int l = 0, r = n-1;
	string eq;
	while(s[l] == s[r] && l < r) l++, r--, eq.pb(s[l-1]);
	string req = eq;
	reverse(all(req));
	if(l == r) eq.pop_back();

	string part = s.substr(l, n-l*2);
	string rpart = part;
	reverse(all(rpart));

	//int test = solve_lpp("ecdfd");
	//debug(test);

	//cerr << part << endl;
	//cerr << rpart << endl;

	int ls = solve_lpp(part);
	int rs = solve_lpp(rpart);
	//debug(ls); debug(rs);
	if(ls > rs)
	{
		cout << eq << part.substr(0, ls) << req;
	}else{
		cout << eq;
		repinv(i, 0, rs) cout << part[part.size()-1-i] ;
		cout << req;
	}
	cout << endl;

  return;
}


signed main()
{
  fastIO();
  T = 1;
  cin >> T; //this
  while(T--) solve();
  return 0;
}
