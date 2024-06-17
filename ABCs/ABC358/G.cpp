#include <bits/stdc++.h>
using namespace std;

#ifndef ONLINE_JUDGE
#include "algo/debug.h"
#define debug(x...) cerr << "[" << #x << "] = ["; _print(x)
#else
#define debug(x...)
#endif

#define int long long

const int INF = 1e15;
void solve() {
	int n, m, k;
	cin >> n >> m >> k;

	int sx, sy;
	cin >> sx >> sy;
	sx--, sy--;
	vector<vector<int>> a(n, vector<int>(m));

	for (auto &x : a) {
		for (auto &y : x) {
			cin >> y;
		}
	}
	auto check = [&](int x, int y) {
		return x >= 0 && x < n && y >= 0 && y < m;
	};

	int mov = 1e4 + 1;
	vector<vector<vector<int>>> dp(n, vector<vector<int>>(m, vector<int>(mov, -INF)));

	//dp[i][j][x] -> reach i,j in x moves and store the max value possible to reach there.

	vector<pair<int, int>> dir = {{ -1, 0}, {0, -1}, {1, 0}, {0, 1}};
	dp[sx][sy][0] = 0;

	for (int mm = 1; mm < mov; mm++) {
		for (int i = 0; i < n; i++) {
			for (int j = 0; j < m; j++) {
				//i,j,mm -> i-dx,j-dx, mm-1

				for (auto [dx, dy] : dir) {
					int ii = i + dx;
					int jj = j + dy;

					if (check(ii, jj)) {
						dp[i][j][mm] = max(dp[i][j][mm], dp[ii][jj][mm - 1] + a[i][j]);
					}
				}
			}
		}
	}
	int ans = 0;
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			for (int mm = 0; mm < mov; mm++) {
				if (k >= mm) {
					ans = max(ans, dp[i][j][mm] + (k - mm) * a[i][j]);
				}
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

