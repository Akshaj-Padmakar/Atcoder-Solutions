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
*> Just a very easy iterative solution exist due to constraints, maybe try it without iteration ?
*/


void solve() {
	int n, k;
	cin >> n >> k;

	if (n <= k) {
		long double req = 1. / (1.*n);

		long double ans = 0;
		for (int i = 1; i <= n; i++) {
			int cur = i;
			int cnt = 0;
			while (cur < k) {
				cur *= 2;
				cnt++;
			}

			ans += req * 1. / (1.*(1ll << cnt));
		}
		cout << fixed << setprecision(12) << ans << "\n";
	} else {
		long double req = 1. / (1.*n);

		long double ans = 0;
		for (int i = 1; i <= n; i++) {
			int cur = i;
			int cnt = 0;
			while (cur < k) {
				cur *= 2;
				cnt++;
			}
			int x = 1ll << cnt;
			ans += req / (1.*x);
		}
		cout << fixed << setprecision(12) << ans << "\n";
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

