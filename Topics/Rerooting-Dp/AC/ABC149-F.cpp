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
/*
Notes:
*> Very good and different Problem.

*> dp[node] -> count the no. of ways/prob. so that col[node] = white and it is included in S.
*> pretty easy counting problem, once we go by the no. of trees rather than direct probablity.
*/
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
	vector<vector<int>> g(n);
	for (int i = 0, a, b; i + 1 < n; i++) {
		cin >> a >> b;
		a--, b--;
		g[a].push_back(b);
		g[b].push_back(a);
	}
	vector<int> sz(n, 1);
	function<void(int, int)> dfs = [&](int node, int p) {
		for (auto ch : g[node]) {
			if (ch ^ p) {
				dfs(ch, node);
				sz[node] += sz[ch];
			}
		}
	};

	dfs(0, -1);

	mint ans = 0;

	function<void(int, int)> dfs_reroot = [&](int node, int p) {
		mint sm = 1;
		for (auto ch : g[node]) {
			sm += (mint(2ll).binpow(sz[ch]) - 1);
		}
		sm = mint(2ll).binpow(n - 1) - sm;

		ans += (sm / mint(2ll).binpow(n));

		for (auto ch : g[node]) {
			if (ch ^ p) {
				sz[node] -= sz[ch];
				sz[ch] += sz[node];

				dfs_reroot(ch, node);

				sz[ch] -= sz[node];
				sz[node] += sz[ch];
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

