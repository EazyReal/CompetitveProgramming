namespace lca{
  int p[maxb][maxn];
	int dep[maxn];
  void dfs(int u, int f)
  {
    p[0][u] = f;
    dep[u] = dep[f] + 1;
    for(auto v : G[u]) if(v != f) dfs(v, u);
  }

  int lca(int a, int b)
  {
    if(dep[a] < dep[b]) swap(a, b);
    //assert(dep[a] >= dep[b]);
    repinv(i, 0, maxb) if(dep[p[i][a]] >= dep[b]) a = p[i][a]; //< -> >=...
    if(a == b) return a;
    repinv(i, 0, maxb)
    {
      if(p[i][a] != p[i][b]) a = p[i][a], b = p[i][b];
    }
    return p[0][a];
  }

  void build(int n)
  {
    dep[0] = -1;
    dfs(1, 0);
    p[0][1] = 1;
    rep(i, 1, maxb) rep(u, 1, n+1) p[i][u] = p[i-1][p[i-1][u]];
  }

  int dist(int a, int b)
  {
    return dep[a] + dep[b] - 2*dep[lca(a, b)];
  }
}
