#include <bits/stdc++.h>

using namespace std;
typedef long long ll;

int n, m, v, p;
const int maxn = 100000+5;
const int maxm = 1e9+5;
ll a[100000+5];
ll b[maxn];
ll c[maxn]; // used vote

bool C(int M)
{
  //cout << "M = " << M << endl;
  ll Mval = a[M] + m;
  while(M > 0 && a[M] == a[M-1]) M--; //move to left most same value
  if(M <= n-v){
    for(int i = 0; i < n; i++) b[n-1-i] = a[n-1-i] + (i<v-1?m:0);
    b[M] = a[M] + m;
  }
  else{
    int tot = v*m;
    for(int i = 0; i < n; i++) b[i] = a[i];
    for(int i = n-1; i >= M ; --i) b[i] += m, tot -= m;
    sort(b, b+M, greater<ll>()); //0 to M-1
    for(int i = 0; i < M && tot>0; ++i)
    {
      if(b[i] > Mval) c[i]=m, b[i] += m, tot -= m;
      else c[i] = min(ll(m), Mval-b[i]), b[i] += c[i], tot -= c[i];
    }
    for(int i = 0; i < M && tot>0; ++i)
    {
      b[i] += m-c[i], tot -= m-c[i];
    }
    assert(tot <= 0);
  }
  //cout << b[M] << endl;
  sort(b, b+n, greater<ll>());
  //for(int i = 0; i < n; i++) cout << b[i] << ' '; cout << endl;
  if(b[p-1] <= Mval) return true;
  else return false;
}

int main()
{
  cin >> n >> m >> v >> p;
  for(int i = 0; i < n; i++) cin >> a[i];
  sort(a, a+n, greater<ll>());
  //for(int i = 0; i < n; i++) cout << a[i] << ' '; cout << endl;
  int L = 0;
  int R = n;
  int M;
  while(L < R-1) //index
  {
    M = (L+R)/2;
    if(C(M)) L = M;
    else R = M;
  }
  while(L < n-1 && a[L] == a[L+1]) ++L;
  cout << L+1 << endl;

  return 0;
}


/*
int L = 1;
int R = n;
int M;
while(L < R+1)
{
  M = (L+R)/2
  if(C(M))
}
cout << L << endl;
*/
