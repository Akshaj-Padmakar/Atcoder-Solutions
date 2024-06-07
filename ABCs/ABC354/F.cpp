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
*> Since array values are not important, we do coordinate compress, probably use them as index ?
*> after coordinate compress, we create ftL and dpL
*> ftL[x = coor_compress(a[i])] = max length LIS ending at value x ! [x could exist at multiple index]
*> dpL[i] = max length LIS ending at index i.

*> We use fenwick tree for this, range query from 0 to x, to find the MAX LIS length for some y s.t y < x and index(y) < index(x)
*> range query and point update => ft or st !

*> Solve the similar problem on the negative of the reverse of the array to find the rest of the part of the LIS i.e LIS starting at index i or some value x !
*> negative as index ? use n-1-x [since 0<=x<=n-1]
*/

template <class T, T (*op)(T, T), T (*e)()>
class fenwick_tree {
public:
	fenwick_tree() : _n(0) {}

	fenwick_tree(int n) : _n(n), data(n, e()) {}

	void update(int i, T value) {
		assert(0 <= i && i < _n);
		i++;
		while (i <= _n) {
			data[i - 1] = op(data[i - 1], value);
			i += i & -i;
		}
	}

	T query(int l, int r) {
		assert(0 <= l && l <= r && r <= _n);
		return range_query(r) - range_query(l);
	}

private:
	int _n;
	std::vector<T> data;

	T range_query(int r) {
		T result = e();
		while (r > 0) {
			result = op(result, data[r - 1]);
			r -= r & -r;
		}
		return result;
	}
};

int op(int a, int b) {
	return max(a, b);
}

int e() {
	return 0;
}


void solve() {
	int n;
	cin >> n;

	vector<int>a(n);

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

	//Forward pass dp

	fenwick_tree<int, op, e> ftL(n);
	vector<int> dpL(n, 1);
	//dpL[i] -> the max length LIS ending at the index i.


	ftL.update(a[0], 1);

	for (int i = 1; i < n; i++) {
		int mxL = ftL.query(0, a[i]);
		dpL[i] = mxL + 1;
		ftL.update(a[i], dpL[i]);
	}

	vector<int>rev_neg(n);
	for (int i = 0; i < n; i++) {
		rev_neg[i] = n - 1 - a[n - 1 - i];
	}


	//Backward pass dp

	fenwick_tree<int, op, e> ftR(n);
	vector<int> dpR(n, 1);
	//dpR[i] -> the max length LIS starting from index i

	ftR.update(rev_neg[0], 1);

	for (int i = 1; i < n; i++) {
		int mxL = ftR.query(0, rev_neg[i]);
		dpR[i] = mxL + 1;
		ftR.update(rev_neg[i], dpR[i]);
	}

	reverse(dpR.begin(), dpR.end());

	int mxL = *max_element(dpL.begin(), dpL.end());
	vector<int> ans;

	for (int i = 0; i < n; i++) {
		if (dpL[i] + dpR[i] == mxL + 1) {
			ans.push_back(i + 1);
		}
	}

	cout << ans.size() << "\n";

	for (int i = 0; i < ans.size(); i++) {
		cout << ans[i] << ' ';
	}
	cout << "\n";
}

signed main() {
#ifndef ONLINE_JUDGE
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
#else
#endif
	ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);

	int t = 1;
	cin >> t;

	while (t--) {
		solve();
	}

	// cerr << "Time elapsed: " << ((long double)clock() / CLOCKS_PER_SEC) << " s.\n";
}

