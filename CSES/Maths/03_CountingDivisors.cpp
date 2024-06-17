#include <bits/stdc++.h>
using namespace std;

#ifndef ONLINE_JUDGE
#include "algo/debug.h"
#define debug(x...) cerr << "[" << #x << "] = ["; _print(x)
#else
#define debug(x...)
#endif

#define int long long

const int MAXN = 1e6 + 5;

vector<int> div_set(MAXN);

void dset(int n = MAXN) {
	for (int i = 1; i < n; i++) {
		for (int j = i; j < n; j += i) {
			div_set[j]++;
		}
	}
}


void solve() {
	int q;
	cin >> q;


	while (q--) {
		int n;
		cin >> n;
		cout << div_set[n] << "\n";
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
	// cin >> t;

	dset();


	while (t--) {
		solve();
	}

	// cerr << "Time elapsed: " << ((long double)clock() / CLOCKS_PER_SEC) << " s.\n";
}