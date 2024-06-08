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
*> https://codeforces.com/contest/937/problem/D

*> A very good problem based on the same idea !!

*> We win if we reach a node with out[x]=0.
*> But only if the path from s->x %2 = 1
*> start from 2*s reach 2*x+1, s.t out[x]=0 -> WIN.

*> DRAW ? reach a cycle !
*> O.W LOSE
*/
const int INF = 1e18;
void solve() {
	int n, m;
	cin >> n >> m;

	vector<vector<int>> g(2 * n), rg(2 * n);
	vector<int> end, in(2 * n, 0);
	for (int i = 0, sz; i < n; i++) {
		cin >> sz;
		if (sz == 0) {
			end.push_back(i);
		}
		for (int j = 0, x; j < sz; j++) {
			cin >> x;
			x--;
			g[2 * i].push_back(2 * x + 1);
			g[2 * i + 1].push_back(2 * x);

			rg[2 * x].push_back(2 * i + 1);
			rg[2 * x + 1].push_back(2 * i);

			in[2 * i + 1]++;
			in[2 * i]++;
		}
	}
	int s;
	cin >> s;
	s--;

	if (end.size() == 0) {
		cout << "Draw\n";
		return;
	}

	vector<int> dis(2 * n, INF), par(2 * n, -1);
	dis[2 * s] = 0;
	queue<int> q;
	q.push(2 * s);
	while (q.size()) {
		int x = q.front();
		q.pop();

		for (auto ch : g[x]) {
			if (dis[ch] > dis[x] + 1) {
				dis[ch] = dis[x] + 1;
				par[ch] = x;
				q.push(ch);
			}
		}
	}

	for (auto &x : end) {
		if (dis[2 * x + 1] != INF) {
			cout << "Win\n";
			vector<int> ans;
			int cur = 2 * x + 1;
			while (cur != -1) {
				ans.push_back(cur);
				cur = par[cur];
			}
			reverse(ans.begin(), ans.end());
			for (auto x : ans) {
				cout << x / 2 + 1 << " ";
			}
			cout << "\n";
			return;
		}
	}

	bool ok = false;

	for (int i = 0; i < 2 * n; ++i) {
		if (in[i] == 0) {
			q.push(i);
		}
	}


	while (!q.empty()) {
		int u = q.front();
		q.pop();

		for (int v : rg[u]) {
			in[v]--;
			if (in[v] == 0) {
				q.push(v);
			}
		}
	}

	for (int i = 1; i < 2 * n; i += 2) {
		if (in[i] > 0 && dis[i] != INF) {
			//its part of a cycle.
			ok = true;
		}
	}


	cout << (ok ? "Draw\n" : "Lose\n");
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

