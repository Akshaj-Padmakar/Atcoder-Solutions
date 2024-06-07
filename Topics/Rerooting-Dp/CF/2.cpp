#include <bits/stdc++.h>
using namespace std;

#ifndef ONLINE_JUDGE
#include "algo/debug.h"
#define debug(x...) cerr << "[" << #x << "] = ["; _print(x)
#else
#define debug(x...)
#endif

#define int long long


void solve() {
	int n;
	cin >> n;
	vector<int> a(n);
	for (auto &x : a) {
		cin >> x;
		if (!x) {
			x = -1;
		}
	}

	vector<vector<int>> g(n);

	for (int i = 0, a, b; i < n - 1; i++) {
		cin >> a >> b;
		a--, b--;
		g[a].push_back(b);
		g[b].push_back(a);
	}

	vector<int> dp(n), ans(n);
	function<void(int, int)> dfs = [&](int node, int p) {
		dp[node] = a[node];
		for (auto ch : g[node]) {
			if (ch ^ p) {
				dfs(ch, node);
				dp[node] += max(dp[ch], 0ll);
			}
		}
	};

	dfs(0, -1);

	function<void(int, int)> dfs_reroot = [&](int node, int p) {
		ans[node] = dp[node];
		for (auto ch : g[node]) {
			if (ch ^ p) {
				dp[node] -= max(0ll, dp[ch]);
				dp[ch] += max(0ll, dp[node]);

				dfs_reroot(ch, node);

				dp[ch] -= max(0ll, dp[node]);
				dp[node] += max(0ll, dp[ch]);
			}
		}
	};

	dfs_reroot(0, -1);

	for (auto &x : ans) {
		cout << x << ' ';
	}
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

