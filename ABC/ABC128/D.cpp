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
*> A pretty easy problem due constraints, just brute forces, how about an optimal solution ??
*/
void solve() {
	int n, k;
	cin >> n >> k;

	vector<int> a(n);
	for (auto &x : a) {
		cin >> x;
	}
	int fans = 0;
	for (int i = -1; i < n; i++) {
		for (int j = i + 1; j <= n; j++) {
			// 0...i  j..n-1 removed

			if (i + 1 + (n - 1 - j + 1) > k) {
				continue;
			}

			multiset<int> s;
			int ans = 0;

			for (int z = 0; z <= i; z++) {
				s.insert(a[z]);
				ans += a[z];
			}
			for (int z = j; z < n; z++) {
				s.insert(a[z]);
				ans += a[z];
			}

			int lft = k - (i + 1 + (n - 1 - j + 1));
			while (lft > 0) {
				if (s.size() == 0) {
					break;
				}
				auto it = s.begin();
				if (*it < 0) {
					ans -= *it;
					s.erase(it);
					lft--;
				} else {
					break;
				}

				if (lft == 0) {
					break;
				}
			}

			fans = max(fans, ans);
		}
	}
	cout << fans << "\n";
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

