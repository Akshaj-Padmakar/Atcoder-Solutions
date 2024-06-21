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
*> Notes:
*> Have solved similar problems
*/
template <class S, S (*op)(S, S), S (*e)(), class F, S (*mapping)(F, S), F (*composition)(F, F), F (*id)()> struct lazy_segtree {
public:
	lazy_segtree() : lazy_segtree(0) {}

	lazy_segtree(int n) : lazy_segtree(vector<S>(n, e())) {}

	lazy_segtree(const vector<S>& v) : _n((v.size())) {
		log = ceil(log2(_n));
		size = 1 << log;

		d = vector<S>(2 * size, e());
		lz = vector<F>(size, id());

		for (int i = 0; i < _n; i++) {
			d[size + i] = v[i];
		}

		for (int i = size - 1; i >= 1; i--) {
			update(i);
		}
	}

	void set(int p, S x) {
		assert(0 <= p && p < _n);

		p += size;
		for (int i = log; i >= 1; i--) {
			push(p >> i);
		}

		d[p] = x;

		for (int i = 1; i <= log; i++) {
			update(p >> i);
		}
	}

	S get(int p) {
		assert(0 <= p && p < _n);

		p += size;
		for (int i = log; i >= 1; i--) {
			push(p >> i);
		}
		return d[p];
	}

	S prod(int l, int r) {
		assert(0 <= l && l <= r && r <= _n);

		if (l == r) return e();

		l += size;
		r += size;

		for (int i = log; i >= 1; i--) {
			if (((l >> i) << i) != l) push(l >> i);
			if (((r >> i) << i) != r) push(r >> i);
		}

		S sml = e(), smr = e();
		while (l < r) {
			if (l & 1) sml = op(sml, d[l++]);
			if (r & 1) smr = op(d[--r], smr);
			l >>= 1;
			r >>= 1;
		}

		return op(sml, smr);
	}

	S all_prod() { return d[1]; }

	void apply(int p, F f) {
		assert(0 <= p && p < _n);

		p += size;
		for (int i = log; i >= 1; i--) {
			push(p >> i);
		}

		d[p] = mapping(f, d[p]);

		for (int i = 1; i <= log; i++) {
			update(p >> i);
		}
	}
	void apply(int l, int r, F f) {
		assert(0 <= l && l <= r && r <= _n);

		if (l == r) return;

		l += size;
		r += size;

		for (int i = log; i >= 1; i--) {
			if (((l >> i) << i) != l) push(l >> i);
			if (((r >> i) << i) != r) push((r - 1) >> i);
		}

		{
			int l2 = l, r2 = r;
			while (l < r) {
				if (l & 1) all_apply(l++, f);
				if (r & 1) all_apply(--r, f);
				l >>= 1;
				r >>= 1;
			}
			l = l2;
			r = r2;
		}

		for (int i = 1; i <= log; i++) {
			if (((l >> i) << i) != l) update(l >> i);
			if (((r >> i) << i) != r) update((r - 1) >> i);
		}
	}

	template <bool (*g)(S)> int max_right(int l) {
		return max_right(l, [](S x) { return g(x); });
	}
	template <class G> int max_right(int l, G g) {
		assert(0 <= l && l <= _n);
		assert(g(e()));
		if (l == _n) return _n;
		l += size;
		for (int i = log; i >= 1; i--) push(l >> i);
		S sm = e();
		do {
			while (l % 2 == 0) l >>= 1;
			if (!g(op(sm, d[l]))) {
				while (l < size) {
					push(l);
					l = (2 * l);
					if (g(op(sm, d[l]))) {
						sm = op(sm, d[l]);
						l++;
					}
				}
				return l - size;
			}
			sm = op(sm, d[l]);
			l++;
		} while ((l & -l) != l);
		return _n;
	}

	template <bool (*g)(S)> int min_left(int r) {
		return min_left(r, [](S x) { return g(x); });
	}
	template <class G> int min_left(int r, G g) {
		assert(0 <= r && r <= _n);
		assert(g(e()));
		if (r == 0) return 0;
		r += size;
		for (int i = log; i >= 1; i--) push((r - 1) >> i);
		S sm = e();
		do {
			r--;
			while (r > 1 && (r % 2)) r >>= 1;
			if (!g(op(d[r], sm))) {
				while (r < size) {
					push(r);
					r = (2 * r + 1);
					if (g(op(d[r], sm))) {
						sm = op(d[r], sm);
						r--;
					}
				}
				return r + 1 - size;
			}
			sm = op(d[r], sm);
		} while ((r & -r) != r);
		return 0;
	}

private:
	int _n, size, log;
	vector<S> d;
	vector<F> lz;

	void update(int k) { d[k] = op(d[2 * k], d[2 * k + 1]); }
	void all_apply(int k, F f) {
		d[k] = mapping(f, d[k]);
		if (k < size) lz[k] = composition(f, lz[k]);
	}
	void push(int k) {
		all_apply(2 * k, lz[k]);
		all_apply(2 * k + 1, lz[k]);
		lz[k] = id();
	}
};

struct S {
	int cntM0;
	int cntM1;

	int cntS0;
	int cntP0;

	int cntS1;
	int cntP1;

	int size;
};

struct F {
	int b;
};

S op(S l, S r) {
	S ans;
	ans.cntM0 = max(l.cntS0 + r.cntP0, max(l.cntM0, r.cntM0));

	ans.cntM1 = max(l.cntS1 + r.cntP1, max(l.cntM1, r.cntM1));

	if (r.cntS0 == r.size) {
		// the entire range is 0(r) !
		ans.cntS0 = r.cntS0 + l.cntS0;
	} else {
		ans.cntS0 = r.cntS0;
	}


	if (r.cntS1 == r.size) {
		// the entire range is 1(r) !
		ans.cntS1 = r.cntS1 + l.cntS1;
	} else {
		ans.cntS1 = r.cntS1;
	}

	if (l.cntP0 == l.size) {
		// the entire range is 0(l) !
		ans.cntP0 = l.cntP0 + r.cntP0;
	} else {
		ans.cntP0 = l.cntP0;
	}

	if (l.cntP1 == l.size) {
		// the entire range is 1(l) !
		ans.cntP1 = l.cntP1 + r.cntP1;
	} else {
		ans.cntP1 = l.cntP1;
	}
	ans.size = l.size + r.size;
	return ans;
}

S e() {
	return S{0, 0, 0, 0, 0, 0, 0};
}

S mapping(F l, S r) {
	if (l.b % 2) {
		swap(r.cntM0, r.cntM1);
		swap(r.cntS0, r.cntS1);
		swap(r.cntP0, r.cntP1);
	}

	return r;

}

F composition(F l, F r) {
	return F{(l.b + r.b) % 2};
}

F id() { return F{0}; }

void solve() {
	int n, q;
	cin >> n >> q;

	vector<S> a(n);

	for (int i = 0; i < n; i++) {
		char c;
		cin >> c;
		int v =  c - '0';
		if (v) {
			a[i] = S{0, 1, 0, 0, 1, 1, 1};
		} else {
			a[i] = S{1, 0, 1, 1, 0, 0, 1};
		}
	}

	lazy_segtree<S, op, e, F, mapping, composition, id> st(a);

	while (q--) {
		int op, l, r;
		cin >> op >> l >> r;
		l--, r--;
		if (op == 1) {
			st.apply(l, r + 1, F{1});
		} else {
			cout << st.prod(l, r + 1).cntM1 << "\n";
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
