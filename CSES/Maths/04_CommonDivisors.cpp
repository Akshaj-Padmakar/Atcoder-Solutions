#include <bits/stdc++.h>
using namespace std;

#ifndef ONLINE_JUDGE
#include "algo/debug.h"
#define debug(x...) cerr << "[" << #x << "] = ["; _print(x)
#else
#define debug(x...)
#endif

#define int long long

const int MAXN = 1e6 + 5;
void solve() {
	int n;
	cin >> n;
	vector<int> a(n);
	vector<int> cnt(MAXN, 0ll);
	for (auto &x : a) {
		cin >> x;
		cnt[x]++;
	}
	int ans = 1;
	for (int i = MAXN - 1; i > 1; i--) {
		int cur = 0;
		for (int j = i; j < MAXN; j += i) {
			cur += cnt[j];
		}
		if (cur >= 2) {
			ans = i;
			break;
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