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

	vector<int> a(n), b(m);
	for (auto &x : a) {
		cin >> x;
	}
	for (auto &x : b) {
		cin >> x;
	}

	sort(a.begin(), a.end());
	sort(b.begin(), b.end());

	int j = 0, ans = 0;
	for (int i = 0; i < m; i++) {
		bool ok = false;
		while (1) {
			if (j >= n) {
				break;
			}
			if (a[j] >= b[i]) {
				ok = true;
				// assign this
				ans += a[j];
				j++;
				break;
			} else {
				j++;
			}

		}

		if (!ok) {
			cout << -1 << "\n";
			return;
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

