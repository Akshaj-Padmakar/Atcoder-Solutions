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
*> Simple clockwise and counter clock wise rotations and write distance.
*/
void solve() {
	int n, k;
	cin >> k >> n;
	vector<int> a(n);
	for (auto &x : a) {
		cin >> x;
	}
	int ans = min(a[n - 1] - a[0], min(a[0] + k - a[1], k - a[n - 1] + a[n - 2]));
	for (int i = 1; i + 1 < n; i++) {
		ans = min(ans, k - a[i] + a[i - 1]);
		ans = min(ans, a[i] + k - a[i + 1]);
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

