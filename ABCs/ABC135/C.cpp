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
*> Implmentation
*/

void solve() {
	int n; cin >> n;
	vector<int> a(n + 1), b(n);
	for (auto &x : a) {
		cin >> x;
	}
	for (auto &x : b) {
		cin >> x;
	}
	b.push_back(0);

	int ans = 0;
	for (int i = 0; i < n + 1; i++) {
		if (i == 0) {
			// only b[0] can fight
			ans += min(a[0], b[0]);
			b[0] -= min(a[0], b[0]);
		} else {
			ans += min(a[i], b[i - 1]);
			a[i] -= min(a[i], b[i - 1]);
			ans += min(a[i], b[i]);
			b[i] -= min(a[i], b[i]);
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
