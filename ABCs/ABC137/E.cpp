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
*> Kinda hard, but not really.
*> making each edge weight c-p is obv. from c.
*> Now maxise over this G, is just minimise over -G
*> minimise ? SPA works.
*> -ve edges and cycles are here, so only bellman ford works.
*> Reach a node from 1 and n(on rG), and if this node dis reduces even after n-1 rounds -> this is part of a -ve cycle.
*> o.w just output -dis[n], but this shouldn't be -ve !
*/
const int INF = 1e12;
void solve() {
	int n, m, p;
	cin >> n >> m >> p;

	vector<vector<pair<int, int>>> g(n), rg(n);
	vector<pair<pair<int, int>, int>> e;
	for (int i = 0, a, b, c; i < m; i++) {
		cin >> a >> b >> c;
		a--, b--;
		g[a].push_back({b, p - c});
		rg[b].push_back({a, p - c});
		e.push_back({{a, b}, p - c});
	}
	vector<int> vis(n, false), vis2(n, false);
	function<void(int)> dfs = [&](int node) {
		vis[node] = 1;
		for (auto [ch, w] : g[node]) {
			if (!vis[ch]) {
				dfs(ch);
			}
		}
	};

	function<void(int)> rdfs = [&](int node) {
		vis2[node] = 1;
		for (auto [ch, w] : rg[node]) {
			if (!vis2[ch]) {
				rdfs(ch);
			}
		}
	};

	dfs(0);
	rdfs(n - 1);
	set<int> s;
	for (int i = 0; i < n; i++) {
		if (vis[i] && vis2[i]) {
			s.insert(i);
		}
	}
	debug(s);

	vector<int> dp(n, INF);
	dp[0] = 0;
	for (int i = 1; i <= n - 1; i++) {
		// n-1 rounds.
		for (auto [x, w] : e) {
			auto [a, b] = x;
			dp[b] = min(dp[b], dp[a] + w);
		}

		if (i == n - 1) {
			for (auto [x, w] : e) {
				auto [a, b] = x;
				if ((dp[b] > dp[a] + w) && s.find(b) != s.end()) {
					cout << -1 << '\n'; return;
				}
			}
		}
	}

	cout << max(0ll, -dp.back()) << '\n';

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
