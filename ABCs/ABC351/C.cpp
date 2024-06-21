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
*> Simulation works, bc each element is pushed once and pulled once atmax.
*/
void solve() {
	int n;
	cin >> n;
	vector<int> a(n);
	for (auto &x : a) {
		cin >> x;
	}
	deque<int> dq;
	for (int i = 0; i < n; i++) {
		int cur = a[i];
		while (1) {
			if (dq.size() == 0) {
				dq.push_back(cur);
				break;
			}
			if (dq.back() == cur) {
				dq.pop_back();
				cur++;
			} else {
				dq.push_back(cur);
				break;
			}
		}
	}

	cout << dq.size() << '\n';
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
