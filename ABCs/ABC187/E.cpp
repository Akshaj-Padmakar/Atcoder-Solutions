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
*> Notes : Pretty ez problem ngl, try doing without segtree.
*/
void solve() {
	int n;
	cin >> n;
	vector<vector<int>>  g(n);
	vector <pair<int, int>> e;
	for (int i = 0, a, b; i < n - 1; i++) {
		cin >> a >> b;
		a--, b--;
		g[a].push_back(b);
		g[b].push_back(a);
		e.push_back({a, b});
	}
	int tm = 0;
	vector<int> in(n, 0), out(n, 0), ord, par(n, 0);
	function<void(int, int)> dfs = [&](int node, int p) {
		par[node] = p;
		in[node] = tm++;
		ord.push_back(0);
		for (auto ch : g[node]) {
			if (ch ^ p) {
				dfs(ch, node);
			}
		}
		out[node] = tm++;
		ord.push_back(0);
	};
	dfs(0, -1);
	ord.push_back(0);
	int q;
	cin >> q;

	while (q--) {
		int op, i, x;
		cin >> op >> i >> x;
		i--;
		auto [a, b] = e[i];
		if (op == 1) {
			if (par[a] == b) {
				ord[in[a]] += x;
				ord[out[a] + 1] -= x;
			} else {
				ord[0] += x;
				ord[in[b]] -= x;
				ord[out[b] + 1] += x;
			}
		} else {
			if (par[b] == a) {
				ord[in[b]] += x;
				ord[out[b] + 1] -= x;
			} else {
				ord[0] += x;
				ord[in[a]] -= x;
				ord[out[a] + 1] += x;
			}
		}
	}

	for (int i = 1; i < ord.size(); i++) {
		ord[i] += ord[i - 1];
	}
	debug(ord);
	for (int i = 0; i < n; i++) {
		cout << ord[in[i]] << '\n';
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
