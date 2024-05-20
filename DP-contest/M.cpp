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
*> prefix sum optimisation dp problem
*> dp[i][j] -> we have scanned the first i+1 students
               and distributed j candies -> number of ways for this scenrio

*> dp[i][j] = sum(dp[i-1][j-k]), where k = [0,min(a[i],k)];
*> Just a range sum of a static array -> Prefix sum.
*/

const int MOD = 1e9 + 7;

template< int mod >struct ModInt {
public:
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
	int x;
};

using mint = ModInt< MOD >;
void solve() {
	int n, k;

	cin >> n >> k;

	vector<int> a(n);
	for (auto &x : a) {
		cin >> x;
	}

	vector<vector<mint>> dp(n, vector<mint>(k + 1, 0));

	for (int i = 0; i <= min(k, a[0]); i++) {
		dp[0][i] = 1;
	}

	for (int i = 1; i < n; i++) {
		vector<mint> psm = dp[i - 1];
		for (int j = 1; j <= k; j++) {
			psm[j] += psm[j - 1];
		}

		auto sm = [&](int l, int r) {
			return l == 0 ? psm[r] : (psm[r] - psm[l - 1]);
		};
		for (int j = 0; j <= k; j++) {
			dp[i][j] = sm(max(0ll, j - a[i]), j);
		}
	}

	cout << dp[n - 1][k] << "\n";

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

