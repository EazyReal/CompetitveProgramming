#include<bits/stdc++.h>
using namespace std;
class st{
    public:long long f,s;
    bool operator<(st o){
        if(o.f==f)return s<o.s;
        return f<o.f;
    }
}in[200005];
long long cur,pas,n;
multiset<long long>ani;
main(){
    ios::sync_with_stdio(0);
    cin.tie(0);cout.tie(0);
    cin>>n;
    for(long long i=1;i<=n;i++)cin>>in[i].f;
    for(long long i=1;i<=n;i++)cin>>in[i].s;
    sort(in+1,in+n+1);
    for(long long i=1;i<=n;i++){
        cur=max(cur+1,in[i].f);
        ani.insert(cur);
    }
    for(long long i=1;i<=n;i++){
        long long tmp=in[i].f;
        in[i].f=in[i].s;
        in[i].s=tmp;
    }
    sort(in+1,in+n+1);
    for(long long i=n;i>=1;i--){
        auto IT=ani.lower_bound(in[i].s);
        pas+=(*IT-in[i].s)*in[i].f;
        ani.erase(IT);
    }
    cout<<pas<<endl;
}
