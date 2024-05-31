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
Note:
*> Such problems are kinda common on atcoder ? So for this if I know a value of a node
   in a cc(formed using edge set) we can find the values of each node, its like painting
   the cc.

*>  Variation : There could be false information, or what if values could be more than just 1 and 2 ?
*/
struct dsu {
public:
	dsu(int _n) {
		n = _n;
		par.assign(n, 0);
		sz.assign(n, 1);
		for (int i = 0; i < n; i++) {
			par[i] = i;
		}
	}

	int find(int v) {
		assert(v >= 0 && v < n);
		if (v == par[v]) {
			return v;
		}
		return par[v] = find(par[v]);
	}

	void merge(int u, int v) {
		assert(u >= 0 && u < n && v >= 0 && v < n);

		u = find(u), v = find(v);
		if (u == v) {
			return;
		}
		if (sz[u] > sz[v]) {
			swap(u, v);
		}
		par[u] = v;
		sz[v] += sz[u];
	}

	int size(int u) {
		assert(u >= 0 && u < n);
		u = find(u);
		return sz[u];
	}

	bool same(int u, int v) {
		assert(u >= 0 && u < n && v >= 0 && v < n);

		return find(u) == find(v);
	}

	void groups(vector<vector<int>> &grp) {
		vector<vector<int>> temp(n);
		for (int i = 0; i < n; i++ ) {
			temp[find(i)].push_back(i);
		}

		for (int i = 0; i < n; i++) {
			if (temp[i].size() >= 1) {
				grp.push_back(temp[i]);
			}
		}
	}

private:
	int n;
	vector<int> par, sz;
};


void solve() {
	int n, m;
	cin >> n >> m;
	dsu ds(n);

	for (int i = 0, x, y, z; i < m; i++) {
		cin >> x >> y >> z;
		x--, y--;
		ds.merge(x, y);
	}
	vector<vector<int>> grp;
	ds.groups(grp);
	cout << grp.size() << "\n";

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

