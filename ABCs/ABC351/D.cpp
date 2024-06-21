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
*> ez, simle implmentation.
*/
void solve() {
	int n, m;
	cin >> n >> m;
	vector<vector<char>> a(n, vector<char>(m));

	for (auto &x : a) {
		for (auto &y : x) {
			cin >> y;
		}
	}
	auto ne = a;

	vector<pair<int, int>> dir = {{1, 0}, { -1, 0}, {0, -1}, {0, 1}};
	auto check = [&](int x, int y) {
		return x >= 0 && x < n && y >= 0 && y < m;
	};
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			if (a[i][j] == '#') {
				for (auto [dx, dy] : dir) {
					int xx = i + dx, yy = j + dy;
					if (check(xx, yy)) {
						ne[xx][yy] = '#';
					}
				}
			}
		}
	}
	swap(ne, a);

	vector<vector<bool>> vis(n, vector<bool>(m, false));
	int cc = 0;
	vector<pair<int, int>> z;
	function<void(int, int)> dfs = [&](int x, int y) {
		vis[x][y] = true;
		cc++;
		for (auto [dx, dy] : dir) {
			int xx = x + dx, yy = y + dy;
			if (check(xx, yy) && vis[xx][yy] == 0) {
				if (a[xx][yy] != '#') {
					dfs(xx, yy);
				} else {
					if (a[xx][yy] != ne[xx][yy]) {
						cc++;
						vis[xx][yy] = 1;
						z.push_back({xx, yy});
					}
				}
			}
		}
	};
	int ans = 1;
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			if (a[i][j] != '#' && !vis[i][j]) {
				cc = 0;
				dfs(i, j);
				debug(cc, i, j);
				ans = max(ans, cc);
				for (auto [x, y] : z) {
					vis[x][y] = 0;
				}
				z.clear();
			}
		}
	}
	cout << ans << '\n';
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
