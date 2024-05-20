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
*> Interesting problem, variation of this came up in some indian regionals.

*> dp[i][j][k] -> score of player 0 when  ..player k plays on segement a[i..j]

*> Recurrance : dp[i][j][0] = max(dp[i+1][j][1] + a[i], dp[i][j-1][0] + a[j]) // player 1 wants to max its score
                dp[i][j][1] = min(dp[i+1][j][0], dp[i][j-1][0]) // player 2 wants to min player 1's score[stored in dp]

*> OOL : i,j,0 -> i+1,j,1 i,j-1,
*/
void solve() {
	int n;
	cin >> n;
	vector<int> v(n);
	int sm = 0;
	for (auto &x : v) {
		cin >> x; sm += x;
	}

	int dp[n][n][2];
	memset(dp, 0ll, sizeof(dp));
	for (int i = 0; i < n; i++) {
		dp[i][i][0] = v[i];
		dp[i][i][1] = 0;
	}

	for (int i = n - 1; i >= 0; i--) {
		for (int j = 0; j < n; j++) {
			dp[i][j][0] = max((i + 1 > j ? 0 : dp[i + 1][j][1]) + v[i], (i > j - 1 ? 0 : dp[i][j - 1][1]) + v[j]);
			dp[i][j][1] = min(i + 1 > j ? 0 : dp[i + 1][j][0], i > j - 1 ? 0 : dp[i][j - 1][0]);
		}
	}
	cout << 2 * dp[0][n - 1][0] - sm << "\n";
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

