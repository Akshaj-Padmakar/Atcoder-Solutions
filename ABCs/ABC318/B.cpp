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

	vector<int> a(n), b(n), c(n), d(n);
	for (int i = 0; i < n; i++) {
		cin >> a[i] >> b[i] >> c[i] >> d[i];
	}

	auto check = [&](int i, int j, int k) {
		return (i >= a[k] && i < b[k]) && (j >= c[k] && j < d[k]);
	};
	set<pair<int, int>> s;
	for (int i = 0; i <= 100; i++) {
		for (int j = 0; j <= 100; j++) {
			for (int k = 0; k < n; k++) {
				if (check(i, j, k)) {
					s.insert({i, j});
				}
			}
		}
	}

	cout << s.size() << "\n";
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

