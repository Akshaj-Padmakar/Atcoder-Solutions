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
	string s, t;
	cin >> s >> t;

	int j = 0;
	vector<int> ans;
	for (int i = 0; i < s.size(); i++) {
		while (j < t.size() && s[i] != t[j]) {
			//ok
			j++;
		}
		ans.push_back(j + 1);
		j++;
	}


	for (auto &x : ans) {
		cout << x << " ";
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

