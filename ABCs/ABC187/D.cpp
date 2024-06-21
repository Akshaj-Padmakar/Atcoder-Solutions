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
*> Notes:
*> For sure this is hard, but we can reason out
*> How much profit I get if i give a speeach in a state ?
*> from -a.first to a.first + a.second -> sort on this delta !
*/
bool cmp(pair<int, int> &a, pair<int, int> &b) {
	int sma = 2 * a.first + a.second;
	int smb = 2 * b.first + b.second;
	return sma > smb;
}
void solve() {
	int n;
	cin >> n;
	vector<pair<int, int>> v(n);
	for (auto &[x, y] : v) {
		cin >> x >> y;
	}

	sort(v.begin(), v.end(), cmp);
	debug(v);

	vector<int> psmab(n, 0), ssma(n, 0);

	for (int i = 0; i < n; i++) {
		psmab[i] = (i > 0 ? psmab[i - 1] : 0) + v[i].first + v[i].second;
	}


	for (int i = n - 1; i >= 0; i--) {
		ssma[i] = (i < n - 1 ? ssma[i + 1] : 0) + v[i].first;
	}


	for (int i = 0; i + 1 < n; i++) {
		if (psmab[i] > ssma[i + 1]) {
			cout << i + 1 << '\n'; return;
		}
	}

	cout << n << '\n';

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
