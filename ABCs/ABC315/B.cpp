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
	int n, s = 0;
	cin >> n;

	vector<int> a(n);
	for (auto &x : a) {
		cin >> x;
		s += x;
	}
	s = (s + 1) / 2;
	int cur = 0;
	for (int i = 0; i < n; i++) {
		if (cur <= s && cur + a[i] >= s) {
			cout << i + 1 << " " << s - cur << "\n";
			return;
		}
		cur += a[i];
	}
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

