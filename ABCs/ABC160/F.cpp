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
*> A very very elegant problem !

*> So its pretty obv that we will use rerooting dp{same problem on all vertices.}

*> dp_x[node] = when rooted at node x, what is the number of ways to follow the game rules on subtree of `node`.

*> So consider a `node` for which we are currently solving and obv we have solved the problem for all its children
    we have calculated the no. of ways to divide sz[ch] no. on subtree of ch. -> stored in dp[ch]

*> So imagine r boxes, where r is the no. of children of `node`

*> We have sz[node]-1 no.s to be distributed among these boxed/children. {note that the value at `node` is fixed rn}

*> This is just multinomial coeffcient i.e (sz[node]-1; r[0],r[1],r[2]..r[i]..r[r])
   Once choices of number have been made, the distributing is just denoted by dp[ch].

*> Using M.P we have the solution for dp[node]

*> Now moving to the rerooting part, its pretty obv how things work
   -undo the effect of `ch` on `node`
   -then make correction for the values that are used {like sz array etc.}
   -then add effect on `ch`.

   - dfs

   - redo the things in the reverse order{before dfs}.
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
	vector<vector<int>> g(n);
	for (int i = 0, a, b; i < n - 1; i++) {
		cin >> a >> b;
		a--, b--;
		g[a].push_back(b);
		g[b].push_back(a);
	}


	vector<mint> fact(n + 1, 1);

	for (int i = 1; i <= n; i++) {
		fact[i] = mint(i) * fact[i - 1];
	}
	vector<mint> dp(n, 1), ans(n);
	vector<int> sz(n, 1);
	auto multinomial_coeff = [&](int m, vector<int> &r) {
		//m!/(r[0]! .. r[i]! ..)

		mint ans = fact[m];
		for (auto &x : r) {
			ans /= fact[x];
		}

		return ans;
	};
	function<void(int, int)> dfs = [&](int node, int p) {
		vector<int> r;
		for (auto ch : g[node]) {
			if (ch ^ p) {
				dfs(ch, node);

				sz[node] += sz[ch];
				dp[node] *= dp[ch];

				r.push_back(sz[ch]);
			}
		}
		dp[node] *= multinomial_coeff(sz[node] - 1, r);
	};

	dfs(0, -1);
	// debug(dp[4].x);

	function<void(int, int)> dfs_reroot = [&](int node, int p) {
		ans[node] = dp[node];
		// debug(node);
		for (auto ch : g[node]) {
			if (ch ^ p) {
				dp[node] /= fact[sz[node] - 1];
				dp[node] *= fact[sz[ch]];
				dp[node] /= dp[ch];


				dp[ch] /= fact[sz[ch] - 1];

				sz[node] -= sz[ch];
				sz[ch] += sz[node];

				dp[node] *= fact[sz[node] - 1];


				dp[ch] *= fact[sz[ch] - 1];
				dp[ch] /= fact[sz[node]];
				dp[ch] *= dp[node];


				dfs_reroot(ch, node);

				dp[ch] /= dp[node];
				dp[ch] *= fact[sz[node]];
				dp[ch] /= fact[sz[ch] - 1];


				dp[node] /= fact[sz[node] - 1];


				sz[ch] -= sz[node];
				sz[node] += sz[ch];

				dp[ch] *= fact[sz[ch] - 1];

				dp[node] *= dp[ch];
				dp[node] /= fact[sz[ch]];
				dp[node] *= fact[sz[node] - 1];

			}
		}
	};

	dfs_reroot(0, -1);

	for (auto &x : ans) {
		cout << x << '\n';
	}


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

