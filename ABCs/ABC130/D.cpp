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
*> Standard Prefix sum problem
*/
void solve() {
	int n, k;
	cin >> n >> k;

	vector<int> a(n);
	for (auto &x : a) {
		cin >> x;
	}

	auto psm = a;
	int ans = 0;
	for (int i = 1; i < n; i++) {
		psm[i] += psm[i - 1];
	}

	for (int i = 0; i < n; i++) {
		// k <= psm[i] - psm[j-1] does there exist such a j ?
		// psm[j-1] <= psm[i] - k;
		if (psm[i] < k) {
			continue;
		}

		auto it = upper_bound(psm.begin(), psm.end(), psm[i] - k);

		ans += it - psm.begin() + 1;
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

