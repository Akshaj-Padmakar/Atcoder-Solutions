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
	}

	vector<vector<int>> g(n);
	for (int i = 0, a, b; i < n - 1; i++) {
		cin >> a >> b;
		a--, b--;
		g[a].push_back(b);
		g[b].push_back(a);
	}

	vector<int> dp(n, 0), sm(n, 0), ans(n, 0);
	//dp[i] -> cost in the subtree of i, when rooted on some node v.

	function<void(int, int)> dfs = [&](int node, int p) {
		sm[node] = a[node];
		for (auto ch : g[node]) {
			if (ch ^ p) {
				dfs(ch, node);

				sm[node] += sm[ch];
				dp[node] += dp[ch] + sm[ch];
			}
		}
	};

	dfs(0, -1);

	function<void(int, int)> reroot_dp = [&](int node, int p) {
		//p -> previous node I came from
		ans[node] = dp[node];

		for (auto ch : g[node]) {
			if (ch ^ p) {
				dp[node] -= dp[ch] + sm[ch];
				sm[node] -= sm[ch];
				sm[ch] += sm[node];
				dp[ch] += dp[node] + sm[node];

				reroot_dp(ch, node);

				dp[ch] -= dp[node] + sm[node];
				sm[ch] -= sm[node];
				sm[node] += sm[ch];
				dp[node] += dp[ch] + sm[ch];
			}
		}
	};

	reroot_dp(0, -1);

	cout << *max_element(ans.begin(), ans.end()) << '\n';
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

