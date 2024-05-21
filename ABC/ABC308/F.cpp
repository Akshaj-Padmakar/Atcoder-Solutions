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
*> A very intuitive greddy problem,
*> ANS = sum(p[i]) - sum(d[i_k]) where some subset of d is choosen.
*> So only option we have is to maximise sum(d[i_k]) without any constraint, so we take the max d possible.
*> Rest is implementation.

*> Never overcomplicate ! I first wrote a 200 lines bs + st bash :/
https://atcoder.jp/contests/abc308/submissions/43730898
*/

void solve() {
	int n, m;
	cin >> n >> m;
	vector<int> p(n);
	int sm = 0;
	for (auto &x : p) {
		cin >> x;
		sm += x;
	}

	vector<int> l(m), d(m);
	for (auto &x : l) {
		cin >> x;
	}
	for (auto &x : d) {
		cin >> x;
	}
	vector<pair<int, int>> dl;

	for (int i = 0; i < m; i++) {
		dl.push_back({d[i], -l[i]});
	}

	sort(p.begin(), p.end());
	sort(dl.begin(), dl.end());
	multiset<int> ms(p.begin(), p.end());

	for (int i = m - 1; i >= 0; i--) {
		auto [dd, ll] = dl[i];

		auto it = ms.lower_bound(-ll);

		if (it != ms.end()) {
			ms.erase(it);
			sm -= dd;
		}
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

