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
	int n, q;
	cin >> n >> q;
	vector<vector<int>> g(n);
	for (int i = 0, a, b; i < n - 1; i++) {
		cin >> a >> b;
		a--, b--;
		g[a].push_back(b);
		g[b].push_back(a);
	}

	vector<int> tour, in(n, 0), out(n, 0);
	int timer = 0;
	function<void(int, int)> dfs = [&](int node, int p) {
		in[node] = timer++;
		tour.push_back(0);
		for (auto ch : g[node]) {
			if (ch ^ p) {
				dfs(ch, node);
			}
		}
		out[node] = timer++;
		tour.push_back(0);
	};

	dfs(0, -1);
	// tour.push_back(0);

	while (q--) {
		int node, x;
		cin >> node >> x;
		node--;

		tour[in[node]] += x;
		tour[out[node]] -= x;
	}

	for (int i = 1; i < tour.size(); i++) {
		tour[i] += tour[i - 1];
	}

	for (int i = 0; i < n; i++) {
		cout << tour[in[i]] << ' ';
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
