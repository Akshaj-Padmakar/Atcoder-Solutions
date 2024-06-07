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
*> A very interesting problem.
*> The key idea here is, which coins turn up head indiviually is not important, just there total count.
*> Hence we make this a state, and the first state is then choosed similar to knapsack problems.
*> Scan first i coins, and get j heads out of it, what is the probablity of this ?
*> In the end its just sum(dp[n][i]) s.t i > n-i

*> Recurrance : dp[i][j] = dp[i - 1][j] * (1 - a[i]) + dp[i - 1][j - 1] * a[i]
*> Order of loops ? (which variable should be written first in the iterative sol? See J.)
*/

void solve() {
	int n;
	cin >> n;

	vector<long double> a(n + 1);
	for (int i = 1; i <= n; i++) {
		cin >> a[i];
	}

	vector<vector<long double>> dp(n + 1, vector<long double>(n + 1, 0.));
	// dp[i][j] -> stores the probablity of getting j heads out of first i coin tosses.

	dp[1][0] = 1. - a[1];
	dp[1][1] = a[1];

	for (int i = 2; i <= n; i++) {
		for (int j = 0; j <= n; j++) {
			dp[i][j] = dp[i - 1][j] * (1 - a[i]) + (j > 0 ? dp[i - 1][j - 1] * a[i] : 0.);
		}
	}

	long double ans = 0;
	for (int i = n;; i--) {
		if (i < n - i) {
			break;
		}
		ans += dp[n][i];
	}

	cout << fixed << setprecision(10) << ans << "\n";
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

