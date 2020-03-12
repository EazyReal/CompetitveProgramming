#include <bits/stdc++.h>
//#define LOCAL
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
//mt19937_64 rng(chrono::steady_clock::now().time_since_epoch().cnt());
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
#define int ll
int T;
const int maxn = 2e5+7;
int n;
int a[maxn], b[maxn], c[maxn], tmp[maxn];

int cnt;//新增
void Merge(int* A,int left,int mid,int right,int* C)
{	//Merge可以將兩個有序的數組排好序,時間複雜度:o(n)
	int i=left;
	int j=mid+1;
	int k=left;
	while(i <= mid && j <= right)
	{
		if(A[i] <= A[j])
			C[k++]=A[i++];
		else
		{
			C[k++]=A[j++];
			cnt += mid-i+1;//新增
		}
	}
	while(i <= mid)
		C[k++]=A[i++];
	while(j <= right)
		C[k++]=A[j++];
	//C[]已經有序，將C[]中數據複製回原數組A[]
	for(int i=left;i <= right;++i)
		A[i]=C[i];
}
void MergeSort(int* A,int left,int right,int* C)//假定MergeSort能將一個亂序數組A排好序．
{
	if(left < right)
	{
		int mid=(left+right)/2;
		MergeSort(A,left,mid,C);//排好一個數組1
		MergeSort(A,mid+1,right,C);//排好一個數組2
		Merge(A,left,mid,right,C); //合併兩個有序的數組
	}
}

//check T
void solve()
{
	cin >> n;
	rep(i, 0, n) cin >> a[i];
	rep(i, 0, n) cin >> b[i];
	rep(i, 1, n+1) c[i] = a[i-1]-b[i-1];
	cnt = 0;
	MergeSort(c,1,n,tmp);
	cout << cnt << endl;

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
