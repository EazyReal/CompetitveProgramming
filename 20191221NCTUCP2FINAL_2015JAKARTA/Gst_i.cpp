#include <iostream>
#include <vector>
#include <string>
#include <queue>
#include <algorithm>
using namespace std;
string map[101];
int dist[10005];
int par[10005];
int INF = 0x3f3f3f3f;
int N, M;
int idx(int row, int col) {
	return row * M + col;
}
int main() {
	int T; cin >> T;
	for (int t = 1; t <= T; t++) {
		cin >> N >> M;
		for (int i = 0; i < N; i++) cin >> map[i];
		int strt = -1;
		int lst = -1;
		for (int i = 0; i < N; i++) {
			for (int j = 0; j < M; j++) {
				if (map[i][j] == 'A') {
					strt = idx(i, j);
				} else if (map[i][j] == 'B') {
					lst = idx(i, j);
				}
			}
		}
		priority_queue<pair<int,int>, vector<pair<int,int>>, greater<pair<int,int>>> pq;
		for (int i = 0; i < N; i++) {
			for (int j = 0; j < M; j++) {
				dist[idx(i, j)] = INF;
				par[idx(i, j)] = -1;
			}
		}
		dist[strt] = 0;
		pq.emplace(0, strt);
		while (not pq.empty()) {
			auto f = pq.top(); pq.pop();
//			cout << "f.first = " << f.first << ", f.second = " << f.second << endl;
			if (f.first > dist[f.second]) continue;
			int i = f.second / M, j = f.second % M;
			if (f.second % M > 0 and map[i][j - 1] != '0') {
				if (dist[f.second - 1] > dist[f.second] + map[i][j - 1] - '0') {
					dist[f.second - 1] = dist[f.second] + map[i][j - 1] - '0';
					pq.emplace(dist[f.second - 1], f.second - 1);
					par[f.second - 1] = f.second;
				}
			}
			if (f.second % M < M - 1 and map[i][j + 1] != '0') {
				if (dist[f.second + 1] > dist[f.second] + map[i][j + 1] - '0') {
					dist[f.second + 1] = dist[f.second] + map[i][j + 1] - '0';
					pq.emplace(dist[f.second + 1], f.second + 1);
					par[f.second + 1] = f.second;
				}
			}
			if (f.second > M and map[i - 1][j] != '0') {
				if (dist[f.second - M] > dist[f.second] + map[i - 1][j] - '0') {
					dist[f.second - M] = dist[f.second] + map[i - 1][j] - '0';
					pq.emplace(dist[f.second - M], f.second - M);
					par[f.second - M] = f.second;
				}
			}
			if (f.second + M < N * M and map[i + 1][j] != '0') {
				if (dist[f.second + M] > dist[f.second] + map[i + 1][j] - '0') {
					dist[f.second + M] = dist[f.second] + map[i + 1][j] - '0';
					pq.emplace(dist[f.second + M], f.second + M);
					par[f.second + M] = f.second;
				}
			}
		}
//		for (int i = 0; i < N * M; i++) cout << "par[" << i << "] = " << par[i] << endl;
		int cost = 0;
		vector<int> path;
		int cur = lst;
		if (par[lst] == -1) {
			cout << "Case #" << t << ": 0" << endl;
			continue;
		}
		while (cur != -1) {
			path.push_back(cur);
			cur = par[cur];
		}
		for (int i = 0; i < N; i++) {
			for (int j = 0; j < M; j++) {
				if (map[i][j] == 'A') continue;
				else if (map[i][j] == 'B') continue;
				else cost += map[i][j] - '0';
			}
		}
		int mx = 0;
		for (int k = 1; k < path.size() - 1; k++) {
			int i = path[k] / M, j = path[k] % M;
			cost -= map[i][j] - '0';
			mx = max(mx, map[i][j] - '0');
		}
//		for (auto v : path) cout << v << " "; cout << endl;
		cost = cost + mx;
		cout << "Case #" << t << ": " << cost << endl;
	}
}
