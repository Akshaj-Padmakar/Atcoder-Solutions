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
*> Pretty repeated idea, when 3 indicies are varying keep the center one constant and do operations on the other 2.
*> Rest here is simple MEX logic(like creating subarray that get some value) and STL implmentation
*/

void solve() {
	int n;
	cin >> n;
	vector<int> a(n);
	for (auto &x : a) {
		cin >> x;
	}

	string s;
	cin >> s;


	vector<string> pos = {"000", "001", "010", "100", "110", "011", "101", "012", "021", "102", "120", "201", "210", "022", "220", "202", "002", "020", "200"};
	vector<int> val = {1, 2, 2, 2, 2, 2, 2, 3, 3, 3, 3, 3, 3, 1, 1, 1, 1, 1, 1};
	int ans = 0;
	string mex = "MEX";

	for (int i = 0; i < pos.size(); i++) {
		// so now we are checking if I can create a subsequence of pos[i]

		vector<int> m, e, x;
		for (int j = 0; j < n; j++) {
			if (s[j] == 'M' && (pos[i][0] - '0') == a[j]) {
				m.push_back(j);
			} else if (s[j] == 'E' && (pos[i][1] - '0') == a[j]) {
				e.push_back(j);
			} else if ((s[j] == 'X' && (pos[i][2] - '0') == a[j])) {
				x.push_back(j);
			}
		}

		for (int j = 0; j < e.size(); j++) {
			auto it = lower_bound(m.begin(), m.end(), e[j]);
			if (it == m.begin()) {
				continue;
			}
			it--;
			int cntM = it - m.begin() + 1;
			auto it2 = upper_bound(x.begin(), x.end(), e[j]);
			int cntX = x.end() - it2;

			ans += cntX * cntM * val[i];
		}
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

