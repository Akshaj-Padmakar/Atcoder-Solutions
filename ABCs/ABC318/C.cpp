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
	int n, d, p;
	cin >> n >> d >> p;

	vector<int> a(n);
	for (auto &x : a) {
		cin >> x;
	}
	sort(a.begin(), a.end(), greater<int>());

	auto psm = a;
	for (int i = 1; i < n; i++) {
		psm[i] += psm[i - 1];
	}
	auto sm = [&](int i, int j) {
		if (i > j) {
			return 0ll;
		}
		return psm[j] - (i > 0 ? psm[i - 1] : 0);
	};
	auto ceil = [&](int a, int b) {
		return (a + b - 1) / b;
	};
	int ans = min(ceil(n, d) * p, psm.back());
	int c = 1;

	for (int i = d - 1; i < n; i += d) {
		ans = min(ans, c * p + sm(i + 1, n - 1));
		c++;
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

