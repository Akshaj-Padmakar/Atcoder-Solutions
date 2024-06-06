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
Notes: Again a very easy problem, just think bout swapping what colorless apple is swapped with colored one, the min one of red or green will be removed.
       So maybe the only hard thing is to keep a track for that.

*/

void solve() {
	int x, y, a, b, c;
	cin >> x >> y >> a >> b >> c;

	vector<pair<int, int>> e;
	vector<int> aa, bb;
	for (int i = 0, x; i < a; i++) {
		cin >> x;
		e.push_back({x, 0});
		aa.push_back(x);
	}

	for (int i = 0, x; i < b; i++) {
		cin >> x;
		e.push_back({x, 1});
		bb.push_back(x);
	}


	for (int i = 0, x; i < c; i++) {
		cin >> x;
		e.push_back({x, 2});
	}

	sort(aa.begin(), aa.end());
	sort(bb.begin(), bb.end());

	sort(e.begin(), e.end());
	bool ok = false;
	int id = -1;
	if (x > a) {
		ok = 1;
		id = 0;
	}

	if (y > b) {
		ok = 1;
		id = 1;
	}

	int ans = 0;
	while (1) {
		if (e.size() == 0) {
			break;
		}
		auto [v, t] = e.back();
		e.pop_back();

		if (t == 0 && x > 0) {
			ans += v;
			x--;
			aa.pop_back();
		}

		if (t == 1 && y > 0) {
			ans += v;
			y--;
			bb.pop_back();
		}


		if (t == 2) {
			if (ok) {
				ans += v;
				(id == 0 ? x-- : y--);
			} else {
				if (x > 0 && y > 0) {
					int vab = aa[aa.size() - x];
					int vbb = bb[bb.size() - y];

					if (vab > vbb) {
						ans += v;
						y--;
					} else {
						ans += v;
						x--;
					}
				} else if (x > 0) {
					ans += v;
					x--;
				} else if (y > 0) {
					ans += v;
					y--;
				} else {
					break;
				}
			}
		}

	}

	cout << ans << '\n';
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


