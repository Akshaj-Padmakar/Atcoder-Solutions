#include <bits/stdc++.h>
using namespace std;

#ifndef ONLINE_JUDGE
#include "algo/debug.h"
#define debug(x...) cerr << "[" << #x << "] = ["; _print(x)
#else
#define debug(x...)
#endif

#define int long long

const int LOGN = 22;
void solve() {
	int n, sm = 0;
	cin >> n;
	vector<int> a(n);
	for (auto &x : a) {
		cin >> x;
		sm += x;
	}

	vector<vector<int>> g(n);
	for (int i = 0, a, b; i < n - 1; i++) {
		cin >> a >> b;
		a--, b--;

		g[a].push_back(b);
		g[b].push_back(a);
	}


	vector<vector<int>> dp(n, vector<int>(LOGN, 0));
	//dp[i][j] -> count the number of nodes in the subtree of node i that {when rooted at some node} that will have there jth bit set, after 'dis' calculation.

	vector<int> sz(n, 1);
	function<void(int, int)> dfs = [&](int node, int p) {
		for (int j = 0; j < LOGN; j++) {
			dp[node][j] = ((a[node] >> j) & 1ll);
		}

		for (auto ch : g[node]) {
			if (ch ^ p) {

				dfs(ch, node);
				sz[node] += sz[ch];

				for (int j = 0; j < LOGN; j++) {
					if (a[node] & (1ll << j)) {
						dp[node][j] += sz[ch] - dp[ch][j];
					} else {
						dp[node][j] += dp[ch][j];
					}
				}
			}
		}
	};

	dfs(0, -1);

	vector<int> ans(n, 0);
	int fans = 0;
	function<void(int, int)> dfs_reroot = [&](int node, int p) {
		for (int j = 0; j < LOGN; j++) {
			ans[node] += (dp[node][j] - ((a[node] >> j) & 1ll)) * (1ll << j);
		}
		fans += ans[node];
		for (auto ch : g[node]) {
			if (ch ^ p) {
				for (int j = 0; j < LOGN; j++) {
					if (a[node] & (1ll << j)) {
						dp[node][j] -= sz[ch] - dp[ch][j];
					} else {
						dp[node][j] -= dp[ch][j];
					}
				}

				sz[node] -= sz[ch];



				sz[ch] += sz[node];


				for (int j = 0; j < LOGN; j++) {
					if (a[ch] & (1ll << j)) {
						dp[ch][j] += sz[node] - dp[node][j];
					} else {
						dp[ch][j] += dp[node][j];
					}
				}

				dfs_reroot(ch, node);

				for (int j = 0; j < LOGN; j++) {
					if (a[ch] & (1ll << j)) {
						dp[ch][j] -= sz[node] - dp[node][j];
					} else {
						dp[ch][j] -= dp[node][j];
					}
				}


				sz[ch] -= sz[node];

				sz[node] += sz[ch];

				for (int j = 0; j < LOGN; j++) {
					if (a[node] & (1ll << j)) {
						dp[node][j] += sz[ch] - dp[ch][j];
					} else {
						dp[node][j] += dp[ch][j];
					}
				}
			}
		}
	};

	dfs_reroot(0, -1);

	cout << fans / 2 + sm << '\n';

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

