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
Notes: Simple ?
*/

void solve() {
	int n, m;
	cin >> n >> m;

	vector<int> a(m);
	for (auto &x : a) {
		cin >> x;
	}

	vector<vector<int>> x(n, vector<int>(m));

	for (auto &y : x) {
		for (auto &z : y) {
			cin >> z;
		}
	}

	bool ok = 1;
	for (int i = 0; i < m; i++) {
		int sm = 0;
		for (int j = 0; j < n; j++) {
			sm += x[j][i];
		}
		if (sm < a[i]) {
			ok = false;
		}
	}

	cout << (ok ? "Yes\n" : "No\n");
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

