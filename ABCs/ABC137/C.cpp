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

	map<vector<int>, int> mp;
	for (int i = 0; i < n; i++) {
		string s; cin >> s;
		vector<int> hsh(26, 0);
		for (int j = 0; j < s.size(); j++) {
			hsh[s[j] - 'a']++;
		}
		mp[hsh]++;
	}
	int ans = 0;
	for (auto &x : mp) {
		ans += (x.second * (x.second - 1)) / 2;
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
