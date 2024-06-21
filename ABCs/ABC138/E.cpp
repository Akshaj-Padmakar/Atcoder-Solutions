#include <bits/stdc++.h>
using namespace std;

#ifndef ONLINE_JUDGE
#include "algo/debug.h"
#define debug(x...) cerr << "[" << #x << "] = ["; _print(x)
#else
#define debug(x...)
#endif

#define int long long


void solve() {
	string s, t;
	cin >> s >> t;
	int n = s.size(), m = t.size();
	vector<vector<int>> dp(n, vector<int>(26, -1));
	// dp[i][c] -> stores a j s.t s[j] = i, and j is the least possible such index. o.w store a -1.

	dp[n - 1][s.back() - 'a'] = n - 1;

	for (int i = n - 2; i >= 0; i--) {
		dp[i] = dp[i + 1];
		dp[i][s[i] - 'a'] = i;
	}

	int cnt = 0, cur = 0;
	for (int i = 0; i < m; i++) {
		int c = t[i] - 'a';

		if (dp[cur][c] != -1) {
			cur = dp[cur][c] + 1;
		} else {
			cur = 0; cnt++;
			if (dp[cur][c] == -1) {
				cout << -1 << '\n';
				return;
			}
			cur = dp[cur][c] + 1;
		}
		if (cur == n) {
			cur = 0;
			cnt++;
		}
	}

	cout << cnt*n + cur << '\n';
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
