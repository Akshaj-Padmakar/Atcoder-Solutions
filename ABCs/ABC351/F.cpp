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
*> It's obv to solve this once we realise it's pretty simialr to INVERSION problems.
*/
template <class T> struct fenwick_tree {
public:
	fenwick_tree() : _n(0) {}

	fenwick_tree(int n) : _n(n), data(n) {}

	void delta(int i, T delta) {
		assert(0 <= i && i < _n);
		i++;
		while (i <= _n) {
			data[i - 1] += (delta);
			i += i & -i;
		}
	}

	T sum(int l, int r) {
		assert(0 <= l && l <= r && r <= _n);

		return pQuery(r) - pQuery(l);
	}

private:
	int _n;
	vector<T> data;

	T pQuery(int r) {
		T s = 0;
		while (r > 0) {
			s += data[r - 1];
			r -= r & -r;
		}
		return s;
	}
};


void solve() {
	int n;
	cin >> n;
	vector<int> a(n);
	for (auto &x : a) {
		cin >> x;
	}

	auto coo_compress = [&](vector<int> &x) {
		// coordinates compresse x and over-writes on it !
		int sz = x.size(), id = 0;
		map<int, int> mp;

		for (int i = 0; i < sz; i++) {
			mp[x[i]] = 1;
		}

		for (auto x : mp) {
			mp[x.first] = id++;
		}

		for (int i = 0; i < sz; i++) {
			x[i] = mp[x[i]];
		}
	};
	auto _a = a;
	coo_compress(_a);
	map<int, int> rmp;
	for (int i = 0; i < n; i++) {
		rmp[_a[i]] = a[i];
	}
	fenwick_tree<int> ftval(n + 2), ftcnt(n + 2);
	int ans = 0;
	for (int i = n - 1; i >= 0; i--) {
		int sub = ftcnt.sum(_a[i], n + 1);
		int sm = ftval.sum(_a[i], n + 1);

		ans += sm - a[i] * sub;

		ftcnt.delta(_a[i], 1ll);
		ftval.delta(_a[i], rmp[_a[i]]);
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
