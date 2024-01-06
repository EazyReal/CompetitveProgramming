#include <iostream>
#include <vector>
#include <fstream>
using namespace std;

#define USESTD

#ifdef USESTD
#define fsin cin
#define fsout cout
#endif

const int MAXN = 200005;
std::vector<int> G[MAXN];
int n;
int lv[MAXN];
bool vis[MAXN];
int father[21][MAXN];

#ifndef USESTD
fstream fsin("dynamic.in",ios::in);
fstream fsout("dynamic.out",ios::out);
#endif

void dfs(int u) {
	for (int i = 0; i < G[u].size(); i++) {
    int v = G[u][i];
		if (not vis[v]) {
			vis[v] = true;
			lv[v] = lv[u] + 1;
			father[0][v] = u;
			dfs(v);
		}
	}
}

void makePP() {
	for (int i = 1; i < 21; i++) {
		for (int j = 2; j <= n; j++) {
			father[i][j] = father[i-1][father[i-1][j]];
		}
	}
}

int find(int a, int b) {
	if (lv[a] < lv[b]) swap(a, b);
	int need = lv[a] - lv[b];
	for (int i = 0; need != 0; i++) {
		if (need & 1) a = father[i][a];
		need >>= 1;
	}
	for (int i = 20; i >= 0; i--) {
		if (father[i][a] != father[i][b]) {
			a = father[i][a];
			b = father[i][b];
		}
	}
	return a != b ? father[0][a] : a;
}

int main() {
	while (fsin >> n and n) {
		for (int i = 1; i <= n - 1; i++) {
			int u, v; cin >> u >> v;
			G[u].push_back(v);
			G[v].push_back(u);
		}
		for (int i = 1; i <= n; i++) vis[i] = 0;
		for (int i = 1; i <= n; i++) {
			for (int j = 0; j < 21; j++) {
				father[i][j] = 0;
			}
		}
		father[0][1] = 1;
		vis[1] = true;
		lv[1] = 0;
		dfs(1);
		makePP();
		int m; fsin >> m;
		int r = 1;
		while (m--)
    {
			char op; fsin >> op;
			if (op == '?')
      {
        int u, v;
        fsin >> u >> v;
        int a, b, c, d;
        a = find(u, v);
        b = find(u, r);
        c = find(r, v);
        d = lv[c]>lv[b]? c:b;
        fsout << (lv[c]==lv[b]?a:d) << endl;
      } else if (op == '!')
      {
        fsin >> r;
      }
		}
	}
  return 0;

}
