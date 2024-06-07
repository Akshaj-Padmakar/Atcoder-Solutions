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
*> Pretty intresting variation of dfs on grid problem.

*> dp[i][j][charID] -> stores if I can reach the cell i,j with a[i][j] = sn[charID] -> 0/1
*> reset is just dfs with direction vector etc.

*/

void solve() {
	int n, m;
	cin >> n >> m;

	vector<vector<char>> v(n, vector<char>(m));
	for (auto &x : v) {
		for (auto &y : x) {
			cin >> y;
		}
	}
	//snuke
	//01234
	vector<vector<vector<int>>> dp(n, vector<vector<int>>(m, vector<int>(5, -1)));
	//

	string sn = "snuke";

	vector<pair<int, int>> dir = {{0, 1}, {0, -1}, { -1, 0}, {1, 0}};
	auto check = [&](int x, int y) {
		return x >= 0 && x < n && y >= 0 && y < m;
	};

	function<int(int, int, int)> dfs = [&](int x, int y, int charV) {
		if (dp[x][y][charV] != -1) {
			return dp[x][y][charV];
		}
		if (x == n - 1 && y == m - 1) {
			return dp[x][y][charV] = 1ll;
		}
		dp[x][y][charV] = 0;
		for (auto [dx, dy] : dir) {
			if (check(dx + x, dy + y)) {
				if (v[dx + x][dy + y] == sn[(charV + 1) % 5]) {
					dp[x][y][charV] = max(dp[x][y][charV], dfs(dx + x, dy + y, (charV + 1) % 5));
				}
			}
		}

		return dp[x][y][charV];
	};

	dfs(0, 0, 0);

	cout << (dp[0][0][0] ? "Yes\n" : "No\n");

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

