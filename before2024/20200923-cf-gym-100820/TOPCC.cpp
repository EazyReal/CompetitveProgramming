#include <bits/stdc++.h>
using namespace std;

#define rep(i, _s, _t) for(int i = (_s); i < (_t); ++i)
#define X first
#define Y second
#define pb push_back
#define mp make_pair
using pii = pair<int, int>;
using pdd = pair<double, double>;
using ll = long long;
#define int ll
//#define dat pair<double, pair<int, int>>
const int maxn = 2000+100;
int n;
int close[maxn];
bool is_free[maxn];
double dis[maxn];
pdd xy[maxn];

double PI = acos(-1);
double d2(int aa, int bb)
{
    pdd a = xy[aa];
    pdd b = xy[bb];
    return sqrt((a.X-b.X)*(a.X-b.X)+(a.Y-b.Y)*(a.Y-b.Y));
}
//template <class T>
struct cmp {
    bool operator()(int a, int b) {
        return dis[a] < dis[b];
    }
};
void fix(int id, double d, set<int, cmp> &s)
{
    bool changed = false;
    rep(i, 0, n)
    {
        d = d2(i, id) - d;
        if(d < dis[i])
        {
            dis[i] = d;
            close[i] = id;
            changed = true;
        }
    }
    if(changed) {s.erase(id); s.insert(id);}
}
signed main() {
    ios::sync_with_stdio(0), cin.tie(0);
    cout << fixed << setprecision(10);
    cin >> n;
    rep(i, 0, n)
    {
        cin >> xy[i].X >> xy[i].Y;
    }
    // data = min-dis, min-dister, id
    set<int, cmp> s;
    // init dis
    rep(i, 0, n)
    {
        double minv = 1e20, minid=-1;
        rep(j, 0, n)if(i!=j)
        {
            if(d2(i, j) < minv)
            {
                minid = j;
                minv = d2(i,j);
            }
        }
        close[i] = minid;
        dis[i] = minv/2.0; //since is half
        is_free[i] = true;
        s.insert(i);
        //cerr << i << endl;
    }
    cerr << n << " " <<  s.size() << endl;
    //
    int free = n;
    double ans = 0.0;
    while(s.size() != 0)
    {
        int tp = *s.begin();
        cerr << tp << endl;
        int a = tp;
        int b = close[tp];
        int d = dis[tp];
        //assert(is_free[a]);
        if(is_free[a]) //sould always true
        {
            fix(a, d, s);
            ans += PI*dis[a]*dis[a];
            is_free[a] = false;
            s.erase(a);
            free--;
        }
        if(is_free[b])
        {
            fix(b, d, s);
            ans += PI*dis[a]*dis[a];;
            is_free[b] = false;
            s.erase(b);
            free--;
        }
    }
    cout << ans << endl;
}
