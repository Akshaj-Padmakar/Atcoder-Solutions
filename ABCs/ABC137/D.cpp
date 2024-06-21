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
hmmmm, Greedy + STL shit.
*/
bool cmp(pair<int, int> &a, pair<int, int> &b) {
	return (a.second == b.second ? a.first > b.first : a.second > b.second);
}
void solve() {
	int n, m;
	cin >> n >> m;

	vector<pair<int, int>> v(n);
	for (auto &[x, y] : v) {
		cin >> x >> y;
	}

	sort(v.begin(), v.end(), cmp);

	set<int> s;
	for (int i = 1; i <= m; i++) {
		s.insert(i);
	}
	int ans = 0;
	for (int i = 0; i < n; i++) {
		auto [a, b] = v[i];
		// m days -> start date <= m-a+1 then only we recieve the price
		if (!(int)s.size()) {
			break;
		}
		auto it = s.upper_bound(m - a + 1);
		if (it == s.begin()) {
			continue;
		}
		it--;
		// first date that is <= m-a+1
		ans += b;
		s.erase(it);
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
