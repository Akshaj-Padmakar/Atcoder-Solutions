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
	int n;
	cin >> n;

	vector<int> v(n), z;
	for (auto &x : v) {
		cin >> x;
	}
	for (int i = 0; i < n; i++) {
		if (i == 0 || i == 1) {
			z.push_back(1);
		} else {
			z.push_back(z.back() * 2ll);
		}
	}

	sort(v.begin(), v.end());
	int ans = 0;
	for (int i = 0; i < n; i++) {
		ans += z[i] * v[i];
	}
	cout << fixed << setprecision(12) << ans / (z.back() * 2.) << '\n';
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
