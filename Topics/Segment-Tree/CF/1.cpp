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
https://codeforces.com/contest/339/problem/D
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

struct S {
	int v;
	int lvl;
};

S op(S a, S b) {
	if (a.lvl % 2) {
		// same lvl elements are operated obv.
		return S{a.v ^ b.v, b.lvl + 1};
	} else {
		return S{a.v | b.v, a.lvl + 1};
	}
}
S e() { return S{0, 0}; }

void solve() {
	int n, m;
	cin >> n >> m;

	vector<S> v(1ll << n);
	for (auto &x : v) {
		cin >> x.v;
		x.lvl = 0;
	}
	segtree<S, op, e> st(v);
	while (m--) {
		int id, val;
		cin >> id >> val;
		id--;
		st.set(id, S{val, 0});

		cout << st.prod(0, 1ll << n).v << '\n';
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

