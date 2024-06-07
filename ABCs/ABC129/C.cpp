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
Notes: Standard Frog 1/2 type problem,
*/

const int MOD = 1e9 + 7;
void solve() {
	int n, m;
	cin >> n >> m;

	vector<int> a(m);
	for (auto &x : a) {
		cin >> x;
	}
	sort(a.begin(), a.end());

	vector<int> dp(n + 1, 0);
	//no of ways to reach the i th step
	dp[0] = 1;

	for (int i = 1; i <= n; i++) {
		if (binary_search(a.begin(), a.end(), i)) {
			continue;
		}

		dp[i] = (dp[i - 1] + (i >= 2 ? dp[i - 2] : 0));
		dp[i] %= MOD;
	}

	cout << dp[n] << "\n";

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

