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
*> Super interesting proble, OOLs and recurring same state in dp ?

*>dp[i][j][k] -> stores the expected no. of roll die to eat i plate of 1 sushi, j 2 suhsi, k 3 sushi.

*> Recurrance :
   dp[i][j][k] = 1 + dp[i][j+1][k-1]*(k/n) + dp[i+1][j-1][k]*(j/n) + dp[i-1][j][k]*(i/n) + dp[i][j][k]*(1-({i+j+k}/n))

   dp[i][j][k]*{i+j+k}/n = 1 + dp[i][j+1][k-1]*(k/n) + dp[i+1][j-1][k]*(j/n) + dp[i-1][j][k]*(i/n)

   dp[i][j][k] =n/{i+j+k} +  dp[i][j+1][k-1]*(k/{i+j+k}) + dp[i+1][j-1][k]*(j/{i+j+k}) + dp[i-1][j][k]*(i/{i+j+k})

	i,j,k -> i,j+1,k-1 ; i+1,j-1,k ; i-1,j,k

*> Order of loops ?
	-k increasing => i,j,k -> i+1,j-1,k ; i-1,j,k
	-j increasing => i,j,k -> i-1,j,k
	-i increasing !

*> Note that here only 1 order of loops is correct, writing iterative loops in any other way wont solve the problem!!
*/
void solve() {
	int n;
	cin >> n;
	vector<int> a(n), cnt(4, 0);

	for (auto &x : a) {
		cin >> x;
		cnt[x]++;
	}

	vector<vector<vector<long double>>> dp(n + 1, vector<vector<long double>>(n + 1, vector<long double>(n + 1, 0)));

	dp[0][0][0] = 0;
	for (int k = 0; k <= n; k++) {
		for (int j = 0; j <= n; j++) {
			for (int i = 0; i <= n; i++) {
				if (i + j + k == 0 || (i + j + k) > n)continue;

				long double p1 = (1.*n) / (i + j + k);
				long double p2 = (1.*k) / (i + j + k);
				long double p3 = (1.*j) / (i + j + k);
				long double p4 = (1.*i) / (i + j + k);

				dp[i][j][k] = p1 + (k > 0 ? p2 * dp[i][j + 1][k - 1] : 0) + (j > 0 ? p3 * dp[i + 1][j - 1][k] : 0) + (i > 0 ? p4 * dp[i - 1][j][k] : 0);
			}
		}
	}

	cout << fixed << setprecision(10) << dp[cnt[1]][cnt[2]][cnt[3]] << "\n";

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

