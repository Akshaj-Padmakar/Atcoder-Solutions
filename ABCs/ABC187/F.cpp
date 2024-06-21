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
*> Notes :
*> A classic submasking problem, but but how is 3^n working on n ~ 18, n ~ 16 is the max ? but somehow
*> pre-computing if a msk set as a CC can that mask satisfy the constraints of the problem ? just store that before hand
*> Now in each msk-> consider submsk -> check if this sbmsk set satisfy the constraints.
*/

const int INF = 25;
void solve() {
	int n, m;
	cin >> n >> m;

	set<pair<int, int>> e;
	for (int i = 0, a, b; i < m; i++) {
		cin >> a >> b;
		a--, b--;

		if (a > b) {
			swap(a, b);
		}

		e.insert({a, b});
	}
	vector<bool> pos(1ll << n);
	for (int msk = 0; msk < 1ll << n; msk++) {
		// int on = __builtin_popcount(msk);
		// int Esz = on * (on - 1) / 2;
		bool ok = true;
		for (int j = 0; j < n; j++) {
			if (msk & (1ll << j)) {
				for (int k = j + 1; k < n; k++) {
					if (msk & (1ll << k)) {
						if (e.find({j, k}) != e.end()) {
							//ok
						} else {
							ok = false;
							break;
						}
					}
				}
			}
		}
		if (ok) {
			pos[msk] = ok;
		}
	}
	vector<int> dp(1ll << n, INF);
	for (int msk = 0; msk < 1ll << n; msk++) {
		if (msk == 0) {
			dp[msk] = 0;
		}
		for (int sbmsk = msk; sbmsk > 0; sbmsk = (sbmsk - 1)&msk) {
			if (pos[sbmsk]) {
				dp[msk] = min(dp[msk], dp[msk ^ sbmsk] + 1);
			}
		}
	}

	cout << dp[(1ll << n) - 1] << "\n";
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
