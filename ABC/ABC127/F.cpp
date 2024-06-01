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
*> 9th class modular maths tbh.

*> so after say some queries we have the following formulae for f(x)

*> f(x) = |x-a1| + .. + |x-ak| + b1 + .. + bk, now we aim to find the min of this function over all x.

*> obv b1 + .. + bk is const. So essentially it reduces to min h(x) = |x-a1| + .. + |x-ak|

*> happens at ? median{a1, a2 ... ak}

*> So this essentially converts to finding the median of a dynamic array !

*> Maintain l and r -> left and right part, l is decreasing and r is increasing.
   so that l begin and r begin makes a continous array l.end() -> l.begin() -> r.begin() -> r.end()

*> inserting (a,b) ? compare with l.begin() and insert in the req. set.

*> Since we claim that after each query we have ||l| - |r|| <= 1 -> after this process at max ||l| - |r|| <= 2

*> we check if ||l| - |r|| == 2 is true, then we push the max from l to r or min from r to l
   -> whichever satisfies ||l| - |r|| <= 1 again.

*> Final value of f(x) ? -sum(l) + sum(r) {Imagine how these will open} + sum(b) - ||l| - |r||*median
*> if ||l| - |r|| == 1 holds, then whichever is larger will provide the median. O.W its l {ATQ Minimise x}
*/
void solve() {
	int q;
	cin >> q;

	int sumb = 0, suml = 0, sumr = 0;
	multiset<int, greater<int>> l;
	multiset<int> r;
	// l decreasing
	// r increasing
	while (q--) {
		int op;
		cin >> op;

		if (op == 1) {
			int a, b;
			cin >> a >> b;
			sumb += b;

			if (l.size() == 0) {
				l.insert(a);
				suml += a;

			} else {
				if (a > *l.begin()) {
					// add it in r
					r.insert(a);
					sumr += a;
				} else {
					l.insert(a);
					suml += a;
				}
			}

			if (l.size() > r.size() + 1) {
				auto it = l.begin();
				r.insert(*it);

				sumr += *it;
				suml -= *it;

				l.erase(it);
			} else if (r.size() > l.size() + 1) {
				auto it = r.begin();
				l.insert(*it);

				suml += *it;
				sumr -= *it;

				r.erase(it);
			}

		} else {
			int vl = *l.begin();
			if (r.size() == l.size() + 1) {
				vl = *r.begin();
			}
			// debug(l, r, vl, sumr , suml , sumb);

			cout << vl << " " << sumr - suml + sumb + ((int)l.size() - (int)r.size())*(vl) << "\n";
		}
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

