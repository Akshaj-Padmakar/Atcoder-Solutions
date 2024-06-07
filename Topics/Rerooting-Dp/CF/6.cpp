#include <bits/stdc++.h>
using namespace std;

#ifndef ONLINE_JUDGE
#include "algo/debug.h"
#define debug(x...) cerr << "[" << #x << "] = ["; _print(x)
#else
#define debug(x...)
#endif

#define int long long

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
	int n;
	cin >> n;
	vector<int> a(n);
	for (auto &x : a) {
		cin >> x;
	}

	vector<vector<int>> g(n);
	for (int i = 0, a, b; i + 1 < n; i++) {
		cin >> a >> b;
		a--, b--;
		g[b].push_back(a);
		g[a].push_back(b);
	}

	vector<mint> dp(n);
	vector<int> sz(n, 1);
	for (int i = 0; i < n; i++) {
		dp[i] = a[i];
	}

	function<void(int, int)> dfs = [&](int node, int p) {
		for (auto ch : g[node]) {
			if (ch ^ p) {
				dfs(ch, node);
				sz[node] += sz[ch];
				dp[node] += mint(sz[ch] * a[node]) - dp[ch];
			}
		}
	};
	dfs(0, -1);
	mint ans = 0;

	function<void(int, int)> dfs_reroot = [&](int node, int p) {
		ans += dp[node];

		for (auto ch : g[node]) {
			if (ch ^ p) {
				dp[node] -= mint(sz[ch] * a[node]) - dp[ch];
				sz[node] -= sz[ch];

				sz[ch] += sz[node];
				dp[ch] += mint(sz[node] * a[ch]) - dp[node];

				dfs_reroot(ch, node);


				dp[ch] -= mint(sz[node] * a[ch]) - dp[node];
				sz[ch] -= sz[node];

				sz[node] += sz[ch];
				dp[node] += mint(sz[ch] * a[node]) - dp[ch];
			}
		}
	};

	dfs_reroot(0, -1);

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

