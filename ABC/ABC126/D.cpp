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
*> claim : dis[node] % 2 == 0/1, all the nodes of same remainder should be painted with the same color.

*> Proof : We want same color nodes to have a even distance between them. say x and y have same color.
           dis(x,y) = dis[x] + dis[y] - 2* dis[lca(x,y)]
           consider %2 of the above eq.

           dis(x,y) mod 2 = (dis[x] mod 2 + dis[y] mod 2) mod 2

           since dis(x,y) mod 2 == 0

           -> dis[x] mod 2 == dis[y] mod 2
*/

void solve() {
	int n;
	cin >> n;
	vector<vector<pair<int, int>>> g(n);

	for (int i = 0, a, b, w; i < n - 1; i++) {
		cin >> a >> b >> w;
		a--, b--;

		g[a].push_back({b, w});
		g[b].push_back({a, w});
	}

	vector<int> dis(n, 0);
	function<void(int, int, int)> dfs = [&](int node, int par, int d) {
		dis[node] = d;

		for (auto [ch, w] : g[node]) {
			if (ch ^ par) {
				dfs(ch, node, d + w);
			}
		}
	};


	dfs(0, -1, 0);

	for (int i = 0; i < n; i++) {
		if (dis[i] % 2 == 0) {
			cout << 0 << "\n";
		} else {
			cout << 1 << "\n";
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

