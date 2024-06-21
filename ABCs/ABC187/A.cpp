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
	int a, b, sma = 0, smb = 0;
	cin >> a >> b;
	string aa = to_string(a);
	string bb = to_string(b);

	for (int i = 0; i < aa.size(); i++) {
		sma += aa[i] - '0';
	}


	for (int i = 0; i < bb.size(); i++) {
		smb += bb[i] - '0';
	}

	cout << max(sma, smb) << '\n';
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
