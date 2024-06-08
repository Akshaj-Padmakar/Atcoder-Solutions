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
*> CANCER PROBLEM -> CANCER IMPLEMENTATION
*/

void solve() {
	int n;
	cin >> n;
	int sz = 1;
	vector<int>pw(n + 1, 1);
	for (int i = 0; i < n; i++) {
		sz *= 3ll;
		pw[i + 1] = sz;

	}
	vector<vector<char>> a(sz, vector<char>(sz));

	function<void(pair<int, int>, pair<int, int>, int)> dfs = [&](pair<int, int>l, pair<int, int>r, int k) {
		if (k == 0) {
			a[l.first][l.second] = '#';
			return;
		}

		auto [lux, luy] = l;
		// auto [rdx, rdy] = r;

		for (int i = 0; i < pw[k - 1]; i++) {
			for (int j = 0; j < pw[k - 1]; j++) {
				a[lux + pw[k - 1] + i][luy + pw[k - 1] + j] = '.';
			}
		}

		dfs({lux, luy}, {lux + pw[k - 1] - 1, luy + pw[k - 1] - 1}, k - 1);

		dfs({lux + pw[k - 1], luy}, {lux + 2 * pw[k - 1] - 1, luy + pw[k - 1] + 1}, k - 1);

		dfs({lux + 2 * pw[k - 1], luy}, {lux + 3 * pw[k - 1] - 1, luy + pw[k - 1] + 1}, k - 1);

		int z1 = lux;
		int z2 = luy + 2 * pw[k - 1];

		swap(z1, lux);
		swap(z2, luy);


		dfs({lux, luy}, {lux + pw[k - 1] - 1, luy + pw[k - 1] - 1}, k - 1);

		dfs({lux + pw[k - 1], luy}, {lux + 2 * pw[k - 1] - 1, luy + pw[k - 1] + 1}, k - 1);

		dfs({lux + 2 * pw[k - 1], luy}, {lux + 3 * pw[k - 1] - 1, luy + pw[k - 1] + 1}, k - 1);

		swap(z1, lux);
		swap(z2, luy);

		dfs({lux, luy + pw[k - 1]}, {lux + pw[k - 1] - 1, luy + 2 * pw[k - 1] - 1}, k - 1);


		z1 = lux + 2 * pw[k - 1];;
		z2 = luy;

		swap(z1, lux);
		swap(z2, luy);

		dfs({lux, luy + pw[k - 1]}, {lux + pw[k - 1] - 1, luy + 2 * pw[k - 1] - 1}, k - 1);
	};

	dfs({0, 0}, {sz - 1, sz - 1}, n);

	for (auto &x : a) {
		for (auto &y : x) {
			cout << y;
		}
		cout << "\n";
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

