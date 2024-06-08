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
*> Just an observation based problem.

*> If a node is part of cycle, it can reach only nodes of cycle.
*> O.W node is attached to the cycle node ---> cycle
*> So all the nodes in the path way and then all nodes of cycle. [do this cal on reverse graph.]
*/
void solve() {
	int n;
	cin >> n;

	vector<vector<int>> g(n), rg(n);
	vector<int> in(n, 0);
	for (int i = 0, x; i < n; i++) {
		cin >> x;
		x--;

		g[i].push_back(x);
		rg[x].push_back(i);
		in[x]++;
	}

	queue<int> q;
	for (int i = 0; i < n; i++) {
		if (in[i] == 0) {
			q.push(i);
		}
	}

	while (q.size()) {
		int x = q.front();
		q.pop();

		for (auto ch : g[x]) {
			in[ch]--;
			if (in[ch] == 0) {
				q.push(ch);
			}
		}
	}
	set<int> s;
	for (int i = 0; i < n; i++) {
		if (in[i] > 0) {
			s.insert(i);//part of cy
		}
	}



	vector<int> cur;
	vector<int> vis(n);
	vector<int> dis(n, 0);
	int sz = 0;
	function<void(int, int)> dfs = [&](int node, int d) {
		cur.push_back(node);
		vis[node] = 1;
		dis[node] = d;
		if (s.find(node) != s.end()) {
			sz++;
		}
		for (auto ch : rg[node]) {
			if (!vis[ch]) {
				int f = 0;
				if (s.find(ch) == s.end()) {
					f = 1;
				}

				dfs(ch, d + f);
			}
		}
	};


	for (auto &x : s) {
		if (!vis[x]) {
			cur.clear();
			sz = 0;
			dfs(x, 0);
			debug(s, cur, rg, x);

			for (auto &y : cur) {
				dis[y] += sz;
			}
		}
	}
	int ans = 0;
	for (auto &x : dis) {
		ans += x;
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

