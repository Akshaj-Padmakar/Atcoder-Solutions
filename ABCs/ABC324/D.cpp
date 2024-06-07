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
*> So there are very less [countable] no of square no. till 13 digits. {~4e6}
*> Now we just need to compare the frequency of digits of any i-th square no. and s
*> if equal we found a permutation !
*> O.W the only case could be all 0's in the beginning.
*/

void solve() {
	vector<string> v;
	for (int i = 0; i < 4e6; i++) {
		int i2 = i * i;
		v.push_back(to_string(i2));
	}

	int n;
	cin >> n;
	string s;
	cin >> s;


	vector<int> hsh2(10, 0);
	for (auto &x : s) {
		hsh2[x - '0']++;
	}
	int ans = 0;
	for (int i = 0; i < v.size(); i++) {
		if (v[i].size() <= n) {
			//ok
			vector<int> hsh1(10, 0);
			for (auto &x : v[i]) {
				hsh1[x - '0']++;
			}

			if (hsh1 == hsh2) {
				//equal
				ans++;
			} else {
				if (v[i].size() < n) {
					//append 0s in front.
					bool ok = 1;
					for (int j = 1; j < 10; j++) {
						if (hsh1[j] != hsh2[j]) {
							ok = false;
						}
					}
					ans += ok;
				}
			}
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

