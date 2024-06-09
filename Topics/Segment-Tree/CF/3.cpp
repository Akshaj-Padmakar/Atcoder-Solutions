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
https://codeforces.com/contest/459/problem/D

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
	map<int, int> mp;
	vector<int> l(n);
	for (int i = 0; i < n; i++) {
		mp[a[i]]++;
		l[i] = mp[a[i]];
	}

	mp.clear();

	vector<int> r(n);
	for (int i = n - 1; i >= 0; i--) {
		mp[a[i]]++;
		r[i] = mp[a[i]];
	}

	segtree<int, op, e> st(n + 2);
	// can't count using set -> segtree
	for (int i = 0; i < n; i++) {
		st.set(r[i], st.get(r[i]) + 1);
	}
	int ans = 0;
	for (int i = 0; i + 1 < n; i++) {
		st.set(r[i], st.get(r[i]) - 1);
		ans += st.prod(0, l[i]);
	}

	cout << ans << "\n";

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

