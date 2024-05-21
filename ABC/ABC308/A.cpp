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
*> Straightforward Implmentation.
*/
void solve() {
	vector<int> a(8);
	for (auto &x : a) {
		cin >> x;
	}

	if (is_sorted(a.begin(), a.end())) {
		bool ok = true;
		for (int i = 0; i < 8; i++) {
			if (!(a[i] >= 100 && a[i] <= 675 && a[i] % 25 == 0)) {
				ok = false;
			}
		}
		cout << (ok ?  "Yes\n" : "No\n");
	} else {
		cout << "No\n";
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

