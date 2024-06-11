#include <bits/stdc++.h>
using namespace std;

#ifndef ONLINE_JUDGE
#include "algo/debug.h"
#define debug(x...) cerr << "[" << #x << "] = ["; _print(x)
#else
#define debug(x...)
#endif

#define int long long
// A very ez intuitive Bitmask dp.
const int INF = 1e15;
void solve() {
	int n;
	cin >> n;

	vector<vector<int>> a(n, vector<int>(n));

	for (int i = 0; i < n; i++) {
		for (int j = 0, x; j <= n - i - 2; j++) {
			cin >> x;
			a[i][i + j + 1] = x;
			a[i + j + 1][i] = x;
		}
	}

	vector<int> dp(1ll << n, -INF);

	//dp[msk] -> max pssible value over this set.

	dp[0] = 0;

	for (int msk = 1; msk < 1ll << n; msk++) {
		for (int j = 0; j < n; j++) {
			if (msk & (1ll << j)) {
				for (int k = 0; k < n; k++) {
					if (msk & ( 1ll << k)) {
						if (j != k) {
							dp[msk] = max(dp[msk], dp[msk ^ (1ll << j) ^ (1ll << k)] + a[j][k]);
						}
					}
				}
			}
		}
	}


	cout << *max_element(dp.begin(), dp.end()) << "\n";
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

