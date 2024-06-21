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
*> Ez dp.
*/
const int MOD = 1e9 + 7;
const int MOD2 = 13;

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
using mint2 = ModInt< MOD2 >;


void solve() {
	string s;
	cin >> s;
	int n = s.size();
	vector<vector<vector<mint>>> dp(n, vector<vector<mint>>(10, vector<mint>(13, 0)));
	//dp[i][j][x] -> keeping j at the ith digit and having reminder as x -> stores the number of ways !

	reverse(s.begin(), s.end());

	if (s[0] == '?') {
		for (int i = 0; i < 10; i++) {
			dp[0][i][i] = 1;
		}
	} else {
		dp[0][s[0] - '0'][s[0] - '0'] = 1;
	}

	for (int i = 1; i < n; i++) {
		if (s[i] == '?') {
			for (int d = 0; d < 10; d++) {
				for (int k = 0; k < 13; k++) {
					mint2 y = mint2(k) - mint2(d) * mint2(10).binpow(i);
					for (int j = 0; j < 10; j++) {
						dp[i][d][k] += dp[i - 1][j][y.x];
					}
				}
			}
		} else {
			int d = s[i] - '0';
			for (int k = 0; k < 13; k++) {
				mint2 y = mint2(k) - mint2(d) * mint2(10).binpow(i);
				for (int j = 0; j < 10; j++) {
					dp[i][d][k] += dp[i - 1][j][y.x];
				}
			}
		}
	}

	mint ans = 0;

	for (int j = 0; j < 10; j++) {
		ans += dp[n - 1][j][5];
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
