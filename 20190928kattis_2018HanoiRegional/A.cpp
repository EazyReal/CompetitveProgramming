#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>
using namespace std;
typedef pair<long long, long long> pll;
const long long INF = 1LL << 60;
struct CostFlow {
    static const int MAXN = 100005;
    int maxn;
     struct Edge {
        int to, r;
        long long rest, c;
    };
    int n, pre[MAXN], preL[MAXN]; bool inq[MAXN];
    long long dis[MAXN], fl, cost;
    vector<Edge> G[MAXN];
    void init() {
        for (int i = 0; i < maxn; i++) G[i].clear();
    }
    void add_edge(int u, int v, long long rest, long long c) {
        G[u].push_back({v, (int)G[v].size(), rest, c});
        G[v].push_back({u, (int)G[u].size() - 1, 0, -c});
    }
    pll flow(int s, int t) {
        fl = cost = 0;
        while (true) {
            fill(dis, dis+maxn, INF);
            fill(inq, inq+maxn, 0);
            //fill(pre, pre+maxn, -1);
            dis[s] = 0;
            queue<int> que;
            que.push(s);
            while (not que.empty()) {
                int u = que.front(); que.pop();
                inq[u] = 0;
                for (int i = 0; i < (int)G[u].size(); i++) {
                    int v = G[u][i].to;
                    long long w = G[u][i].c;
                    if (G[u][i].rest > 0 and dis[v] > dis[u] + w) {
                        pre[v] = u; preL[v] = i;
                        dis[v] = dis[u] + w;
                        if (not inq[v]) {
                            inq[v] = 1;
                            que.push(v);
                        }
                    }
                }
            }
            if (dis[t] == INF) break;
            long long tf = INF;
            for (int v = t, u, l; v != s; v = u) {
                u = pre[v]; l = preL[v];
                tf = min(tf, G[u][l].rest);
            }
            for (int v = t, u, l; v != s; v = u) {
                u = pre[v]; l = preL[v];
                G[u][l].rest -= tf;
                G[v][G[u][l].r].rest += tf;
            }
            cost += tf * dis[t];
            fl += tf;
        }
        return {fl, cost};
    }
} flow;
int N, M;
inline int index(int i, int j) {
    return i * M + j;
}
int main() {
    while (cin >> N >> M and N and M) {
        int rB, cB; cin >> rB >> cB; rB--, cB--;
        int rC, cC; cin >> rC >> cC; rC--, cC--;
        int rG, cG; cin >> rG >> cG; rG--, cG--;
        int rU, cU; cin >> rU >> cU; rU--, cU--;
        flow.maxn = 2 * N * M + 2;
        flow.init();
        for (int i = 0; i < N; i++) {
            for (int j = 0; j < M; j++) {
								if (index(i, j) == index(rU, cU)) continue;
                flow.add_edge(index(i, j), index(i, j) + N * M, 1, 0);
                if (i > 0) flow.add_edge(index(i - 1, j) + N * M, index(i, j), 1, 1);
                if (i < N - 1) flow.add_edge(index(i + 1, j) + N * M, index(i, j), 1, 1);
                if (j > 0) flow.add_edge(index(i, j - 1) + N * M, index(i, j), 1, 1);
                if (j < M - 1) flow.add_edge(index(i, j + 1) + N * M, index(i, j), 1, 1);
            }
        }
        flow.add_edge(2 * N * M, index(rC, cC) + N * M, 2, 0);
        flow.add_edge(index(rB, cB) + N * M, 2 * N * M + 1, 1, 0);
        flow.add_edge(index(rG, cG) + N * M, 2 * N * M + 1, 1, 0);
				int maxflow = flow.flow(2 * N * M, 2 * N * M + 1).first;
        if (maxflow != 2) {
            cout << "NO" << endl;
        } else {
						auto& G = flow.G;
            vector<int> BCpath, CGpath;
						for (int i = 0; i < G[index(rC, cC) + N * M].size(); i++) {
							if (G[index(rC, cC) + N * M][i].rest == 0) {
								int v = G[index(rC, cC) + N * M][i].to;
								if (v == index(rC, cC)) continue;
								while (v != index(rB, cB) and v != index(rG, cG)) {
									for (int i = 0; i < G[v + N * M].size(); i++) {
										if (G[v + N * M][i].rest == 0) {
											v = G[v + N * M][i].to;
											break;
										}
									}
								}
								if (v == index(rB, cB)) {
									v = index(rC, cC);
									BCpath.push_back(v);
									v = G[v + N * M][i].to;
									BCpath.push_back(v);
									while (v != index(rB, cB)) {
										for (int i = 0; i < G[v + N * M].size(); i++) {
											if (G[v + N * M][i].rest == 0) {
												v = G[v + N * M][i].to;
												break;
											}
										}
										BCpath.push_back(v);
									}
								} else {
									v = index(rC, cC);
									CGpath.push_back(v);
									v = G[v + N * M][i].to;
									CGpath.push_back(v);
									while (v != index(rG, cG)) {
										for (int i = 0; i < G[v + N * M].size(); i++) {
											if (G[v + N * M][i].rest == 0) {
												v = G[v + N * M][i].to;
												break;
											}
										}
										CGpath.push_back(v);
									}
								}
							}
						}
            reverse(BCpath.begin(), BCpath.end());
						cout << "YES" << endl;
//            for (auto v : BCpath) cout << v << " "; cout << endl;
//						for (auto v : CGpath) cout << v << " "; cout << endl;
						for (int i = 1; i < BCpath.size(); i++) {
                int pre = BCpath[i - 1], now = BCpath[i];
                if (pre / M + 1 == now / M) cout << "U";
                if (pre / M - 1 == now / M) cout << "D";
                if (pre % M + 1 == now % M) cout << "R";
                if (pre % M - 1 == now % M) cout << "L";
            }
            for (int i = 1; i < CGpath.size(); i++) {
                int pre = CGpath[i - 1], now = CGpath[i];
                if (pre / M + 1 == now / M) cout << "U";
                if (pre / M - 1 == now / M) cout << "D";
                if (pre % M + 1 == now % M) cout << "R";
                if (pre % M - 1 == now % M) cout << "L";
            }cout << endl;
        }
    }
}
