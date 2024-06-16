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
*> A very interesting problem ! So obv all the nodes with a relation (A->x)-(B->y)=x are connected.
*> A rank in a cc -> determines all the ranks in that cc.
*> If I can subsitute j and k to the head of that cc -> the answer is -1 or else it has a strict single answer for that cc
*> But How do i check that after replacing i on cc, the rest form a valid ranking ?
*> consider msk = set of i's left ->

   dp[j-1][msk] = first j-1 cc considered, and msk set of no.s used on the rank

   mskI = used while placing i on the head of jth cc.
   consider msk used on j-1 cc
   (2^n-1) ^ msk ^ mskI is used for cc from j+1 onwards.

   so maintain a dp in both forward and backward direction !
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
	vector<vector<pair<int, int>>> g(n), rg(n);
	vector<int> in(n, 0);

	dsu ds(n);

	for (int i = 0, a, b, c; i < m; i++) {
		cin >> a >> b >> c;
		a--, b--;
		g[a].push_back({b, -c});
		g[b].push_back({a, c});

		ds.merge(a, b);
	}
	vector<int> bc;//base case
	vector<vector<int>> grp;
	ds.groups(grp);
	for (int i = 0; i < grp.size(); i++) {
		bc.push_back(grp[i][0]);
	}


	bool ok = true;
	int mx = 0;
	vector<int> vis(n, -1);
	function<void(int, int, int)> dfs = [&](int node, int cur, int msk) {
		mx += (1ll << cur);
		vis[node] = cur;

		for (auto [ch, w] : g[node]) {
			if (vis[ch] != -1) {
				if (vis[node] + w == vis[ch]) {
					//ok
				} else {
					ok = false;
					return;
				}
			} else {
				int nxt = w + vis[node];

				if ((nxt >= n) || (nxt < 0)) {
					ok = false;
					return;
				} else {
					if (msk & (1ll << nxt)) {
						// nxt bit is on
						ok = false;
						return;
					} else {
						dfs(ch, nxt, msk ^ (1ll << nxt));
					}
				}

			}
		}
	};

	int sz = bc.size();
	vector<vector<int>> val(sz, vector<int>(n, -1));
	//val[i][j] -> msk created if we assign j to ith cc.


	for (int i = 0; i < sz; i++) {
		for (int j = 0; j < n; j++) {
			ok = true;
			mx = 0;
			for (int k = 0; k < n; k++) {
				vis[k] = -1;
			}
			dfs(bc[i], j, (1ll << j));
			if (ok) {
				val[i][j] = mx;
			}
		}
	}


	vector<vector<int>> dp(sz, vector<int>((1ll << n), 0));
	//dp[i][msk]-> true/false, can we distribute msk set on first i cc.
	for (int j = 0; j < n; j++) {
		if (val[0][j] != -1) {
			// we can distribute val[0][j] on the 0th cc;
			int msk = val[0][j];
			dp[0][msk] = 1;
		}
	}

	for (int i = 1; i < sz; i++) {
		for (int msk = 0; msk < (1ll << n); msk++) {
			for (int j = 0; j < n; j++) {
				int cur = val[i][j];
				if (cur != -1) {
					// then we can use cur set on the ith cc.

					if ((cur & msk) == cur) {
						// then only its fine
						dp[i][msk] = max(dp[i][msk], dp[i - 1][cur ^ msk]);
					}
				}
			}
		}
	}



	vector<vector<int>> rdp(sz, vector<int>((1ll << n), 0));

	for (int j = 0; j < n; j++) {
		if (val[sz - 1][j] != -1) {
			int msk = val[sz - 1][j];
			rdp[sz - 1][msk] = 1;
		}
	}

	for (int i = sz - 2; i >= 0; i--) {
		for (int msk = 0; msk < (1ll << n); msk++) {
			for (int j = 0; j < n; j++) {
				int cur = val[i][j];
				if (cur != -1) {
					// then we can use cur set on the ith cc.

					if ((cur & msk) == cur) {
						// then only its fine
						rdp[i][msk] = max(rdp[i][msk], rdp[i + 1][cur ^ msk]);
					}
				}
			}
		}
	}

	vector<int> vals(n, -1);
	function<void(int, int)> dfsv = [&](int node, int cur) {
		vals[node] = cur;
		for (auto [ch, w] : g[node]) {
			if (vals[ch] == -1) {
				dfsv(ch, cur + w);
			}
		}
	};


	vector<int> ans(n, 0);

	for (int i = 0; i < sz; i++) {
		set<int> vv;
		for (int j = 0; j < n; j++) {
			int msk = val[i][j];

			if (i == 0) {
				if (msk != -1) {
					int forw = msk ^ ((1ll << n) - 1);
					if (i + 1 == sz) {
						if (forw == 0) {
							vv.insert(j);
						}
					} else if (rdp[i + 1][forw]) {
						//good
						vv.insert(j);

					}
				}
			} else if (msk != -1) {
				for (int prev = 0; prev < (1ll << n); prev++) {
					if ((msk & prev) == 0) {
						if (dp[i - 1][prev]) {
							int forw = ((1ll << n) - 1) ^ (msk ^ prev);
							if (i + 1 == sz) {
								if (forw == 0) {
									//ok
									vv.insert(j);

								}

							} else if (rdp[i + 1][forw]) {
								vv.insert(j);
							}
						}

					}
				}
			}
		}

		if (vv.size() > 1) {
			for (int j = 0; j < grp[i].size(); j++) {
				int node = grp[i][j];
				ans[node] = -2;
			}
		} else {
			dfsv(grp[i][0], *vv.begin());
			for (int j = 0; j < grp[i].size(); j++) {
				int node = grp[i][j];
				ans[node] = vals[node];
			}
		}
	}


	for (auto &x : ans) {
		cout << x + 1 << ' ';
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

