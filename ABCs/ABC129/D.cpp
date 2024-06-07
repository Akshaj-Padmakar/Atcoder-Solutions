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
*> Again a pretty easy prefix sum problem, just do it indiviually on X and Y directions.
*/
void solve() {
	int n, m;
	cin >> n >> m;

	vector<vector<int>> a(n, vector<int>(m));

	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			char x; cin >> x;

			if (x == '.') {
				a[i][j] = 1;
			} else {
				a[i][j] = 0;
			}
		}
	}

	vector<vector<int>> psmX = a, psmY = a;
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			if (i)psmY[i][j] += psmY[i - 1][j];
			if (j)psmX[i][j] += psmX[i][j - 1];
		}
	}

	auto X = [&](int i, int j1, int j2) {
		return (psmX[i][j2] - (j1 > 0 ? psmX[i][j1 - 1] : 0)) == (j2 - j1 + 1);
	};

	auto Y = [&](int j, int i1, int i2) {
		return (psmY[i2][j] - (i1 > 0 ? psmY[i1 - 1][j] : 0)) == (i2 - i1 + 1);
	};

	int ans = 0;
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			//consider this as the center;
			if (!a[i][j]) {
				continue;
			}
			int cur = 0;
			int l = 0, r = j;

			auto checkl = [&](int md) {
				return X(i, md, j);
			};
			while (r - l > 1) {
				int md = (r + l) >> 1ll;

				if (checkl(md)) {
					r = md;
				} else {
					l = md + 1;
				}
			}

			if (checkl(l)) {
				cur += abs(l - j) + 1;
			} else {
				cur += abs(r - j) + 1;
			}



			l = j, r = m - 1;

			auto checkr = [&](int md) {
				return X(i, j, md);
			};
			while (r - l > 1) {
				int md = (r + l) >> 1ll;

				if (checkr(md)) {
					l = md;
				} else {
					r = md - 1;
				}
			}

			if (checkr(r)) {
				cur += abs(r - j) + 1;
			} else {
				cur += abs(l - j) + 1;
			}





			l = 0, r = i;

			auto checku = [&](int md) {
				return Y(j, md, i);
			};

			while (r - l > 1) {
				int md = (r + l) >> 1ll;

				if (checku(md)) {
					r = md;
				} else {
					l = md + 1;
				}
			}

			if (checku(l)) {
				cur += abs(l - i) + 1;
			} else {
				cur += abs(r - i) + 1;
			}




			l = i, r = n - 1;

			auto checkd = [&](int md) {
				return Y(j, i, md);
			};

			while (r - l > 1) {
				int md = (r + l) >> 1ll;

				if (checkd(md)) {
					l = md;
				} else {
					r = md - 1;
				}
			}

			if (checkd(r)) {
				cur += abs(r - i) + 1;
			} else {
				cur += abs(l - i) + 1;
			}

			ans = max(ans, cur - 3);
		}
	}

	cout << ans << "\n";

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

