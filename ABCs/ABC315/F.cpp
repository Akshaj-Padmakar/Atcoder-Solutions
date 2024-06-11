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
Very darn hard and a beautiful problem !!!
*/
const int MAXN = 32;
const int INF = 1e15;
void solve() {
	int n;
	cin >> n;

	vector<pair<int, int>> a(n);
	for (auto &[x, y] : a) {
		cin >> x >> y;
	}

	vector<vector<vector<long double>>> dp(n, vector<vector<long double>>(MAXN, vector<long double>(2, INF)));
	// dp[i][j] -> scanned the first i points and skipped exactly j out of thoese, min distance then ?

	dp[0][0][1] = 0;

	auto dis = [&](int i, int j) {
		return sqrtl((a[i].first - a[j].first) * (a[i].first - a[j].first) + (a[i].second - a[j].second) * (a[i].second - a[j].second));
	};

	for (int i = 1; i < n; i++) {
		for (int j = 0; j < MAXN; j++) {
			if (j > i) {
				break;
			}
			if (i == n - 1 && j == n - 1) {
				break;
			}

			if (i != n - 1 && j > 0) {
				int vl = (j >= 1 ? 1ll << (j - 1) : 0) - (j >= 2 ? 1ll << (j - 2) : 0);

				dp[i][j][0] = dp[i - 1][j - 1][1] + vl;
				dp[i][j][0] = dp[i - 1][j - 1][0] + vl;

			}
			// debug(i, j, dp[i][j]);

			for (int p = 1; p <= 30; p++) {
				int nw = i - p; // so we skipped p-1 points.
				if (nw < 0) {
					break;
				}
				if (j - (p - 1) < 0) {
					break;
				}
				int vl = ((j - 1 >= 0) ? (1ll << (j - 1)) : 0);
				vl -= (j - 1 - (p - 1) >= 0 ? 1ll << (j - 1 - (p - 1)) : 0);

				dp[i][j][1] = min(dp[i][j][1], dp[nw][j - (p - 1)][1] + dis(i, nw) + vl);

				// debug(i, j, nw, j - (p - 1));
				// debug(dp[i][j]);

			}
		}
	}

	long double ans = INF;

	for (int i = 0; i < MAXN; i++) {
		for (int j = 0; j < 2; j++) {
			ans = min(ans, dp[n - 1][i][j]);
		}
	}

	cout << fixed << setprecision(12) << ans << '\n';
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

