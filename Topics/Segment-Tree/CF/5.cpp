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
https://codeforces.com/contest/380/problem/C
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
	int b;
	int l;
	int r;
};

S op(S a, S b) {
	int bb = min(a.l, b.r);
	return S{a.b + b.b + bb, a.l + b.l - bb, a.r + b.r - bb};
}

S e() { return S{0, 0, 0}; }

void solve() {
	string s;
	cin >> s;
	int n = s.size();
	vector<S> dum(n);
	for (int i = 0; i < n; i++) {
		if (s[i] == '(') {
			dum[i] = S{0, 1, 0};
		} else {
			dum[i] = S{0, 0, 1};
		}
	}

	segtree<S, op, e> st(dum);
	int q;
	cin >> q;
	// think bout range update -> ez right ?

	while (q--) {
		int l, r;
		cin >> l >> r;
		l--, r--;
		cout << 2 * st.prod(l, r + 1).b << '\n';
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

