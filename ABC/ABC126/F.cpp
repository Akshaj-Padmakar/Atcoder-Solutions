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
*> Claim : The main obs. here is that 0^1^....^(pow(2,n-1)-1) = 0 , n >= 2. {Very easy to proof.}

*> Other side cases such as k >= pow(2,m) could be formed.
*> x0 x1 ... xk-1 k xk-1 ... x0 k
Such a sequence works using the above claim, but there is a triaval case of (n==1) that is not dealt here.
*/

void solve() {
	int m, k;
	cin >> m >> k;

	if (k >= 1ll << m) {
		cout << "-1\n";
	} else if (k == 0) {
		for (int i = 0; i < (1ll << m); i++) {
			cout << i << ' ' << i << ' ';
		}
		cout << "\n";
	} else if (m == 1) {
		cout << "-1\n";
	} else {
		for (int i = 0; i < (1ll << m); i++) {
			if (i == k) {
				continue;
			}
			cout << i << " ";
		}
		cout << k << " ";


		for (int i = (1ll << m) - 1; i >= 0; i--) {
			if (i == k) {
				continue;
			}
			cout << i << " ";
		}
		cout << k << " ";

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


