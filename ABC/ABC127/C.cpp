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
Note:
*> Based on a very well know psm technique used for static queries, add 1 at l and -1 at r, take psm.
*/

void solve() {
	int n, m;
	cin >> n >> m;

	vector<int> psm(n, 0);

	for (int i = 0, l, r; i < m; i++) {
		cin >> l >> r;
		l--, r--;
		psm[l]++;
		if (r + 1 < n) {
			psm[r + 1]--;
		}
	}

	for (int i = 1; i < n; i++) {
		psm[i] += psm[i - 1];
	}

	int ans = 0;
	for (int i = 0; i < n; i++) {
		if (psm[i] == m) {
			ans++;
		}
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

