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
*> So very similar to range + greedy query problems in cses.
*> We solve for each closing of a point and try to check if some guy is fucked due to that or not !
*> So just iterating over the set of people sorted according to there start time, and seeing if the current iterator is fucked by the closing or not.
*> Code have more comments.
*/

void solve() {
	int n, q;
	cin >> n >> q;

	vector<pair<int, pair<int, int>>> v;
	set<pair<int, int>> s;

	for (int i = 0, l, r, x; i < n; i++) {
		cin >> l >> r >> x;
		v.push_back({x, {l - x, r - x - 1}});
	}
	sort(v.begin(), v.end());
	// like if it is stopped at both x = 2 and x = 10 ? you will answer x = 2 right ?
	for (int i = 0, d; i < q; i++) {
		cin >> d;
		s.insert({d, i});
	}

	vector<int> ans(q, -1);

	for (int i = 0; i < n; i++) {
		int x = v[i].first;
		int l = v[i].second.first;
		int r = v[i].second.second;


		if (s.size() == 0) {
			break;
		}

		debug(l, r, x);

		auto it = s.lower_bound({l, -1}); // second element is random

		while (1) {
			if (it == s.end()) {
				break;
			}
			if ((*it).first <= r) {
				ans[(*it).second] = x;
				auto it2 = it;
				it2++;
				s.erase(it);
				it = it2;
			} else {
				break;
			}
		}
	}

	for (auto x : ans) {
		cout << x << "\n";
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

