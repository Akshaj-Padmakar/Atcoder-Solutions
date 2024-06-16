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
	int n, k;
	cin >> n >> k;

	vector<int> p(n);
	for (auto &x : p) {
		cin >> x;
		x--;
	}

	vector<int> rev(n);
	for (int i = 0; i < n; i++) {
		rev[p[i]] = i;
	}

	set<int> s;
	for (int i = 0; i < k; i++) {
		s.insert(rev[i]);
	}
	int ans = (*(--s.end()) - *s.begin());
	for (int i = 1; i < n; i++) {
		if (i + k - 1 >= n) {
			break;
		}
		s.erase(rev[i - 1]);
		s.insert(rev[i + k - 1]);

		ans = min(ans, (*(--s.end()) - *s.begin()));
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

