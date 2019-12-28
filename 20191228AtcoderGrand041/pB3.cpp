#include <bits/stdc++.h>

using namespace std;
typedef long long ll;

int n;
ll m , v, p;
const int maxn = 100000+5;
ll a[maxn];
ll s[maxn];

//after context finish b

bool C(int k)
{
  if(k < p) return true;
  if(a[k]+m < a[p-1]) return false;
  ll sum = (p-1+n-k)*m; //biggest p-1 and smaller then u all vote
  for(int i=p-1; i<k; ++i) sum += min(m, a[k]+m-a[i]);
  //no two judge will vote for the same(<=m)
  //vote over v is ok because removal wont change answer
  //will some judge vote below v? to proof, see editorial explanation
  return sum >= m*v; // this will over flow :(, debug so long
}

/*
Let Bi ≤ M be the number of votes that can be cast for problem i, and ∑Bi ≥ MV .
Write down a sequence where problem i is repeated Bi times consecutively.
Now, assign votes by judges 1, 2, . . . , M, 1, 2, . . . , M, . . . to the first MV problems in the sequence,
in this order. It’s easy to see that every problem gets at most Bi votes,
every judge votes exactly V times,
and no judge votes for the same problem twice.(Bi ≤ M)
*/

int main()
{
  cin >> n >> m >> v >> p;
  for(int i = 0; i < n; i++) cin >> a[i];
  sort(a, a+n, greater<ll>());
  int L = -1; //n>=2, M wont < 0
  int R = n;
  int M;
  while(L < R-1) //index
  {
    M = (L+R)/2;
    if(C(M)) L = M;
    else R = M;
  }
  cout << L+1 << endl;
  return 0;
}
