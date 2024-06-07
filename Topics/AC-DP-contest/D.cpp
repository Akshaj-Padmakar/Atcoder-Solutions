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
*> dp[i][j] = stores the max value gained for this config
              scanned first i books with exactly j weight in the sack.

*> dp[i][j] = max(dp[i-1][j], dp[i-1][j-w[i]] + v[i])
*> i depends on i-1, rolling array optimisation ? {just need 2 states for i to solve}

51 ms -> 13 ms

82312 Kb -> 4780 Kb
*/
const int INF = 1e9 + 5;
void solve() {
	int n, ww;
	cin >> n >> ww;

	vector<int> w(n), v(n);

	for (int i = 0; i < n; i++) {
		cin >> w[i] >> v[i];
	}

	// vector<vector<int>> dp(n, vector<int>(ww + 1, -INF));
	vector<int> dp(ww + 1, -INF);
	//dp[i][j] -> stores the max value gained by carring a weight of exactly j in the sack by scanning the first i books.

	dp[0] = 0;
	dp[w[0]] = v[0];

	for (int i = 1; i < n; i++) {
		vector<int> nxt = dp; // dont take the i-th item.
		for (int j = w[i]; j <= ww; j++) {
			nxt[j] = max(nxt[j], dp[j - w[i]] + v[i]);

		}
		swap(nxt, dp);
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

