/*
    if you can't see the repay
    Why not just work step by step
    rubbish is relaxed
    to ljq
*/
#include <cstdio>
#include <cstring>
#include <iostream>
#include <queue>
#include <cmath>
#include <map>
#include <stack>
#include <set>
#include <sstream>
#include <vector>
#include <stdlib.h>
#include <algorithm>
using namespace std;

#define dbg(x) cout<<#x<<" = "<< (x)<< endl
#define dbg2(x1,x2) cout<<#x1<<" = "<<x1<<" "<<#x2<<" = "<<x2<<endl
#define dbg3(x1,x2,x3) cout<<#x1<<" = "<<x1<<" "<<#x2<<" = "<<x2<<" "<<#x3<<" = "<<x3<<endl
#define max3(a,b,c) max(a,max(b,c))
#define min3(a,b,c) min(a,min(b,c))
#define lc (rt<<1)
#define rc (rt<<11)
#define mid ((l+r)>>1)

typedef pair<int,int> pll;
typedef long long ll;
const int inf = 0x3f3f3f3f;
const int _inf = 0xc0c0c0c0;
const ll INF = 0x3f3f3f3f3f3f3f3f;
const ll _INF = 0xc0c0c0c0c0c0c0c0;
const ll mod =  (int)1e9+7;

ll gcd(ll a,ll b){return b?gcd(b,a%b):a;}
ll ksm(ll a,ll b,ll mod){int ans=1;while(b){if(b&1) ans=(ans*a)%mod;a=(a*a)%mod;b>>=1;}return ans;}
ll inv2(ll a,ll mod){return ksm(a,mod-2,mod);}
void exgcd(ll a,ll b,ll &x,ll &y,ll &d){if(!b) {d = a;x = 1;y=0;}else{exgcd(b,a%b,y,x,d);y-=x*(a/b);}}//printf("%lld*a + %lld*b = %lld\n", x, y, d);
int mp[25][25];
int dp[1<<22];
int main()
{
    //ios::sync_with_stdio(false);
    //freopen("a.txt","r",stdin);
    //freopen("b.txt","w",stdout);
    int n;
    scanf("%d",&n);
    for(int i = 0;i<n;++i)
        for(int j = 0;j<n;++j)
            scanf("%d",&mp[i][j]);
    dp[0] = 1;
    for(int i = 1;i<(1<<n);++i)
    {
        int now = __builtin_popcount(i) - 1;
        for(int j = 0;j<n;++j)
        {
            if(i&(1<<j)&&mp[now][j])
            {
                dp[i] = (dp[i] + dp[i^(1<<j)])%mod;
            }
        }
    }
    printf("%d\n",dp[(1<<n)-1]);
    //fclose(stdin);
    //fclose(stdout);
    //cout << "time: " << (long long)clock() * 1000 / CLOCKS_PER_SEC << " ms" << endl;
    return 0;
}
/*
online resource
版权声明：本文为CSDN博主「ljq&&lxw」的原创文章，遵循 CC 4.0 BY-SA 版权协议，转载请附上原文出处链接及本声明。
原文链接：https://blog.csdn.net/heucodesong/article/details/89706975
*/
