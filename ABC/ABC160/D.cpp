#include <bits/stdc++.h>
using namespace std;

#ifndef ONLINE_JUDGE
#include "algo/debug.h"
#define debug(x...) cerr << "[" << #x << "] = ["; _print(x)
#else
#define debug(x...)
#endif

#define int long long

const int INF = 1e9;

void solve() {
	int n, x, y;
	cin >> n >> x >> y;

	vector<vector<int>> g(n + 1);
	for (int i = 1; i < n; i++) {
		g[i + 1].push_back(i);
		g[i].push_back(i + 1);
	}
	g[x].push_back(y);
	g[y].push_back(x);

	vector<int> ans(n + 1, 0);

	for (int i = 1; i <= n; i++) {
		queue<int> q;
		vector<int> dis(n + 1, INF);
		dis[i] = 0;
		q.push(i);
		while (q.size()) {
			int node = q.front();
			q.pop();

			for (auto ch : g[node]) {
				if (dis[ch] > dis[node] + 1) {
					dis[ch] = dis[node] + 1;
					q.push(ch);
				}
			}
		}

		for (int j = 1; j <= n; j++) {
			ans[dis[j]]++;
		}
	}


	for (int i = 1; i <= n - 1; i++) {
		cout << ans[i] / 2 << "\n";
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

