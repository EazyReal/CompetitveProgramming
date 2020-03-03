//https://atcoder.jp/contests/dp/submissions/3951000
//from hank55663
//well written segment_tree, logic is same as pW2
//better style for compression

#pragma GCC optimize("Ofast")
#include<bits/stdc++.h>
//#include<bits/extc++.h>
using namespace std;
//using namespace __gnu_pbds;
//typedef tree<int,null_type,less<int>,rb_tree_tag,tree_order_statistics_node_update> set_t;
#define mp(a,b) make_pair((a),(b))
#define pii pair<int,int>
#define pll pair<LL,LL>
#define pdd pair<double,double>
#define pb push_back
#define x first
#define y second
#define sqr(x) ((x)*(x))
#define EPS 1e-6
#define MEM(x) memset(x,0,sizeof(x))
#define MEMS(x) memset(x,-1,sizeof(x))
#define pi acos(-1)
#define index Index
#define Line pll
typedef long long LL;
vector<pair<int,pii> > p;
struct node{
    node *l,*r;
    LL tag;
    LL Max;
    int a,b;
    node(int _a,int _b):l(NULL),r(NULL){
        a=_a;
        b=_b;
        Max=tag=0;
    }
}*root;
void build(node *n){
    if(n->a==n->b){
        return ;
    }
    int mid=(n->a+n->b)/2;
    n->l=new node(n->a,mid);
    n->r=new node(mid+1,n->b);
    build(n->l);
    build(n->r);
}
void push(node *n){
    n->l->tag+=n->tag;
    n->r->tag+=n->tag;
    n->tag=0;
}
LL Max(node *n){
    return n->Max+n->tag;
}
void pull(node *n){
    n->Max=max(Max(n->l),Max(n->r));
}
void add(node *n,int l,int r,LL k){
    if(n->a>=l&&n->b<=r){
        n->tag+=k;
        return;
    }
    if(n->b<l||n->a>r){
        return ;
    }
    push(n);
    add(n->l,l,r,k);
    add(n->r,l,r,k);
    pull(n);
}
LL query(node *n,int x){
    if(n->b<=x){
        return Max(n);
    }
    int mid=(n->a+n->b)/2;
    if(x<=mid)
    return query(n->l,x);
    else
    return max(query(n->l,x),query(n->r,x));
}
int main(){
    int n,m;
    scanf("%d %d",&n,&m);
    for(int i=0;i<m;i++){
        int l,r,a;
        scanf("%d %d %d",&l,&r,&a);
        p.pb(mp(l,mp(l-1,a)));
        p.pb(mp(r+1,mp(l-1,-a)));
    }
    sort(p.begin(),p.end());
    int index=0;
    root = new node(0,n);
    build(root);
    LL ans=0;
    for(int i=1;i<=n;i++){
        while(index!=p.size()&&p[index].x==i){
            add(root,0,p[index].y.x,p[index].y.y);
          //  printf("l:%d %d %d\n",0,p[index].y.x,p[index].y.y);
            index++;
        }
        ans=max(query(root,i-1),ans);
       // printf("%d %d\n",i,Max(root));
        add(root,i,i,query(root,i-1));
       // printf("l:%d %d %d\n",i,i,Max(root));
    }
    printf("%lld\n",ans);
}
