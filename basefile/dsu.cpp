struct DSU {
    vector<int> p, sz;

    DSU(int n) : p(n), sz(n,1)
    {
        iota(p.begin(), p.end(), 0);
    }

    int findset(int u)
    {
        return p[u]==u ? u : p[u] = findset(p[u]);
    }

    bool unionset(int u, int v)
    {
        u = findset(u);
        v = findset(v);
        if(u == v) return false;
        if(sz[u] < sz[v]) swap(u, v);
        p[v] = u;
        sz[u] += sz[v];
        return true;
    }
}