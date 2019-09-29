#include <iostream>
#include <fstream>
#include <vector>
#include <algorithm>
using namespace std;
using LL = long long;
using pLL = pair<LL,LL>;
using vL = vector<LL>;
using vLL = vector<pLL>;
using vvL = vector<vL>;
int main() {
	ios_base::sync_with_stdio(false);
	fstream fin("dull.in");
	int T; fin >> T;
	while (T--) {
		LL N, M, K; fin >> N >> M >> K;
		vLL whites(K);
		vL xw, yw;
		for (auto& white : whites) {
			fin >> white.first >> white.second;
			xw.push_back(white.first);
			yw.push_back(white.second);
		}
		xw.push_back(0); yw.push_back(0);
		xw.push_back(N); yw.push_back(M);
		sort(xw.begin(), xw.end());
		sort(yw.begin(), yw.end());
		xw.erase(unique(xw.begin(), xw.end()), xw.end());
		yw.erase(unique(yw.begin(), yw.end()), yw.end());
/*		cout << "xw : ";
		for (int x : xw) cout << x << " "; cout << endl;
		cout << "yw : ";
		for (int y : yw) cout << y << " "; cout << endl;
*/		vvL sum(xw.size(), vL(yw.size(), 0));
		for (int i = 0; i < K; i++) {
			int x = lower_bound(xw.begin(), xw.end(), whites[i].first) - xw.begin();
			int y = lower_bound(yw.begin(), yw.end(), whites[i].second) - yw.begin();
			sum[x][y] = 1;
		}
/*		cout << "sum : " << endl;
		for (int i = 0; i < xw.size(); i++) {
			for (int j = 0; j < yw.size(); j++) {
				cout << sum[i][j] << " ";
			} cout << endl;
		}*/
		for (int i = 1; i < xw.size(); i++) {
			for (int j = 1; j < yw.size(); j++) {
				sum[i][j] = sum[i][j] + sum[i - 1][j] + sum[i][j - 1] - sum[i - 1][j - 1];
			}
		}
/*		cout << "sum : " << endl;
		for (int i = 0; i < xw.size(); i++) {
			for (int j = 0; j < yw.size(); j++) {
				cout << sum[i][j] << " ";
			} cout << endl;
		}*/
		LL total = 0;
		for (int i = 0; i <= xw.size() - 1; i++) {
			for (int j = 0; j <= yw.size() - 1; j++) {
				if (sum[i][j] & 1) {
					if (i == xw.size() - 1 and j == yw.size() - 1) total += 1;
					else if (i == xw.size() - 1) total += yw[j + 1] - yw[j];
					else if (j == yw.size() - 1) total += xw[i + 1] - xw[i];
					else total += (xw[i + 1] - xw[i]) * (yw[j + 1] - yw[j]);
				}
			}
		}
		cout << total << " " << N * M - total << endl;
	}
}
