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
*> Comparator sorting practice ez.
*/
bool cmp(pair<pair<string, int>, int> a, pair<pair<string, int>, int>b) {
	return (a.first.first == b.first.first ? a.first.second > b.first.second : a.first.first < b.first.first);
}
void solve() {
	int n;
	cin >> n;

	vector<pair<pair<string, int>, int>> v;

	for (int i = 0; i < n; i++) {
		string s;
		int x;
		cin >> s >> x;

		v.push_back({{s, x}, i});
	}

	sort(v.begin(), v.end(), cmp);

	for (auto x : v) {
		cout << x.second + 1 << "\n";
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

