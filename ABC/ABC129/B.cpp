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
Notes: Super easy prefix sum problem.
*/
void solve() {
	int n, sm = 0;
	cin >> n;
	vector<int> w(n);
	for (auto &x : w) {
		cin >> x;
		sm += x;
	}
	int mn = 1000000;
	for (int i = 1; i + 1 < n; i++) {
		w[i] += w[i - 1];
		mn = min(mn, abs(sm - 2 * w[i]));
	}
	cout << mn << "\n";
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

