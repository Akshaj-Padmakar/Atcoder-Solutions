#include <bits/stdc++.h>
using namespace std;

#ifndef ONLINE_JUDGE
#include "algo/debug.h"
#define debug(x...) cerr << "[" << #x << "] = ["; _print(x)
#else
#define debug(x...)
#endif

#define int long long

const int MAXN = 1e5 + 5;
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
vector<int> phi(MAXN);
vector<bool> is_prime(MAXN, true);
void totient() {
	phi[0] = 0;
	phi[1] = 1;
	vector<int> prime;
	for (int i = 2; i < MAXN; i++) {
		if (is_prime[i]) {
			phi[i] = i - 1;
			prime.push_back(i);
		}
		for (int j = 0; j < prime.size() && i * prime[j] < MAXN; j++) {
			is_prime[i * prime[j]] = false;
			if (i % prime[j] == 0) {
				phi[i * prime[j]] = phi[i] * prime[j];
				break;
			} else {
				phi[i * prime[j]] = phi[i] * phi[prime[j]];
			}
		}
	}
}
void solve() {
	totient();

	int n;
	cin >> n;
	vector<int> v(n);
	for (auto &x : v) {
		cin >> x;
	}

	vector<vector<int>> fac(MAXN);
	for (int i = 1; i < MAXN; i++) {
		for (int j = i; j < MAXN; j += i) {
			fac[j].push_back(i);
		}
	}

	vector<int> cnt(MAXN, 0ll);
	auto calc = [&](vector<int> dum) {
		mint sm = 0;
		for (auto z : dum) {
			for (auto f : fac[z]) {
				sm += (2ll * cnt[f] + 1ll) * phi[f];
				cnt[f]++;
			}
		}

		for (auto z : dum) {
			for (auto f : fac[z]) {
				cnt[f] = 0;
			}
		}
		return sm;
	};


	mint ans = 0;

	for (int i = 1; i <= n; i++) {
		vector<int> dum;
		for (int j = i; j <= n; j += i) {
			dum.push_back(v[j - 1]);
		}
		mint phii = phi[i];
		ans += calc(dum) * phii;
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
