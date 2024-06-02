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
Notes: I was bit rusty, so took time.

*> Again a pretty easy problem, similar problems exist.

*> anyways the main idea is to note that values of a[i] are small, and O(max(a[i])*log(max(a[i]))) works.
*> So just count how many no.s of x multiple {x*a[i]} exist by using a frequency array.

*> Trival case ? How to deal with duplicates ?
*/
const int MAXN = 1e6 + 5;
void solve() {
	int n;
	cin >> n;
	vector<int> a(n), freq(MAXN, 0), psm(MAXN, 0);
	for (auto&x : a) {
		cin >> x;
		freq[x]++;
	}
	sort(a.begin(), a.end());
	psm = freq;

	for (int i = 1; i < MAXN; i++) {
		psm[i] += psm[i - 1];
	}


	int ans = 0;
	auto cnt = [&](int l, int r) {
		r = min(r, MAXN - 1);
		return (psm[r] - (l > 0 ? psm[l - 1] : 0));
	};
	for (int i = 1; i < MAXN; i++) {
		if (freq[i]) {
			for (int d = 1; d * i < MAXN; d++) {
				int c = cnt(d * i, ((d + 1) * i) - 1);

				ans += c * d * freq[i];

				if (d == 1) {
					int cc = cnt(i, i);
					ans -= cc * d * freq[i];
					ans += freq[i] * (freq[i] + 1) / 2;
				}
			}
		}
	}


	cout << ans - n << "\n";
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

