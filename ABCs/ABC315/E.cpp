#include <bits/stdc++.h>
using namespace std;

#ifndef ONLINE_JUDGE
#include "algo/debug.h"
#define debug(x...) cerr << "[" << #x << "] = ["; _print(x)
#else
#define debug(x...)
#endif

#define int long long
// Simple problem on top sort, and dfs.
const int INF = 1e6;
void solve() {
	int n;
	cin >> n;

	vector<vector<int>> g(n), rg(n);
	vector<int> out(n, 0);
	queue<int> q;
	for (int i = 0, sz; i < n; i++) {
		cin >> sz;
		for (int j = 0, x; j < sz; j++) {
			cin >> x; x--;
			g[i].push_back(x);
			rg[x].push_back(i);
			out[i]++;
		}
		if (sz == 0) {
			q.push(i);
		}
	}

	vector<int> tp;
	while (q.size()) {
		int x = q.front();
		q.pop();
		tp.push_back(x);
		for (auto ch : rg[x]) {
			out[ch]--;
			if (out[ch] == 0) {
				q.push(ch);
			}
		}
	}
	vector<int> vis(n, 0), ans;
	function<void(int)> dfs = [&](int node) {
		ans.push_back(node);
		vis[node] = 1;
		for (auto ch : g[node]) {
			if (!vis[ch]) {
				dfs(ch);
			}
		}
	};
	debug(tp);
	reverse(tp.begin(), tp.end());
	vector<int> dp(n, -INF);
	for (int i = tp.size() - 1; i >= 0; i--) {
		int x = tp[i];
		if (g[x].size() == 0) {
			dp[x] = 0;
		}
		for (auto ch : g[x]) {
			dp[x] = max(dp[x], dp[ch] + 1);
		}
	}

	dfs(0);

	reverse(ans.begin(), ans.end());
	ans.pop_back();

	vector<pair<int, int>> fans;

	for (auto x : ans) {
		fans.push_back({dp[x], x});
	}
	sort(fans.begin(), fans.end());

	for (auto [x, y] : fans) {
		cout << y + 1 << " ";
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

