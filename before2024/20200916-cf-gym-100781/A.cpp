#include <bits/stdc++.h>
using namespace std;
 
#define vt vector
#define sz(x) int((x).size())
#define all(x) (x).begin(), (x).end()
#define rall(x) (x).rbegin(), (x).rend()
#define fi first
#define se second
 
using ll = long long;
using pii = pair<int, int>;
 
void solve() {
    int n, m;
    cin >> n >> m;
    vt<vt<int>> adj(n);
    while (m--) {
        int u, v;
        cin >> u >> v;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }
 
    vt<bool> vis(n);
    vt<int> comp;
    auto find_far = [&](int s) -> pii {
        int max_len = 0, max_node = s;
        map<int, int> depth;
        depth[s] = 0;
        function<void(int, int)> dfs = [&](int u, int p) {
            vis[u] = true;
            if (depth[u] > max_len) {
                max_len = depth[u];
                max_node = u;
            }
 
            for (int v : adj[u]) if (v != p) {
                depth[v] = depth[u] + 1;
                dfs(v, u);
            }
        };
        dfs(s, s);
 
        return {max_len, max_node};
    };
    for (int i = 0; i < n; i++) {
        if (!vis[i]) {
            comp.push_back(
                find_far(find_far(i).se).fi
            );
        }
    }
    sort(rall(comp));
 
    int nc = sz(comp);
    if (nc == 1) return void(cout << comp[0]);
 
    int big = comp[0];
    for(int i = 1; i < nc; i ++)
    {
        int nxt = (big+1)/2 + (comp[i]+1)/2 + 1;
        big = max(big, nxt);
    }

    cout << big << endl;
}
 
int main() {
    ios::sync_with_stdio(0), cin.tie(0);
 
    int tcs = 1;
    for (int tc = 1; tc <= tcs; tc++) {
        solve();
    }
}