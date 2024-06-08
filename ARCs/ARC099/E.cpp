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
*> A very awesome problem, not that hard tho !

*> all nodes are directly connected via edge of same city -> in complment no node of same color are connected by edge

*> complement -> bipartite coloring -> now which city should be paired with each other in different connected component.

*> col0 -> a1 a2 .. an
   col1 -> b1 b2 .. bn

   A = a1 b2 a3 ..
   B = b1 a2 b3 ..

   min(sum of 2 taken at a time of A + B) -> value ?
    => KNAPSACK ! how ? make correct formula !
*/
void solve() {
	int n, m;
	cin >> n >> m;

	vector<vector<int>> g(n), cg(n), ce(n, vector<int>(n, true));
	for (int i = 0, a, b; i < m; i++) {
		cin >> a >> b; a--, b--;
		g[a].push_back(b);
		g[b].push_back(a);

		ce[a][b] = false;
		ce[b][a] = false;

	}
	for (int i = 0; i < n; i++) {
		for (int j = i + 1; j < n; j++) {
			if (ce[i][j]) {
				cg[i].push_back(j);
				cg[j].push_back(i);
			}
		}
	}
	vector<int> col(n, 0), vis(n, false);
	vector<pair<int, int>> cnt;
	int c0 = 0, c1 = 0;
	function<bool(int, int)> dfs = [&](int node, int c) {
		vis[node] = 1;
		col[node] = c;

		(c == 0 ? c0++ : c1++);

		for (auto ch : cg[node]) {
			if (!vis[ch]) {
				if (!dfs(ch, c ^ 1)) {
					return false;
				}
			} else {
				if (col[node] == col[ch]) {
					return false;
				}
			}
		}
		return true;
	};


	for (int i = 0; i < n; i++) {
		if (!vis[i]) {
			c0 = 0, c1 = 0;
			if (!dfs(i, 0)) {
				cout << -1 << '\n';
				return;
			}
			cnt.push_back({c0, c1});
		}
	}

	/*
	a1 a2 a3 .. an
	b1 b2 b3 .. bn

	A = a1 b2 a3 ..
	B = b1 a2 b3 ..


	min(sum of 2 taken at a time of A + B) -> value ?

	(x1+x2+..xn)^2 = x1^2.. + 2*(sum of )

	A[i]*A[i]


	-----------------------------------------------------------------------------------
	min{(a1+..an +b1 .. bn)^2 - {a1^2 .. an^2 + b1^2 .. bn^2} - 2*sum(A) * sum(B)}/2 !!

	max{sum(A)*sum(B)}

	dp[i][j] -> sum(A)= j is it possible ?
	*/

	// sort(cnt.begin(), cnt.end(), greater<pair<int, int>>());

	int ans = 0;
	int s = 0;

	for (int i = 0; i < cnt.size(); i++) {
		s += cnt[i].first + cnt[i].second;
	}

	ans = s * s;

	for (int i = 0; i < cnt.size(); i++) {
		ans -= cnt[i].first * cnt[i].first + cnt[i].second * cnt[i].second;
	}


	vector<vector<bool>> dp(cnt.size(), vector<bool>(n + 1, false));
	// dp[i][j] -> can we make a sum of j from the first i elements.

	dp[0][cnt[0].first] = 1;
	dp[0][cnt[0].second] = 1;


	for (int i = 1; i < cnt.size(); i++) {
		auto [s, t] = cnt[i];
		for (int j = 0; j <= n; j++) {
			if (j >= s && dp[i - 1][j - s]) {
				dp[i][j] = 1;
			}

			if (j >= t && dp[i - 1][j - t]) {
				dp[i][j] = 1;
			}
		}
	}

	int mx = -1;
	for (int j = 0; j < n + 1; j++) {
		if (dp.back()[j]) {
			mx = max(mx, 2 * j * (s - j));
		}
	}
	ans -= mx;
	ans /= 2;
	auto c2 = [&](int x) {
		return x * (x - 1) / 2;
	};

	for (auto [s, t] : cnt) {
		ans += c2(s) + c2(t);
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

