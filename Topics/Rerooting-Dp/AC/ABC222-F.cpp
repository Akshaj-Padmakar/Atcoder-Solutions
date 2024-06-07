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
*> Interesting problem, but it could get very ugly.

*> Unique thing here is we can use multiset to keep dp, in min related recurrance relation, WOW !
*/
void solve() {
	int n;
	cin >> n;
	vector <vector<pair<int, int>>> g(n);
	map<pair<int, int>, int> ww;
	for (int i = 0, a, b, w; i + 1 < n; i++) {
		cin >> a >> b >> w;
		a--, b--;

		g[a].push_back({b, w});
		g[b].push_back({a, w});
	}
	vector<int> d(n);
	for (auto &x : d) {
		cin >> x;
	}

	vector<int>ans(n, 0);
	vector<multiset<int>> dp(n);
	function<void(int, int)> dfs = [&](int node, int p) {
		dp[node].insert(d[node]);
		for (auto [ch, w] : g[node]) {
			if (ch ^ p) {
				dfs(ch, node);
				dp[node].insert(*dp[ch].rbegin() + w);
			}
		}
	};
	dfs(0, -1);

	debug(dp);

	function<void(int, int)> dfs_reroot = [&](int node, int p) {
		dp[node].erase(dp[node].find(d[node]));
		ans[node] = *dp[node].rbegin();
		dp[node].insert(d[node]);

		for (auto [ch, w] : g[node]) {
			if (ch ^ p) {
				dp[node].erase(dp[node].find(*dp[ch].rbegin() + w));
				dp[ch].insert(*dp[node].rbegin() + w);

				dfs_reroot(ch, node);

				dp[ch].erase(dp[ch].find(*dp[node].rbegin() + w));
				dp[node].insert(*dp[ch].rbegin() + w);
			}
		}
	};

	dfs_reroot(0, -1);

	// debug(ans);

	for (auto x : ans) {
		cout << x << '\n';
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

