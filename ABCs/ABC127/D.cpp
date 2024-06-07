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
Note:
*> This solution looks like a brute force, but actually is pretty optimal,
   ig the only hard part here is to convience yourself that it works in the time limit !
*/
void solve() {
	int n, m;
	cin >> n >> m;

	map<int, int> mp;

	for (int i = 0, x; i < n; i++) {
		cin >> x;
		mp[x]++;
	}

	while (m--) {
		int b, c;
		cin >> b >> c;
		swap(b, c);
		while (1) {
			auto it = mp.begin();
			if (it->first >= b) {
				break;
			} else {
				if (it->second <= c) {
					mp[b] += it->second;
					c -= it->second;
					mp.erase(it);
				} else {
					mp[b] += c;
					mp[it->first] -= c;
					break;
				}
			}
		}
	}

	int sm = 0;
	for (auto [x, y] : mp) {
		sm += x * y;
	}
	cout << sm << "\n";
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

