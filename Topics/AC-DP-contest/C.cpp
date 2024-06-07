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
*> dp[i][j] -> max happiness achieved till day i and performing jth activity on the ith day.
*> then it just depends on doing someother activity on i-1th day, say some k(!= j).
*> recurrance relations hence follows.
*/
const int INF = 1e9 + 5;
void solve() {
	int n;
	cin >> n;
	vector<vector<int>> a(n, vector<int>(3));

	for (int i = 0; i < n; i++) {
		cin >> a[i][0] >> a[i][1] >> a[i][2];
	}

	vector<vector<int>> dp(n, vector<int>(3, -INF));
	dp[0][0] = a[0][0];
	dp[0][1] = a[0][1];
	dp[0][2] = a[0][2];


	for (int i = 1; i < n; i++) {
		for (int j = 0; j < 3; j++) {
			for (int k = 0; k < 3; k++) {
				if (j == k) {
					continue;
				}
				dp[i][j] = max(dp[i][j], dp[i - 1][k] + a[i][j]);
			}
		}
	}

	cout << *max_element(dp[n - 1].begin(), dp[n - 1].end()) << "\n";
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

