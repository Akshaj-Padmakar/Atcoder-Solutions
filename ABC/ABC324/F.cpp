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
*> So a very interesting binary search problem, we try to bs on the answer here.
*> Let's say atleast md is the answer.
*> sum(b[i])/sum(c[i]) >= md, sum is evaluated over a path from 1 - n.
*> sum(b[i])-md*sum(c[i]) >= 0 -> we can push the md inside
*> each edge have weight b-md*c, and we try to find the max weight path from 1 to n.
*> we note from the conditions the graph is a dag, for all edge u<v for u->v
*> Simpler ways exist due this constraint, but the generic one being dp over top sort!
*> final check being dp[n-1] >= 0  -> atleast `md` could be the solution. which inturn satisfy bs predicate properties.


*> Can we solve this for a NON-DAG graph ?
*> Case 1 : there exist atleast 1 DAG with +ve cycle s.t it is reachable from node 1
            => md could be a solution.

*> Case 2 : no +ve cycle DAG exist => hmmm ??
*/
const long double eps = 1e-10;
const int INF = 1e9;
void solve() {
	int n, m;
	cin >> n >> m;

	vector<pair<pair<int, int>, pair<int, int>>> e;
	for (int i = 0, u, v, b, c; i < m; i++) {
		cin >> u >> v >> b >> c;
		u--, v--;

		e.push_back({{u, v}, {b, c}});
	}

	long double l = 0, r = 1e4;

	auto check = [&](long double md) {
		/*
		sum(b[i])-sum(c[i])*md >= 0 => there exist a path with atleast md as answer, EZ !
		*/

		vector<vector<pair<int, long double>>> g(n), rg(n);
		vector<int> in(n, 0);

		for (int i = 0; i < m; i++) {
			auto [u, v] = e[i].first;
			auto [b, c] = e[i].second;

			g[u].push_back({v, b - md * c}); // u->v
			rg[v].push_back({u, b - md * c}); // v->u

			in[v]++;
		}

		// Given to us is a DAG ! Ez to solve the max path problem then !

		queue<int> q;
		for (int i = 0; i < n; i++) {
			if (in[i] == 0) {
				q.push(i);
			}
		}

		vector<int> tp;
		while (q.size()) {
			auto node = q.front();
			q.pop();

			tp.push_back(node);

			for (auto &[ch, w] : g[node]) {
				in[ch]--;
				if (in[ch] == 0) {
					q.push(ch);
				}
			}
		}


		vector<long double> dp(n + 1, -INF); // dp[i] = the maximum length of the path traversed to reach the i-th node.

		dp[0] = 0;
		for (int i = 0; i < tp.size(); i++) {
			int node = tp[i];
			for (auto &[ch, w] : rg[node]) {
				dp[node] = max(dp[node], dp[ch] + w);
			}
		}

		return dp[n - 1] >= 0;

	};
	while (r - l > eps) {
		long double md = (r + l) / 2.;

		if (check(md)) {
			l = md;
		} else {
			r = md;
		}
	}


	cout << setprecision(10) << fixed << (check(r) ? r : l) << "\n";
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

