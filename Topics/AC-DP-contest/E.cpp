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
Notes :
*> Very interesting variation of the classic knapsack.
*> sum(v[i]) <= 1e5; -> make this a state !
*> max value for a weight = min weight for a value

*> dp[i][j] = stores the min weight gained for this config
             scanned first i books with exactly j value in the sack.

*> i depends on i-1, rolling array optimisation.
*/
const int MAXN = 1e5 + 5;
const int INF = 1e12;
void solve() {
	int n, ww;
	cin >> n >> ww;

	vector<int> w(n), v(n);

	for (int i = 0; i < n; i++) {
		cin >> w[i] >> v[i];
	}

	vector<int> dp(MAXN, INF);
	// dp[i][j] -> min weight possible for scanning first i books and exactly j value in the sac.

	dp[0] = 0;
	dp[v[0]] = w[0];

	for (int i = 1; i < n; i++) {
		vector<int> nxt = dp;
		for (int j = v[i]; j < MAXN; j++) {
			nxt[j] = min(nxt[j], dp[j - v[i]] + w[i]);
		}
		swap(nxt, dp);
	}

	for (int i = MAXN - 1; i >= 0; i--) {
		if (dp[i] <= ww) {
			cout << i << "\n";
			return;
		}
	}
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

