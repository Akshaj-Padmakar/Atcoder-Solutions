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
*> Nothing to add here
*/

void solve() {
	string s;
	cin >> s;

	int ff = (s[0] - '0') * 10 + (s[1] - '0');
	int ss = (s[2] - '0') * 10 + (s[3] - '0');


	if (ff <= 0 || ff > 12) {
		if (ss <= 0 || ss > 12) {
			cout << "NA\n";
		} else {
			cout << "YYMM\n";
		}
	} else if (ss <= 0 || ss > 12) {
		if (ff <= 0 || ff > 12) {
			cout << "NA\n";
		} else {
			cout << "MMYY\n";
		}
	} else {
		cout << "AMBIGUOUS\n";
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

