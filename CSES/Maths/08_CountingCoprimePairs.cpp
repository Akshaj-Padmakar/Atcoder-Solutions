#include <bits/stdc++.h>
using namespace std;

#ifndef ONLINE_JUDGE
#include "algo/debug.h"
#define debug(x...) cerr << "[" << #x << "] = ["; _print(x)
#else
#define debug(x...)
#endif

#define int long long

const int MAXN = 1e6 + 1;
vector<int> mu(MAXN);

void mobius() {
	vector<int> primes;
	vector<bool> isPrime(MAXN, true);

	mu[1] = 1;  // μ(1) = 1

	for (int i = 2; i < MAXN; ++i) {
		if (isPrime[i]) {
			primes.push_back(i);
			mu[i] = -1;  // i is prime, μ(i) = -1
		}

		for (int j = 0; j < primes.size() && i * primes[j] < MAXN; ++j) {
			isPrime[i * primes[j]] = false;

			if (i % primes[j] == 0) {
				mu[i * primes[j]] = 0;  // i has a squared prime factor, μ(i * p) = 0
				break;
			} else {
				mu[i * primes[j]] = mu[i] * mu[primes[j]];  // μ(i * p) = μ(i) * μ(p)
			}
		}
	}
}


void solve() {
	int n;
	cin >> n;
	vector<int> a(n);
	vector<int> hsh(MAXN, 0);
	mobius();
	for (auto &x : a) {
		cin >> x;
		hsh[x]++;
	}
	auto cnt = hsh;

	for (int i = 1; i < MAXN; i++) {
		for (int j = 2 * i; j < MAXN; j += i) {
			cnt[i] += hsh[j];
		}
	}
	int ans = 0;


	for (int d = 1; d < MAXN; d++) {
		ans += mu[d] * (cnt[d] * cnt[d]);
	}

	cout << (ans - hsh[1]) / 2 << '\n';

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