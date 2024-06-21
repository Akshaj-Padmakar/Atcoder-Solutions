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
*> Bruh fuck no, How do I not know this :

-> |s|+|t| = max(|s+t|, |s-t|)
*/
bool cmp0(pair<int, int> &a, pair<int, int>&b) {
	return a.first + a.second <= b.first + b.second;
}

bool cmp1(pair<int, int> &a, pair<int, int>&b) {
	return a.first - a.second <= b.first - b.second;
}
void solve() {
	int n;
	cin >> n;
	vector<pair<int, int>> v0, v1;

	for (int i = 0, x, y; i < n; i++) {
		cin >> x >> y;
		if ((x + y) % 2) {
			v1.push_back({x, y});
		} else {
			v0.push_back({x, y});
		}
	}
	sort(v0.begin(), v0.end(), cmp0);
	vector<int> ssm(v0.size(), 0);
	for (int i = v0.size() - 1; i >= 0; i--) {
		auto [x, y] = v0[i];
		ssm[i] = (i + 1 == v0.size() ? 0 : ssm[i + 1]) + x + y;
	}
	int ans = 0;
	for (int i = 0; i < v0.size(); i++) {
		auto [x, y] = v0[i];
		ans += ssm[i] - (x + y) * (v0.size() - i);
	}


	sort(v0.begin(), v0.end(), cmp1);
	// vector<int> ssm(v0.size(), 0);
	for (int i = v0.size() - 1; i >= 0; i--) {
		auto [x, y] = v0[i];
		ssm[i] = (i + 1 == v0.size() ? 0 : ssm[i + 1]) + (x - y);
	}
	for (int i = 0; i < v0.size(); i++) {
		auto [x, y] = v0[i];
		ans += ssm[i] - (x - y) * (v0.size() - i);
	}




	sort(v1.begin(), v1.end(), cmp0);
	vector<int> ssm1(v1.size(), 0);
	for (int i = v1.size() - 1; i >= 0; i--) {
		auto [x, y] = v1[i];
		ssm1[i] = (i + 1 == v1.size() ? 0 : ssm1[i + 1]) + x + y;
	}
	for (int i = 0; i < v1.size(); i++) {
		auto [x, y] = v1[i];
		ans += ssm1[i] - (x + y) * (v1.size() - i);
	}

	sort(v1.begin(), v1.end(), cmp1);
	// vector<int> ssm1(v1.size(), 0);
	for (int i = v1.size() - 1; i >= 0; i--) {
		auto [x, y] = v1[i];
		ssm1[i] = (i + 1 == v1.size() ? 0 : ssm1[i + 1]) + (x - y);
	}
	for (int i = 0; i < v1.size(); i++) {
		auto [x, y] = v1[i];
		ans += ssm1[i] - (x - y) * (v1.size() - i);
	}

	cout << ans / 2 << '\n';
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
