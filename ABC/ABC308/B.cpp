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
*> Simple Implmentation problem.
*/

void solve() {
	int n, m;
	cin >> n >> m;
	vector<string> c(n), z;
	for (auto &x : c) {
		cin >> x;
	}

	map<string, int> mp;

	for (int i = 0; i < m; i++) {
		string s;
		cin >> s;
		z.push_back(s);
	}
	int spec = 0;
	cin >> spec;

	for (int i = 0, x; i < m; i++) {
		cin >> x;
		mp[z[i]] = x;
	}

	int ans = 0;

	for (auto &x : c) {
		if (mp.find(x) == mp.end()) {
			ans += spec;
		} else {
			ans += mp[x];
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

