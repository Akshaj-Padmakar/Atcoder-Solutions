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
*> In such problems we try to fix the order of the quantites in the order described
   in the problem,then try to do something on the second value
*> So we make a map of -a[i] VS {c[i], i}
*> -a[i] for decreasing order a[i] in map.
*> then we insert the values of c[i] in a set s, if there exist any value in s i.e
   less than c[i], i-th card is fucked.
*/

void solve() {
	int n;
	cin >> n;
	vector<int> a(n), c(n);

	for (int i = 0; i < n; i++) {
		cin >> a[i] >> c[i];
	}

	map<int, pair<int, int>>mp;
	set<int> s;

	for (int i = 0; i < n; i++) {
		mp[-a[i]] = {c[i], i};
	}

	for (auto it = mp.begin(); it != mp.end(); it++) {
		auto it2 = s.lower_bound(-(it->second).first);
		s.insert(-(it->second).first);
		if (it2 != s.end()) {
			mp[it->first] = {0, (it->second).second};
		}
	}

	vector<int> ans;
	for (auto x : mp) {
		if (x.second.first != 0) {
			ans.push_back(x.second.second + 1);
		}
	}

	sort(ans.begin(), ans.end());

	cout << ans.size() << "\n";
	for (auto &x : ans) {
		cout << x << " ";
	}

	cout << "\n";
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

