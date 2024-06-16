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
Theorem -> Any cc of the clique will be enough !
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

	vector<pair<int, pair<int, int>>> e;
	for (int i = 0, k, c; i < m; i++) {
		cin >> k >> c;
		vector<int> a;
		for (int j = 0, x; j < k; j++) {
			cin >> x;
			x--;
			a.push_back(x);
		}

		for (int j = 1; j < k; j++) {
			e.push_back({c, {a[0], a[j]}});
		}
	}

	sort(e.begin(), e.end());

	dsu ds(n);

	int ans = 0;
	for (auto [w, x] : e) {
		if (ds.same(x.first, x.second)) {
			continue;
		}
		ds.merge(x.first, x.second);
		ans += w;
	}

	vector<vector<int>> g;
	ds.groups(g);

	cout << (g.size() == 1 ? ans : -1);

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

