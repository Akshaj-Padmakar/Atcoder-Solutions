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
*> DAG => Topsort => all the directed edges go from left to right,
                     if all the nodes(in a certain permutation) are ordered.

*> then writing a dp over this is pretty easy.

*> Similar for weighted-DAG.
*/
void solve() {
	int n, m;
	cin >> n >> m;
	vector<vector<int>> g(n), rg(n);
	vector<int> in(n, 0);

	for (int i = 0, a, b; i < m; i++) {
		cin >> a >> b;
		a--, b--;
		g[a].push_back(b);
		rg[b].push_back(a);

		in[b]++;
	}

	vector<int> tp;

	queue<int> q;

	for (int i = 0; i < n; i++) {
		if (!in[i]) {
			q.push(i);
		}
	}

	while (q.size()) {
		int node = q.front();
		tp.push_back(node);

		q.pop();

		for (auto ch : g[node]) {
			in[ch]--;
			if (!in[ch]) {
				q.push(ch);
			}
		}
	}

	vector<int> dp(n, 0);
	for (int i = 0; i < n; i++) {
		for (auto ch : rg[tp[i]]) {
			dp[tp[i]] = max(dp[tp[i]], dp[ch] + 1);
		}
	}

	cout << *max_element(dp.begin(), dp.end()) << "\n";
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

