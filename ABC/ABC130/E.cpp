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
*> dp[i][j] -> consider the first i and j elements of a and b; and ith element and jth element are selected; How many ways are possible.

*> if(a[i]==b[j]) -> dp[i][j] = sigma(dp[i-k1][j-k2]); k1>=1 k2>=1

*> calculate this sigma, as we calculate dp's, pretty ez.

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
	int n, m;
	cin >> n >> m;
	vector<int> a(n), b(m);
	for (auto &x : a) {
		cin >> x;
	}
	for (auto &x : b) {
		cin >> x;
	}


	vector<vector<mint>> dp(n, vector<mint>(m, 0));

	if (a[0] == b[0]) {
		dp[0][0] = 1;
	}

	auto sm = dp;
	//dp[i][j] -> consider the first i and j elements of a and b; and ith element and jth element are selected;



	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			if (i + j == 0) {
				continue;
			}

			if (a[i] == b[j]) {
				dp[i][j] = mint(1) + ((i > 0 && j > 0) ? sm[i - 1][j - 1] : mint(0));
			}

			sm[i][j] = dp[i][j] + (i > 0 ? sm[i - 1][j] : mint(0)) + (j > 0 ? sm[i][j - 1] : mint(0)) - (i > 0 && j > 0 ? sm[i - 1][j - 1] : mint(0));
		}
	}


	mint ans = 1;

	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			ans += dp[i][j];
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

