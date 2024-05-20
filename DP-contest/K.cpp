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
*> A very classic game-dp problem.
*/

void solve() {
	int n, k;
	cin >> n >> k;

	vector<int> a(n);
	for (auto &x : a) {
		cin >> x;
	}

	vector<int> dp(k + 1, 0);
	//dp[i] -> 0/1 if the starting player wins the game with i starting stones.

	dp[0] = 0;
	for (int i = 1; i <= k; i++) {
		for (int j = 0; j < n; j++) {
			if (i >= a[j] && !dp[i - a[j]]) {
				dp[i] = 1;
			}
		}
	}
	cout << (dp[k] ? "First\n" : "Second\n");
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

