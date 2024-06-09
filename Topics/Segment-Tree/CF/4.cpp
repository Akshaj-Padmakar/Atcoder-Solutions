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
https://codeforces.com/contest/61/problem/E

*/
int log2_ceil(int n) {
	int x = 0;
	while ((1ll << x) < (int)(n)) {
		x++;
	}
	return x;
}

template <class S, S (*op)(S, S), S (*e)()> struct segtree {
public:
	segtree(int n) {
		_n = n;
		log = log2_ceil(_n);
		size = 1 << log;
		d = vector<S>(2 * size, e());
	}

	segtree(const vector<S>& v) {
		_n = v.size();
		log = log2_ceil(_n);
		size = 1 << log;
		d = vector<S>(2 * size, e());

		for (int i = 0; i < _n; i++) {
			d[size + i] = v[i];
		}
		for (int i = size - 1; i >= 1; i--) {
			update(i);
		}
	}

	void set(int p, S x) {
		assert(0 <= p && p < _n);

		p += size; d[p] = x;

		for (int i = 1; i <= log; i++) {
			update(p >> i);
		}
	}

	S get(int p) {
		assert(0 <= p && p < _n);
		return d[p + size];
	}
	S prod(int l, int r) {
		assert(0 <= l && l <= r && r <= _n);
		S sml = e(), smr = e();
		l += size;
		r += size;

		while (l < r) {
			if (l & 1) sml = op(sml, d[l++]);
			if (r & 1) smr = op(d[--r], smr);
			l >>= 1;
			r >>= 1;
		}
		return op(sml, smr);
	}
private:
	int _n, size, log;
	vector<S> d;

	void update(int k) {
		d[k] = op(d[2 * k], d[2 * k + 1]);
	}
};


int op(int a, int b) {
	return a + b;
}
int e() { return 0; }


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

	coo_compress(a);

	segtree<int, op, e> stl(n + 2);
	segtree<int, op, e> str(n + 2);

	stl.set(a[0], 1);
	for (int i = 1; i < n; i++) {
		str.set(a[i], str.get(a[i]) + 1);
	}

	int ans = 0;
	for (int i = 1; i + 1 < n; i++) {
		str.set(a[i], str.get(a[i]) - 1);
		ans += stl.prod(a[i] + 1, n + 2) * str.prod(0, a[i]);
		stl.set(a[i], stl.get(a[i]) + 1);
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

