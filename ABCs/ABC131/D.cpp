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
*> Very well known greedy problem.
*/
void solve() {
	int n;
	cin >> n;

	vector<pair<int, int>> e;
	for (int i = 0, t, d; i < n; i++) {
		cin >> t >> d;
		e.push_back({d, t});
	}

	sort(e.begin(), e.end());
	int cur = 0;
	for (int i = 0; i < n; i++) {
		auto [d, t] = e[i];
		if (cur + t > d) {
			cout << "No\n";
			return;
		}
		cur += t;
	}

	cout << "Yes\n";
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

