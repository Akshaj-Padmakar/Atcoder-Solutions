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
Note: Fck you, this was so damn easy.

*> How to count the number of no.s that have there kth bit set till n ? DERIVE THIS SHIT.
*> rest is easy maths.

https://www.geeksforgeeks.org/count-numbers-up-to-n-having-kth-bit-set/
*/
const int MOD = 998244353;
int getcount(int n, int k) {
	int res = (n >> (k + 1)) << k;

	if ((n >> k) & 1) {
		res += n & ((1ll << k) - 1);
	}
	return res;
}


void solve() {
	int n, m;
	cin >> n >> m;

	int ans = 0;
	for (int i = 0; i < 61; i++) {
		if (m & (1ll << i)) {
			ans += getcount(n + 1, i);
			ans %= MOD;
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

