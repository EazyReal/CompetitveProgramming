#include <bits/stdc++.h>

using namespace std;
typedef long long ll;

int n, m, v, p;
const int maxn = 100000+5;
const int maxm = 1e9+5;
ll a[100000+5];
ll b[maxn];

//binary search for ans
//use strategy to fill in O(nlogn), total n*logn*logn
//but something want wrong
//it's kind of unconfortable to code when have a cold :(

bool C(int M)
{
  //cout << "M = " << M << endl;
  ll Mval = a[M] + m;
  while(M > 0 && a[M] == a[M-1]) M--; //move to left most same value
  if(M <= n-v){
    for(int i = 0; i < n; i++) b[n-1-i] = a[n-1-i] + (i<v-1?m:0);
    b[M] = a[M] + m;
    sort(b, b+n, greater<ll>());
    //cout << M << " is ok by judge 1" << endl;
    return b[p-1] <= Mval;
  }
  else{
    //cout << "judge2" << endl;
    int vt = v-(n-1 - M + 1); //voted right
    assert(vt >= 0);
    //cout << "vt =" << vt  << endl;
    for(int i = 0; i < M; i++) b[i] = a[i];
    int bigger = 0;
    for(int i = 0; i < M; ++i)
    {
      if(vt <= 0) {bigger += (b[i]>Mval); continue;}
      if(b[i] > Mval) --vt, bigger++;
      else
      {
        //cout <<  "break at " << i << endl;
        if(Mval-b[i] >= vt){
          bigger += max(0, vt-(M-i));
          break;
        }else
        {
          --vt, bigger++;
        }
      }
    }
    //for(int i = 0; i < M; i++) cout << b[i] << ' '; cout << endl;
    //cout << "bigger = " << bigger << endl;
    //cout << M << " is ok by judge 2" << endl;
    return bigger < p;
  }
}

int main()
{
  cin >> n >> m >> v >> p;
  for(int i = 0; i < n; i++) cin >> a[i];
  sort(a, a+n, greater<ll>());
  //cout <<"sorted a"<< endl;
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
