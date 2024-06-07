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
*> So this problem just uses the simple property of xor:
min(x^y,y^z) <= min(x^z) if x<=y<=z

*> Exploiating this we only then need to check for neighbours
   in a sorted array to find the min xor among all pairs.

*> Easily done using Multiset !
*/
void solve() {
	int q;
	cin >> q;

	multiset<int> ms, xr;

	while (q--) {
		int op;
		cin >> op;
		if (op == 1) {
			int x;
			cin >> x;
			auto it = ms.lower_bound(x);

			if (it == ms.begin()) {
				// no element is less than x
				if (it != ms.end()) {
					xr.insert(*it ^ x);
				}
			} else if (it == ms.end()) {
				// no element is greater than x
				if (it != ms.begin()) {
					--it;
					xr.insert(*it ^ x);
				}
			} else {
				auto it2 = it;
				--it2;
				xr.erase(xr.find(*it ^ *it2)); // *it and *it2 are not adjacent.

				xr.insert(*it ^ x); // *it >= x
				// now we find *it < x
				xr.insert(*it2 ^ x);
			}

			ms.insert(x);
		} else if (op == 2) {
			int x;
			cin >> x;
			auto it = ms.find(x);
			if (it == ms.begin()) {
				// there is no element less than x
				auto itr = it;
				++itr;
				if (itr != ms.end()) {
					xr.erase(xr.find(x ^ *itr));
				}
			} else if (next(it) == ms.end()) {
				// there is no element greater than x
				auto itl = it;
				if (itl != ms.begin()) {
					--itl;
					xr.erase(xr.find(x ^ *itl));
				}
			} else {
				// it is some element in between
				auto itl = it;
				auto itr = it;
				--itl;
				++itr;

				xr.insert(*itl ^ *itr);
				xr.erase(xr.find(*itl ^ x));
				xr.erase(xr.find(*itr ^ x));
			}
			ms.erase(it);
		} else if (op == 3) {
			cout << *xr.begin() << "\n";
		}
	}
}

signed main() {
#ifndef ONLINE_JUDGE
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
#else
#endif
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);

	int t = 1;
	// cin >> t;

	while (t--) {
		solve();
	}

	// cerr << "Time elapsed: " << ((long double)clock() / CLOCKS_PER_SEC) << " s.\n";
}
