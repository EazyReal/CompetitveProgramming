
/*
By NCTU_Oimo, contest: 2018 Benelux Algorithm Programming Contest (BAPC 18), problem: (I) In Case of an Invasion, Please..., 
*/

#include <bits\stdc++.h>
using namespace std;
using LL = long long;
vector<vector<pair<int,LL>>> G;
const long long INF = 1LL<<60;
struct Dinic {  //O(VVE), with minimum cut
    static const int MAXN = 200005;
    struct Edge{
        int u, v;
        long long cap, rest;
    };

    int n, m, s, t, d[MAXN], cur[MAXN];
    vector<Edge> edges;
    vector<int> G[MAXN];

    void init(){
        edges.clear();
        for ( int i = 0 ; i < n ; i++ ) G[i].clear();
        n = 0;
    }


    int add_node(){
        return n++;
    }

    void add_edge(int u, int v, long long cap){
        edges.push_back( {u, v, cap, cap} );
        edges.push_back( {v, u, 0, 0LL} );
        m = edges.size();
        G[u].push_back(m-2);
        G[v].push_back(m-1);
    }

    bool bfs(){
        fill(d,d+n,-1);
        queue<int> que;
        que.push(s); d[s]=0;
        while (!que.empty()){
            int u = que.front(); que.pop();
            for (int ei : G[u]){
                Edge &e = edges[ei];
                if (d[e.v] < 0 && e.rest > 0){
                    d[e.v] = d[u] + 1;
                    que.push(e.v);
                }
            }
        }
        return d[t] >= 0;
    }

    long long dfs(int u, long long a){
        if ( u == t || a == 0 ) return a;
        long long flow = 0, f;
        for ( int &i=cur[u]; i < (int)G[u].size() ; i++ ) {
            Edge &e = edges[ G[u][i] ];
            if ( d[u] + 1 != d[e.v] ) continue;
            f = dfs(e.v, min(a, e.rest) );
            if ( f > 0 ) {
                e.rest -= f;
                edges[ G[u][i]^1 ].rest += f;
                flow += f;
                a -= f;
                if ( a == 0 )break;
            }
        }
        return flow;
    }

    long long maxflow(int _s, int _t){
        s = _s, t = _t;
        long long flow = 0, mf;
        while ( bfs() ){
            fill(cur,cur+n,0);
            while ( (mf = dfs(s, INF)) ) flow += mf;
        }
        return flow;
    }
} dinic;
int n, m, s;
LL total = 0;
vector<LL> p;
vector<vector<LL>> dist;
vector<pair<int,LL>> c;
bool check(LL mx_t) {
//    cout << "mx_t = " << mx_t << endl;
    dinic.init();
    // source
    dinic.add_node();
    // left side
    for (int i = 1; i <= n; i++) {
        dinic.add_edge(0, dinic.add_node(), p[i]);
    }
    // right side
    for (int i = 1; i <= s; i++) {
        dinic.add_edge(dinic.add_node(), n + s + 1, c[i].second);
    }
    // drain
    dinic.add_node();
    //cout<<dinic.n<<'\n';
    for (int i = 1; i <= s; i++) {
        for (int j = 1; j <= n; j++) {
//            cout << "dist[" << i << "][" << j << "] = " << dist[i][j] << endl;
            if (dist[i][j] <= mx_t) {
//                cout << "dinic.add_edge(" << j << ", " << n + i << ", INF);" << endl;
                dinic.add_edge(j, n + i, INF);
            }
        }
    }
    return dinic.maxflow(0, n + s + 1) == total;
}
int main() {
    ios_base::sync_with_stdio(false);
    cin >> n >> m >> s;
    p.resize(n+1);
    dist.resize(s + 1, vector<LL>(n + 1, INF));
    c.resize(s+1);
    G.resize(n+1,vector<pair<int,LL>>());
    total = 0;
    for (int i = 1; i <= n; i++) {
            cin >> p[i];
            total += p[i];
    }
    p[0]=0;

    for (int i = 0; i < m; i++) {
        int u, v; LL w; cin >> u >> v >> w;
        G[u].emplace_back(v, w);
        G[v].emplace_back(u, w);
    }
    for (int i = 1; i <= s; i++) cin >> c[i].first >> c[i].second;
    priority_queue<pair<LL,int>,vector<pair<LL,int>>,greater<pair<LL,int>>> pri;
    LL mt = 0;
    for (int i = 1; i <= s; i++) {
        pri.emplace(0, c[i].first);
        vector<bool> vis(n + 1, false);
        dist[i][c[i].first] = 0;
        while (not pri.empty()) {
            auto f = pri.top(); pri.pop();
            if (vis[f.second]) continue;
            vis[f.second] = true;
//            cout << "f.first = " << f.first << endl;
//            cout << "f.second = " << f.second << endl;
            for (auto& e : G[f.second]) {
                if (not vis[e.first]) {
                    if (dist[i][e.first]>dist[i][f.second]+e.second)
                    {
                        dist[i][e.first]=dist[i][f.second]+e.second;
                        pri.emplace(dist[i][e.first],e.first);
                    }
                }
            }
        }
        for (int j = 1; j <= n; j++) mt = max(mt, dist[i][j]);
    }
/*    for (int i = 1; i <= s; i++) {
        for (int j = 1; j <= n; j++) cout << "dist[" << i << "][" << j << "] = " << dist[i][j] << endl;
    }*/
    LL L = 0, R = mt+5;
    while (L != R) {
        LL M = (L + R) / 2LL;
        if (check(M)) R = M;
        else L = M + 1;
    }
    cout << L << endl;
}
