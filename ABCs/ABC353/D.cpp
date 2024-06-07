#include <bits/stdc++.h>
using namespace std;

#ifndef ONLINE_JUDGE
#include "algo/debug.h"
#define debug(x...) cerr << "[" << #x << "] = ["; _print(x)
#else
#define debug(x...)
#endif

#define int long long
/*
Notes :

*>Key idea is that xy = x * (10^digits(y)) + y

*> y is just evaluated as sum, and there are not a lot of digits possible in y (~10),
   so not a lost of distinct values of x * (10^digits(y)) exist.

*/
const int MOD = 998244353;
const int mxN = 11;
void solve() {
	int n;
	cin >> n;
	vector<int> a(n);
	for (auto &x : a) {
		cin >> x;
	}
	vector<vector<int>> cnt(n, vector<int>(mxN));

	for (int i = 0; i < n; i++) {
		int sz = to_string(a[i]).size();
		cnt[i][sz]++;
	}

	auto ssm = cnt;

	for (int i = n - 2; i >= 0; i--) {
		for (int j = 0; j < mxN; j++) {
			ssm[i][j] += ssm[i + 1][j];
		}
	}
	int sm = a[n - 1], ans = 0;
	for (int i = n - 2; i >= 0; i--) {
		for (int j = 1; j < mxN; j++) {
			if (ssm[i + 1][j]) {
				int vl = a[i];
				for (int k = 1; k <= j; k++) {
					vl *= 10;
					vl %= MOD;
				}
				ans += vl * ssm[i + 1][j];
				ans %= MOD;
			}
		}
		ans += sm;
		ans %= MOD;
		sm += a[i];
		sm %= MOD;
	}

	cout << ans << "\n";
}

signed main() {
#ifndef ONLINE_JUDGE
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
#else
#endif
	ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);

	int t = 1;
	//cin >> t;

	while (t--) {
		solve();
	}

	// cerr << "Time elapsed: " << ((long double)clock() / CLOCKS_PER_SEC) << " s.\n";
}

