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
	vector<pair<int, int>> v(n);

	for (auto &[x, y] : v) {
		cin >> y >> x;
		// f,s
	}

	sort(v.begin(), v.end());
	if (v[n - 1].second == v[n - 2].second) {
		int ans = v[n - 1].first + v[n - 2].first / 2;
		for (int j = n - 1; j >= 0; j--) {
			if (v[n - 1].second != v[j].second) {
				ans = max(ans, v[n - 1].first + v[j].first);
			}
		}
		cout << ans << '\n';
	} else {
		cout << v[n - 1].first + v[n - 2].first;
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

