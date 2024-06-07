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
*> Very good problem, so breaking the sigma in x and y dimension aint that hard.

*> The main catch here is that how do we proceed from there, so consider any pair of cells, say i1,j1 and i2,j2
*> We have (n*m-2,k-2) sets where these 2 cells will occur. So ?

*> Now lets move to single dimension, consider x, so for x = 1 there are d = {1,2,3..n-1} distance possible.
*> each of these distance can occur m*m times {m options of y for x = 1 and same for x = x}

*> sigma(d[i]*m*m*(n*m-2,k-2)) for each x.

*> x = e -> 1 2 .. n-e options for d. => (n-e)*(n-e+1)/2 * m * m * (n*m-2,k-2)

*> We do this for each e, and calculation of the above for each 'e' takes O(1) with proper precomp.
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
	int n, m, k;
	cin >> n >> m >> k;

	vector<mint> fact(n * m + 1, 1);
	for (int i = 1; i <= n * m; i++) {
		fact[i] = fact[i - 1] * i;
	}


	mint ans = 0;
	mint ncrV = fact[n * m - 2] / (fact[k - 2] * fact[n * m - 2 - (k - 2)]);
	mint nwM = ncrV * mint(m) * mint(m);
	for (int i = 0; i < n; i++) {
		ans += (nwM * (mint(n - i) * mint(n - i - 1))) / mint(2);

	}

	mint nwN = ncrV * mint(n) * mint(n);
	for (int i = 0; i < m; i++) {
		ans += (nwN * (mint(m - i) * mint(m - i - 1))) / mint(2);
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

