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
*> Kind of easy, like the idea of everthing connected to 1 is, but after that,
   just adding edges between pairs, might be diff. to come up idk ? Seemed ez
*/
void solve() {
	int n, k;
	cin >> n >> k;


	if (k > ((n - 1) * (n - 2)) / 2) {
		cout << -1 << '\n';
		return;
	}

	vector<pair<int, int>> e;

	for (int i = 2; i <= n; i++) {
		e.push_back({1, i});
	}
	int cnt = ((n - 1) * (n - 2)) / 2;


	for (int i = 2; i <= n; i++) {
		for (int j = i + 1; j <= n; j++) {
			if (cnt == k) {
				break;
			}
			cnt--;
			e.push_back({i, j});

		}
	}
	cout << e.size() << '\n';
	for (auto &[a, b] : e) {
		cout << a << ' ' << b << '\n';
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

