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
Notes:
*> Super ez problem if you have idea bout tree dp, just keep in mind that the sum here could be pretty large{even inf = 1e18, didnt work}
*/

void solve() {
	int n;
	cin >> n;
	vector<vector<int>> g(n);
	for (int i = 0, a, b; i < n - 1; i++) {
		cin >> a >> b;
		a--, b--;
		g[a].push_back(b);
		g[b].push_back(a);
	}


	vector<int> c(n);
	for (auto &x : c) {
		cin >> x;
	}

	vector<int> sm, dp(n, 0);
	sm = c;
	function<void(int, int)> dfs = [&](int node, int p) {
		for (auto ch : g[node]) {
			if (ch ^ p) {
				dfs(ch, node);
				dp[node] += dp[ch] + sm[ch];
				sm[node] += sm[ch];
			}
		}
	};

	dfs(0, -1);
	int ans = -1;
	function<void(int, int)> dfs_reroot = [&](int node, int p) {
		ans = (ans == -1 ? dp[node] : min(ans, dp[node]));
		for (auto ch : g[node]) {
			if (ch ^ p) {
				dp[node] -= dp[ch] + sm[ch];
				sm[node] -= sm[ch];

				dp[ch] += dp[node] + sm[node];
				sm[ch] += sm[node];

				dfs_reroot(ch, node);

				sm[ch] -= sm[node];
				dp[ch] -= dp[node] + sm[node];


				sm[node] += sm[ch];
				dp[node] += dp[ch] + sm[ch];
			}
		}
	};

	dfs_reroot(0, -1);

	cout << ans << '\n';
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

