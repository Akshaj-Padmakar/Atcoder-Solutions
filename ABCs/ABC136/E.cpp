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
Notes :
*> SO it is not at that hard.
*> if k-> inf => ans = sum(A)
*> the answer could be a factor of sum(A) !
*> no. of operations needed for a factor of d ? like the every no is divisible by d, after some operations
*> take d modulus -> no either a[i]%d operations of -1 or d-a[i]%d of +1 operations
*> sort this r[i] array and till the first i smallest indexes do -1 and from there on do +1
*> they both turn out same -> and sum(r[j]) <= k , j<=i => a solution !
*/
void solve() {
	int n, k, s = 0;
	cin >> n >> k;
	vector<int> a(n);
	for (auto &x : a) {
		cin >> x;
		s += x;
	}

	vector<int> f;
	for (int i = 1; i * i <= s; i++) {
		if ((s % i) == 0) {
			f.push_back(i);
			if (i * i != s) {
				f.push_back(s / i);
			}
		}
	}

	sort(f.begin(), f.end());
	debug(f);
	int ans = 1;
	for (auto d : f) {
		vector<int> r(n);
		for (int j = 0; j < n; j++) {
			r[j] = (a[j] % d);
		}
		sort(r.begin(), r.end());
		reverse(r.begin(), r.end());

		while (r.size() && r.back() == 0) {
			r.pop_back();
		}

		if (r.size() == 0) {
			ans = max(ans, d);
			continue;
		}

		reverse(r.begin(), r.end());

		int szR = r.size();
		vector<int> psm(szR), ssm(szR);
		for (int i = 0; i < szR; i++) {
			psm[i] = (i > 0 ? psm[i - 1] : 0) + r[i];
		}

		for (int i = szR - 1; i >= 0; i--) {
			int v = d - r[i];
			ssm[i] = (i + 1 == szR ? 0 : ssm[i + 1]) + v;
		}

		for (int i = 0; i + 1 < szR; i++) {
			if (psm[i] == ssm[i + 1]) {
				if (psm[i] <= k) {
					ans = max(ans, d);
				}
			}
		}
	}

	cout << ans << '\n';
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
