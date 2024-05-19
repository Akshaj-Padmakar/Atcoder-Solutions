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
*> Straightforward Implmentation.

*/

void solve() {
	int n;
	cin >> n;
	string t;
	cin >> t;

	vector<int> ans;
	for (int k = 0; k < n; k++) {
		string s; cin >> s;

		if (s == t) {
			//equal
			ans.push_back(k + 1);
		} else {
			if (s.size() == t.size()) {
				//replaced char
				int c = 0;
				for (int i = 0; i < s.size(); i++) {
					if (s[i] != t[i]) {
						c++;
					}
				}
				if (c == 1) {
					ans.push_back(k + 1);
				}
			} else if (s.size() == t.size() + 1) {
				//Deleted a char
				int i = 0, j = 0, c = 0;
				while (1) {
					if (i >= s.size() || j >= t.size()) {
						break;
					}
					if (s[i] == t[j]) {
						//ok
						i++, j++;
					} else {
						i++;
						c++;
					}
				}

				if (c <= 1) {
					ans.push_back(k + 1);
				}
			} else if (s.size() + 1 == t.size()) {
				//Inserted a new char
				int i = 0, j = 0, c = 0;
				while (1) {
					if (i >= s.size() || j >= t.size()) {
						break;
					}
					if (s[i] == t[j]) {
						//ok
						i++, j++;
					} else {
						j++;
						c++;
					}
				}

				if (c <= 1) {
					ans.push_back(k + 1);
				}
			}
		}
	}


	cout << ans.size() << "\n";
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

