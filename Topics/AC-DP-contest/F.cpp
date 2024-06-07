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
*> Just a length problem, try to solve the problem on the prefix of s and t.
*> dp[i][j], also keep choice[i][j] to backtrack the subsequence at the end.
*/

void solve() {
	string s, t;
	cin >> s >> t;

	int a = s.size();
	int b = t.size();

	vector<vector<int>> dp(a + 1, vector<int>(b + 1, 0ll));
	//dp[i][j] length of the longest common subsequnece in the prefix of [0..i] and [0..j] of s and t

	vector<vector<int>> choice(a + 1, vector<int>(b + 1, 1));
	// choice[i][j]-> dont take i of string s(1) or dont take j of string t(2) or take i,j (3)

	if (s[0] == t[0]) {
		dp[0][0] = 1;
		choice[0][0] = 3;
	}

	for (int i = 0; i < a; i++) {
		for (int j = 0; j < b; j++) {
			if (i) {
				if (dp[i][j] < dp[i - 1][j]) {
					dp[i][j] = dp[i - 1][j];
					choice[i][j] = 1;
				}
			}

			if (j) {
				if (dp[i][j] < dp[i][j - 1]) {
					dp[i][j] = dp[i][j - 1];
					choice[i][j] = 2;
				}
			}


			if (s[i] == t[j]) {
				dp[i][j] = max(dp[i][j], 1 + (i > 0 && j > 0 ? dp[i - 1][j - 1] : 0));
				choice[i][j] = 3;
			}
		}
	}

	string ans;
	int i = a - 1, j = b - 1;
	while (i >= 0 && j >= 0) {
		if (choice[i][j] == 1) {
			i--;
		} else if (choice[i][j] == 2) {
			j--;
		} else {
			ans.push_back(s[i]);
			i--, j--;
		}
	}
	reverse(ans.begin(), ans.end());

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

