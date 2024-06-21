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
*> x,y => x ---> i <---- y if y is closer, go to the deepest node in that subtree when rooted at y.
*/
void solve() {
	int n, x, y;
	cin >> n >> x >> y;
	x--, y--;

	vector<vector<int>> g(n);
	for (int i = 0, a, b; i + 1 < n; i++) {
		cin >> a >> b;
		a--, b--;
		g[a].push_back(b);
		g[b].push_back(a);
	}
	vector<vector<int>> dis(2, vector<int>(n, 0)), dp(2, vector<int>(n, 0));
	// dis[src][node] ->distance from src to node
	// dp[src][node] ->largest distacne from node to some node x in the subtree of node when src is the soruce.
	function<void(int, int, int, int)> dfs = [&](int node, int p, int d, int src) {
		dis[src][node] = d;

		for (auto ch : g[node]) {
			if (ch ^ p) {
				dfs(ch, node, d + 1, src);
				dp[src][node] = max(dp[src][node], dp[src][ch] + 1);
			}
		}
	};

	dfs(x, -1, 0, 0);
	dfs(y, -1, 0, 1);

	int ans = 0;
	for (int i = 0; i < n; i++) {
		int t = dis[0][i], a = dis[1][i];

		if (t < a) {
			ans = max(ans, a + dp[1][i]);
		}
	}

	cout << ans - 1 << '\n';

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
