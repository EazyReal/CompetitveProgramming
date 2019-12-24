#include <bits/stdc++.h>

using namespace std;
#define pb push_back

typedef long long ll;

const int maxn = 80000*4+5;

int T;
ll R;
char c;
ll len; //len of objs
int stk[maxn]; //stack
int t[maxn]; //type of i th obj
int to[maxn];
ll mark[maxn];
vector<int> G[maxn];

ll dfs(int u)
{
  if(t[u] == 0) return 1ll;
  ll ret = (t[u]==1)?0ll:maxn;
  for(int v:G[u])
  {
    if(t[u] == 1) ret += dfs(v);
    if(t[u] == 2)
    {
      ll val = dfs(v);
      if(val < ret) to[u] = v, ret = val;
    }
  }
  return ret;
}

void dfs2(int u) //mark sol
{
  if(t[u] == 0) mark[u] = 1ll;
  if(t[u] == 1) for(int v:G[u]) dfs2(v);
  if(t[u] == 2) dfs2(to[u]);
}

int main()
{
  //ios::sync_with_stdio(false);
  //cin.tie(0); cout.tie(0);
  scanf("%d", &T);
  while(T--)
  {
    scanf("%lld", &R); //getline(cin, s);
    len = 0;

    int top = 0;
    while(1)
    {
      c = getchar();
      if(c == '\n') break;
      if(c == '(')
      {
        if(top) G[stk[top]].pb(len+1);
        stk[++top] = ++len;
        G[len].clear();
      }
      if(c == ')') --top;
      if(c == '*') t[++len] = 0, G[stk[top]].pb(len), G[len].clear(), mark[len]=0ll;
      if(c == 'P') t[stk[top]] = 1;
      if(c == 'S') t[stk[top]] = 2;
    }
    ll ret = dfs(1);
    dfs2(1);
    printf("REVOLTING ");
    for(int i = 1; i <= len; i++)if(t[i] == 0) printf("%lld ", ret*R*mark[i]);
    printf("\n");
  }

  return 0;
}
