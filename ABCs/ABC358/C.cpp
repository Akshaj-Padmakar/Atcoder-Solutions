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
	int n, m;
	cin >> n >> m;

	vector<string> s(n);

	for (auto &x : s) {
		cin >> x;
	}
	int ans = n;
	for (int msk = 1; msk < (1ll << n); msk++) {
		vector<int> hsh(m, 0);
		int c = 0;
		for (int j = 0; j < n; j++) {
			if (msk & (1ll << j)) {
				c++;
				for (int k = 0; k < m; k++) {
					if (s[j][k] == 'o') {
						hsh[k] = 1;
					}
				}
			}
		}

		bool ok = true;
		for (int i = 0; i < m; i++) {
			if (hsh[i] == 0) {
				ok = false;
			}
		}
		debug(hsh, msk);

		if (ok) {
			ans = min(ans, c);
		}
	}

	cout << ans << '\n';
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

