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
A very ez standar problem, think bout i index here(or maybe k)
*/
void solve() {
	int n;
	cin >> n;
	vector<int> a(n);
	for (auto &x : a) {
		cin >> x;
	}
	map<int, vector<int>> mp;
	for (int i = 0; i < n; i++) {
		mp[a[i]].push_back(i);
	}
	auto psm = mp;
	for (auto [x, y] : psm) {
		for (int j = 1; j < y.size(); j++) {
			psm[x][j] += psm[x][j - 1];
		}
	}

	int ans = 0;

	for (int i = 0; i < n; i++) {
		int id = lower_bound(mp[a[i]].begin(), mp[a[i]].end(), i) - mp[a[i]].begin();
		int k = mp[a[i]].size() - id - 1;

		ans += (psm[a[i]].back() - psm[a[i]][id]) - (k) * i - (k * (k + 1)) / 2;
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

