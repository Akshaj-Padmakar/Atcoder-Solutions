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
Notes: Basic Implmentation.
*/

void solve() {
	int n, m;
	cin >> n >> m;

	vector<vector<int>> g(m);

	for (int i = 0, k; i < m; i++) {
		cin >> k;
		for (int j = 0, x; j < k; j++) {
			cin >> x;
			x--;
			g[i].push_back(x);
		}
		// sort(g[i].begin(), g[i].end());
	}

	vector<int> p(m);
	for (auto &x : p) {
		cin >> x;
	}

	int ans = 0;
	for (int i = 0; i < 1ll << n; i++) {
		vector<int> on;
		for (int k = 0; k < n; k++) {
			if (i & (1ll << k)) {
				on.push_back(k);
			}
		}
		bool ok = 1;
		for (int j = 0; j < m; j++) {
			int c = 0;
			for (auto &x : g[j]) {
				if (binary_search(on.begin(), on.end(), x)) {
					c++;
				}
			}

			if (c % 2 != p[j]) {
				ok = false;
				break;
			}
		}
		ans += ok;
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

