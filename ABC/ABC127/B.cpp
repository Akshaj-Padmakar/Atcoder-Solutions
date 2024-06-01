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
Notes: ughhh
*/

void solve() {
	int r, d, x;
	cin >> r >> d >> x;
	vector<int> ans(12, 0);
	ans[0] = x;

	for (int i = 1; i <= 10; i++) {
		ans[i] = ans[i - 1] * r - d;
	}

	for (int i = 1; i <= 10; i++) {
		cout << ans[i] << "\n";
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

