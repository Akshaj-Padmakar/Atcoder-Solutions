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
NO FUCKING WAY MINT BETRAYED, DUDE SO UNLUCKY :/
*/
const int MOD = 998244353;

template<typename T> T gcd(T a, T b) {if (b == 0) return a; a %= b; return gcd(b, a);}
template<typename T> T lcm(T a, T b) {return (a * (b / gcd(a, b)));}
int add(int a, int b, int c = MOD) {int res = a + b; return (res >= c ? res % c : res);}
int sub(int a, int b, int c = MOD) {int res; if (abs(a - b) < c)res = a - b; else res = (a - b) % c; return (res < 0 ? res + c : res);}
int mul(int a, int b, int c = MOD) {int res = (long long)a * b; return (res >= c ? res % c : res);}

template<typename T>T binpow(T e, T n) {T x = 1, p = e; while (n) {if (n & 1)x = x * p; p = p * p; n >>= 1;} return x;}
template<typename T>T binpow2(T e, T n, T m = MOD) {T x = 1, p = e; while (n) {if (n & 1)x = mul(x, p, m); p = mul(p, p, m); n >>= 1;} return x;}
template<typename T>T extended_euclid(T a, T b, T &x, T &y) {
	T xx = 0, yy = 1; y = 0; x = 1; while (b) {
		T q = a / b, t = b; b = a % b; a = t; \
		t = xx; xx = x - q * xx; x = t; t = yy; yy = y - q * yy; y = t;
	} return a;
}
template<typename T>T mod_inverse(T a, T n = MOD) {T x, y, z = 0; T d = extended_euclid(a, n, x, y); return (d > 1 ? -1 : sub(x, z, n));}



void solve() {
	int n; cin >> n;

	vector<int> c(26);
	for (auto &x : c) {
		cin >> x;
	}
	vector<int> fact(n + 1, 1);
	for (int i = 1; i <= n; i++) {
		fact[i] = fact[i - 1] * i;
		fact[i] %= MOD;
	}

	vector<int> ifact(n + 1);
	for (int i = 0; i <= n; i++) {
		ifact[i] = mod_inverse(fact[i]);
	}
	vector<int> dp(n + 1, 0);
	//dp[i][j] -> count the number of ways to get j length using first i variable

	for (int i = 0; i <= min(n, c[0]); i++) {
		dp[i] = 1;// base case
	}

	for (int i = 1; i < 26; i++) {
		vector<int> nxt(n + 1, 0);
		for (int j = 0; j <= n; j++) {
			for (int x = 0; x <= min(j, c[i]); x++) {
				int m = fact[j]; m %= MOD;
				m *= ifact[j - x]; m %= MOD;
				m *= ifact[x]; m %= MOD;

				nxt[j] += dp[j - x] * m;
				nxt[j] %= MOD;
			}
		}
		swap(nxt, dp);
	}


	int ans = 0;

	for (int j = 1; j <= n; j++) {
		ans += dp[j];
		ans %= MOD;
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

