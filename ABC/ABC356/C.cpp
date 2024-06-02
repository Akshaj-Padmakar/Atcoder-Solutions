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
Notes: Simple Bitmasking and brute force tbh.
*/
void solve() {
	int n, m, k;
	cin >> n >> m >> k;

	vector<vector<int>> tc(m);
	vector<int> res;
	// each vector is a tc and finally store the result in it

	for (int i = 0, sz; i < m; i++) {
		cin >> sz;

		for (int j = 0, x; j < sz; j++) {
			cin >> x;
			x--;
			tc[i].push_back(x);
		}
		char cc;
		cin >> cc;
		if (cc == 'o') {
			res.push_back(1);
		} else {
			res.push_back(0);
		}
	}
	int ans = 0;
	for (int msk = 0; msk < 1ll << n; msk++) {
		vector<int> tru;
		for (int j = 0; j < n; j++) {
			if (msk & (1ll << j)) {
				tru.push_back(j);
			}
		}
		bool ok = true;
		for (int i = 0; i < m; i++) {
			int c = 0;
			for (int j = 0; j < tc[i].size(); j++) {
				if (binary_search(tru.begin(), tru.end(), tc[i][j])) {
					c++;
				}
			}
			if (c >= k) {
				// fine we can open the door.
				if (res[i] == 1) {
					//ok
				} else {
					ok = false;
					break;
				}
			} else {
				if (res[i] == 0) {
					//ok
				} else {
					ok = false;
					break;
				}
			}
		}

		ans += ok;
	}

	cout << ans << "\n";

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

