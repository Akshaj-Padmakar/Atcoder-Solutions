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
/*
Notes:
*> NEW SHIT !!

*> Not much intution on how to derive this, but how does this work?
	- 3a -> 3b+1 -> 3c+2 -> 3d
	- all paths would like this, bc thats how edges are being added.

*> so if you can reach 3s -> 3t its for sure a %3==0 path
*> other than that paths for 3s+x -> 3t+x are all same.
    so => 3s+x1 -> 3t+x1 then 3s+x2 -> 3t+x2 [INF or finite!]
*/

void solve() {
	int n, m;
	cin >> n >> m;

	vector<vector<int>> g(3 * n);

	for (int i = 0, a, b; i < m; i++) {
		cin >> a >> b;
		a--, b--;
		g[3 * a].push_back(3 * b + 1);
		g[3 * a + 1].push_back(3 * b + 2);
		g[3 * a + 2].push_back(3 * b);

	}
	int s, t;
	cin >> s >> t;
	s--, t--;

	vector<int> dis(3 * n, INF);
	dis[3 * s + 1] = 0;
	queue<int> q;

	q.push(3 * s + 1);

	while (q.size()) {
		int x = q.front();
		q.pop();

		for (auto ch : g[x]) {
			if (dis[ch] > dis[x] + 1) {
				dis[ch] = dis[x] + 1;
				q.push(ch);
			}
		}
	}

	cout << (dis[3 * t + 1] == INF ? -1 : dis[3 * t + 1] / 3) << '\n';
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

