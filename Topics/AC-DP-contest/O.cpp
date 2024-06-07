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
*> A classic bitmasking problem, constraints screams so.

*> We fix the order in which we scan man, then we choose any random set of women, and form a pairing.

*> O(n^2*2^n)

*> dp[i][msk] -> pair the first i men and msk set of women.
              -> stores the no. of ways to do so
*/

const int MOD = 1e9 + 7;

template< int mod >struct ModInt {
public:
	int x;

	ModInt() : x(0) {}

	ModInt(int _x) {
		_x %= mod; _x += mod; _x %= mod;
		x = _x;
	}

	ModInt &operator+=(const ModInt &_x) {
		x += _x.x;
		if (x >= mod) {
			x -= mod;
		}
		return *this;
	}

	ModInt &operator-=(const ModInt &_x) {
		x -= _x.x;
		if (x < 0) {
			x += mod;
		}
		return *this;
	}

	ModInt &operator*=(const ModInt &_x) {
		x *= _x.x; x %= mod;

		return *this;
	}

	ModInt &operator/=(const ModInt &_x) {
		*this *= _x.inverse();
		return *this;
	}

	ModInt operator-() const {return ModInt(-x); }

	ModInt operator+(const ModInt &_x) const { return ModInt(*this) += _x; }

	ModInt operator-(const ModInt &_x) const { return ModInt(*this) -= _x; }

	ModInt operator*(const ModInt &_x) const { return ModInt(*this) *= _x; }

	ModInt operator/(const ModInt &_x) const { return ModInt(*this) /= _x; }

	bool operator==(const ModInt &_x) const { return x == _x.x; }

	bool operator!=(const ModInt &_x) const { return x != _x.x; }

	ModInt inverse() const {
		int a = x, b = mod, u = 1, v = 0, t;
		while (b > 0) {
			t = a / b;
			swap(a -= t * b, b);
			swap(u -= t * v, v);
		}
		return ModInt(u);
	}

	ModInt binpow(int n) const {
		ModInt ans(1), mul(x);
		while (n > 0) {
			if (n & 1) {
				ans *= mul;
			}
			mul *= mul;
			n >>= 1;
		}
		return ans;
	}

	friend ostream &operator<<(ostream &os, const ModInt &p) {
		return os << p.x;
	}

	friend istream &operator>>(istream &is, ModInt &a) {
		int t;
		is >> t;
		a = ModInt< mod >(t);
		return (is);
	}

private:
};

using mint = ModInt< MOD >;

void solve() {
	int n;
	cin >> n;
	vector<vector<int>> a(n, vector<int>(n));

	for (auto &x : a) {
		for (auto &y : x) {
			cin >> y;
		}
	}

	vector<vector<mint>> dp(n + 1, vector<mint>(1ll << n, 0));

	dp[0][0] = 1;

	for (int i = 1; i <= n; i++) {
		for (int msk = 0; msk < 1ll << n; msk++) {
			if (__builtin_popcount(msk) == i) {
				for (int j = 0; j < n; j++) {
					if (msk & 1ll << j && a[i - 1][j]) {
						dp[i][msk] += dp[i - 1][msk ^ (1ll << j)];

					}
				}
			}
		}
	}

	cout << dp[n][(1ll << n) - 1] << "\n";
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

