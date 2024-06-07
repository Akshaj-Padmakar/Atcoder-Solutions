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
Notes :
*> Pretty classic game based DP.
*> dp[msk] = stores [0/1] if the starting player win, with msk set of cards in the game.
*> check if 2 cards have same front or back value and in the game, then it is a valid move.
*> From simple game theory logic, we know for a state to win it should have atleast one move to a losing state.
*> answer = dp[2^n-1]
*/
void solve() {
	int n;
	cin >> n;
	vector<int> a(n), b(n);
	for (int i = 0; i < n; i++) {
		cin >> a[i] >> b[i];
	}

	vector<int> dp(1ll << n, 0);
	// dp[msk] -> when we start with the state msk, then which of the players will win ?
	// dp[msk] = 0 => the player who dont start won !

	dp[0] = 0; // base case

	for (int msk = 1; msk < 1ll << n; msk++) {
		for (int i = 0; i < n; i++) {
			if (msk & 1ll << i) {
				for (int j = i + 1; j < n; j++) {
					if (msk & 1ll << j) {
						if (a[i] == a[j] || b[i] == b[j]) {
							if (!dp[msk ^ (1ll << i) ^ (1ll << j)]) {
								dp[msk] = 1;
							}
						}
					}
				}
			}
		}
	}

	cout << (dp[(1ll << n) - 1] == 1 ? "Takahashi" : "Aoki");
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

