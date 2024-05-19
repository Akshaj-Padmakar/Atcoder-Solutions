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
Notes :
*> Pretty Easy for E, here just noticing that till what index can string
   s can match as prefix and suffix to t[Easy task]

*> Since we just need to count pairs, we just need to find how many values of j s.t
*> vb[j] <= va[i]  {va -> prefix index , vb -> suffix index} {ez, Use --upper bound}
*/

void solve() {
	int n;
	cin >> n;
	string t;
	cin >> t;

	vector<string> s(n);
	for (auto &x : s) {
		cin >> x;
	}
	vector<int> va, vb;
	for (int i = 0; i < n; i++) {
		int k = 0;
		for (int j = 0; j < s[i].size(); j++) {
			if (k >= t.size()) {
				break;
			}
			if (s[i][j] == t[k]) {
				k++;
			}
		}
		if (k >= 0) {
			va.push_back(k - 1);
		}


		k = t.size() - 1;

		for (int j = s[i].size() - 1; j >= 0; j--) {
			if (k < 0) {
				break;
			}
			if (s[i][j] == t[k]) {
				k--;
			}
		}
		vb.push_back(k + 1);
	}

	sort(va.begin(), va.end());
	sort(vb.begin(), vb.end());

	int ans = 0;
	for (int i = 0; i < va.size(); i++) {
		auto it = upper_bound(vb.begin(), vb.end(), va[i] + 1);
		if (it == vb.begin()) {
			continue;
		}
		it--;
		ans += it - vb.begin() + 1;
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

