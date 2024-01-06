//By NCTU_Oimo, contest: NCTU PCCA [191002], problem: (C) On Number of Decompositions into Multipliers, Accepted

#include <iostream>
#include <vector>
#include <map>
#include <cmath>
#include <cassert>
using namespace std;
map<long long, long long> prime_count;
long long mod = 1e9+7;
long long inv[1000005];
long long H(long long m, long long n) {
	long long res = 1;
	for (long long i = n + m - 1; i >= m; i--) {
		res = res * i % mod;
	}
	res = res * inv[n] % mod;
	return res;
}
int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	inv[1] = 1;
	for (long long i = 2; i <= 1000000; i++) {
		inv[i] = (mod - (mod / i)) * inv[mod % i] % mod;
		assert(inv[i] * i % mod == 1);
	}
	for (long long i = 2; i <= 1000000; i++) inv[i] = inv[i - 1] * inv[i] % mod;
	long long n; cin >> n;
	vector<long long> a(n);
	for (long long i = 0; i < n; i++) cin >> a[i];
	for (long long i = 0; i < n; i++) {
		for (long long j = 2; j * j <= a[i]; j++) {
			if (a[i] % j == 0) {
				while (a[i] % j == 0) {
					a[i] /= j;
					prime_count[j]++;
				}
			}
		}
		if (a[i] != 1) prime_count[a[i]]++;
	}
	long long ans = 1;
	for (auto prime : prime_count) {
//		cout << prime.first << " " << prime.second << endl;
		ans = ans * H(n, prime.second) % mod;
	} cout << ans << endl;
}
