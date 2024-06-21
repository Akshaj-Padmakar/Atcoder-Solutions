#include <bits/stdc++.h>
using namespace std;

#ifndef ONLINE_JUDGE
#include "algo/debug.h"
#define debug(x...) cerr << "[" << #x << "] = ["; _print(x)
#else
#define debug(x...)
#endif

#define int long long


void solve() {
	int n;
	cin >> n;
	vector<string> s(n), pos;

	for (auto &x : s) {
		cin >> x;
		if (x[0] != '!') {
			pos.push_back(x);
		}
	}

	sort(s.begin(), s.end());
	for (int i = 0; i < pos.size(); i++) {
		string ne = '!' + pos[i];
		if (binary_search(s.begin(), s.end(), pos[i]) && binary_search(s.begin(), s.end(), ne)) {
			cout << pos[i] << '\n';
			return;
		}
	}
	cout << "satisfiable\n";
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
