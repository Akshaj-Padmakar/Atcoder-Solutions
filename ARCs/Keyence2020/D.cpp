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
*> Probably the best dp problem on bitmasking.
*> How the hell do you think all this ? deadly.
*/
const int INF = 1e10;
void solve() {
	int n;
	cin >> n;
	vector<int> a(n), b(n);
	for (auto &x : a) {
		cin >> x;
	}
	for (auto &x : b) {
		cin >> x;
	}


	vector<vector<int>> dp(n, vector<int>(1ll << n, INF));

	//dp[i][msk] -> min no.of moves to sort the msk set of cards, s.t i is at the last index. Note that we use all the cards, its just that the set msk is sorted !
	// note that all the choosen cards are swapped and reaches the 1st half.
	// so it looks something like this -> 1111000
	for (int i = 0; i < n; i++) {
		dp[i][(1ll << i)] = i;
	}

	for (int msk = 1; msk < (1ll << n); msk++) {
		for (int i = 0; i < n; i++) {
			if (msk == (1ll << i)) {
				continue;
			}
			if (!(msk & (1ll << i))) {
				continue;
			}

			int on = __builtin_popcount(msk) - 1;
			int tp = (abs(on - i) % 2 ? b[i] : a[i]); // top
			// only relative distance determines what value is on top, irrespective of path.

			int cnt = 0;
			for (int j = 0; j < n; j++) {
				if (!(msk & (1ll << j)) || (i == j)) {
					continue;
				}
				if (j > i) {
					cnt++; // if j > i -> i have moved 1 more place ahead.
				}
			}
			for (int j = 0; j < n; j++) {
				if (!(msk & (1ll << j)) || (i == j)) {
					continue;
				}

				int tpP = (abs(on - 1 - j) % 2 ? b[j] : a[j]); //top-previous

				if (tp >= tpP) {
					// its ok, we can map these states.
					dp[i][msk] = min(dp[i][msk], dp[j][msk ^ (1ll << i)] + abs(on - (i + cnt)));
				}
			}
		}
	}
	int ans = INF;
	for (int i = 0; i < n; i++) {
		ans = min(ans, dp[i][(1ll << n) - 1]);
	}
	cout << (ans == INF ? -1 : ans) << '\n';

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

