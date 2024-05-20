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
*> we can reach to i from i-1 or i-2, then we are solving the same subproblem again.

*/
const int INF = 1e9;
void solve() {
	int n;
	cin >> n;
	vector<int> h(n);
	for (auto &x : h) {
		cin >> x;
	}

	vector<int> dp(n, 0);

	for (int i = 1; i < n; i++) {
		dp[i] = min(dp[i - 1] + abs(h[i] - h[i - 1]), (i >= 2 ? dp[i - 2] + abs(h[i] - h[i - 2]) : INF));
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

