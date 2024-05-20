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
*> dp[i] = min cost to reach the i-th tower.
*> we can reach to i from i-j,for all j<=i then we are solving the same subproblem again.
*/
const int INF = 1e9;
void solve() {
	int n, k;
	cin >> n >> k;
	vector<int> h(n);
	for (auto &x : h) {
		cin >> x;
	}

	vector<int> dp(n, INF);
	dp[0] = 0;
	for (int i = 1; i < n; i++) {
		for (int j = 1; j <= k && j <= i; j++) {
			dp[i] = min(dp[i], dp[i - j] + abs(h[i] - h[i - j]));
		}
	}

	cout << dp[n - 1] << "\n";
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

