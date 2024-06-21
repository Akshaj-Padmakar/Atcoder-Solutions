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
	vector<int> a(n);
	for (auto &x : a) {
		cin >> x;
	}

	if (is_sorted(a.begin(), a.end())) {
		cout << "YES\n"; return;
	}

	for (int i = 0; i < n; i++) {
		for (int j = i + 1; j < n; j++) {
			swap(a[i], a[j]);
			if (is_sorted(a.begin(), a.end())) {
				cout << "YES\n"; return;
			}
			swap(a[i], a[j]);
		}
	}
	cout << "NO\n";
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
