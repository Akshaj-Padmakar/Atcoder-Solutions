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
Notes : Straightforward impl.
*/

void solve() {
	int n;
	cin >> n;
	vector<int> a(n);
	cin >> a[0];
	int c = 1;
	for (int i = 1; i < n; i++) {
		cin >> a[i];
		if (c && a[i] > a[0]) {
			cout << i + 1 << "\n";
			c = 0;
		}
	}
	if (c) {
		cout << -1 << "\n";
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

