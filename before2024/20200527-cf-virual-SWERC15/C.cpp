#include <bits/stdc++.h>

#define rep(i,s,t) for(int i = s; i < t; ++i)
#define ll long long
#define X first 
#define Y second

using namespace std;

int T;
int n;
const int maxn = 1e6+5;
int a[maxn];
int nxt[maxn];
int pre[maxn];

using pli = pair<ll,int>;

signed main()
{
  ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
  cin >> T;
  while(T--)
  {
    cin >> n;
    rep(i, 0, n) cin >> a[i];
    rep(i, 0, n+2) nxt[i] = i+1;
    rep(i, 0, n+2) pre[i] = i-1;
    set<pair<ll,int>> vs;
    //init choice
    rep(i, 0, n-1) vs.insert(pli(a[i] +a[nxt[i]], i));
     // merge step
    
    ll cost = 0;
    rep(r, 0, n-1)
    {
      pli cur = *vs.begin();
      int pos = cur.Y;
      ll val = cur.X;
      cost += val;

      //cerr << "set"<<endl;
      /*for(auto& ele : vs)
      {
        cerr << ele.X << " " << ele.Y << endl;
      }*/
      //cerr << "val " << r << " is "<<  val << endl;
      //cerr << "pos " << r << " is "<<  pos << endl;

      //erase yhe merged
      if(nxt[nxt[pos]] < n){
        vs.erase(pli(a[nxt[pos]]+a[nxt[nxt[pos]] ], nxt[pos]));
      }
      
      if(pre[pos] >= 0){
        assert(vs.find(pli(a[pre[pos]]+a[pos], pre[pos])) != vs.end());
        vs.erase(pli(a[pre[pos]]+a[pos], pre[pos]));
        //a[pre[pos]] -= a[pos];
        //a[pre[pos]] += val;
        vs.insert(pli(a[pre[pos]]+val, pre[pos]));
      }

      a[pos] = val;
      //deal with the link
      nxt[pos] = nxt[nxt[pos]];
      pre[nxt[pos]] = pos;
      vs.erase(cur);

      //rep(i, 0, n+1) cout << pre[i] << " "; cout << endl;
      //rep(i, 0, n+1) cout << nxt[i] << " "; cout << endl;


      //not last
      if(nxt[pos] < n)
      {
        vs.insert(pli(a[pos] +a[nxt[pos]], pos));
      }
    }
    cout << cost << endl;
    
  }

  return 0;
}