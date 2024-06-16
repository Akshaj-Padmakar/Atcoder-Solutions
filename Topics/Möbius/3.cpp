#include <bits/stdc++.h>
using namespace std;

#ifndef ONLINE_JUDGE
#include "algo/debug.h"
#define debug(x...) cerr << "[" << #x << "] = ["; _print(x)
#else
#define debug(x...)
#endif

#define int long long

const int MAXN = 5e5 + 5;
vector<int> spf(MAXN);

template<typename T> T gcd(T a, T b) {if (b == 0) return a; a %= b; return gcd(b, a);}

void seive() {
	spf[1] = 1;
	for (int i = 2; i < MAXN; i++) {
		if (spf[i] == 0) {
			spf[i] = i;
			for (int j = 2 * i; j < MAXN; j += i) {
				spf[j] = i;
			}
		}
	}
}

vector<int> mu(MAXN, -5);
int mobF(int x) {
	if (mu[x] != -5) {
		return mu[x];
	}
	if (x == 1) {
		return mu[x] = 1;
	} else if (spf[x] == x) {
		return mu[x] = -1;
	} else if ((x / spf[x]) % spf[x]) {
		return mu[x] = mobF(x / spf[x]) * mobF(spf[x]);
	} else {
		return mu[x] = 0;
	}
}

void solve() {
	int n, q;
	cin >> n >> q;

	vector<int> a(n);
	int mxn = 0;
	for (auto &x : a) {
		cin >> x;
		mxn = max(mxn, x);
	}

	vector<int> hsh(mxn + 1, 0);

	vector<vector<int>> d(mxn + 1, vector<int>(1, 1));

	for (int i = 2; i <= mxn; i++) {
		for (int j = i; j <= mxn; j += i) {
			d[j].push_back(i);
		}
	}

	vector<int> cnt(n, 0);
	vector<int> val(mxn + 1, 0);

	int ans = 0;
	while (q--) {
		int x;
		cin >> x;
		x--;
		cnt[x]++;
		cnt[x] %= 2;

		int v = a[x];

		if (cnt[x] == 1) {
			for (int j = 0; j < d[v].size(); j++) {
				int dd = d[v][j];

				ans += mu[dd] * val[dd];
				val[dd]++;
			}
		} else {
			if (v == 1) {
				for (int j = 0; j < d[v].size(); j++) {
					int dd = d[v][j];


					ans -= mu[dd] * (val[dd] - 1);
					val[dd]--;
				}

			} else {
				for (int j = 0; j < d[v].size(); j++) {
					int dd = d[v][j];


					ans -= mu[dd] * val[dd];
					val[dd]--;
				}

			}
		}

		cout << ans << "\n";

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

	seive();
	for (int i = 1; i < MAXN; i++) {
		mobF(i);
	}

	while (t--) {
		solve();
	}

	// cerr << "Time elapsed: " << ((long double)clock() / CLOCKS_PER_SEC) << " s.\n";
}

