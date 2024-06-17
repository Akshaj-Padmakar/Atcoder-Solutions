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
	int n, k;
	cin >> n >> k;

	vector<int> a(k);
	for (auto &x : a) {
		cin >> x;
	}
	int ans = 0;
	for (int msk = 1; msk < (1ll << k); msk++) {
		vector<int> z;
		for (int i = 0; i < k; i++) {
			if (msk & (1ll << i)) {
				z.push_back(a[i]);
			}
		}

		int l = 1;
		for (auto &x : z) {
			if (l > n / x) { // noo
				l = n + 1; // n/l
				break;
			}
			l *= x;
		}

		int on = z.size();

		ans += ((on % 2) ? n / l : -n / l);
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