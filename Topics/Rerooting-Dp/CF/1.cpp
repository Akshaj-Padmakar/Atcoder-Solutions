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
	vector<vector<int>>  g(n);
	map<pair<int, int>, int> mp;
	for (int i = 0, a, b; i < n - 1; i++) {
		cin >> a >> b;
		a--, b--;
		g[a].push_back(b);
		g[b].push_back(a);
		// e.push_back({a, b}); //a->b

		mp[ {a, b}] = 0;
		mp[ {b, a}] = 1;
	}

	vector<int> dp(n, 0), ans(n);
	function<void(int, int)> dfs = [&](int node, int p) {
		for (auto ch : g[node]) {
			if (ch ^ p) {
				dfs(ch, node);
				// debug(node, ch, mp[ {node, ch}]);
				dp[node] += (dp[ch] + mp[ {node, ch}]);
			}
		}
	};

	dfs(0, -1);

	function<void(int, int)> dfs_reroot = [&](int node, int p) {
		ans[node] = dp[node];
		for (auto ch : g[node]) {
			if (ch ^ p) {
				dp[node] -= dp[ch] + mp[ {node, ch}];
				dp[ch] += dp[node] + mp[ {ch, node}];

				dfs_reroot(ch, node);


				dp[ch] -= dp[node] + mp[ {ch, node}];
				dp[node] += dp[ch] + mp[ {node, ch}];

			}
		}
	};
	dfs_reroot(0, -1);

	int fans = *min_element(ans.begin(), ans.end());

	cout << fans << '\n';
	for (int i = 0; i < n; i++) {
		if (fans == ans[i]) {
			cout << i + 1 << ' ';
		}
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

