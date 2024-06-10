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
*> This is a very interesting problem.

So consider the classic knapsack dp as
dp[i][x] -> no. of ways to subsitute x on the ith index.

dp[i][x] = dp[i-1][1] + dp[i-1][2] + ... + dp[i-1][t]

s.t x*t<=N -> t<=[N/x]

This is sigma is same for all the values of x s.t [N/x] is same.
So if [N/x] = [N/y] -> dp[i][x] = dp[i][y]

So rather than x and y we keep dp[i][t] as the states, where t = [N/x]

There are only sqrt(N) unique values of [N/x] {theorem !}

dp[i][t] = dp[i-1][z1] + .. dp[i-1][zm] ?

where z1 and zm are transformed values for the 2nd index

t<=[N/x] -> t<=N/x<t+1 -> x*t<=N but x*(t+1)>N

So i-1 can take values from 1 to t
-> transformed index ? [N/1] ... [N/t]

dp[i][t] = dp[i-1][[N/t]] + .. dp[i-1][N]
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
	int n, k;
	cin >> n >> k;
	vector<map<int, mint>> dp(k);

	//dp[i][j] -> no. of ways to put x on ith index s.t [n/x] = j -> j<= n/x < j+1 -> j*x <= n
	vector<int> vl, cnt;
	for (int i = 1; i <= n;) {
		int l = i, r = n;

		auto check = [&](int md) {
			return (n / i) == (n / md);
		};
		while (r - l > 1) {
			int md = (r + l) >> 1ll;
			if (check(md)) {
				l = md;
			} else {
				r = md - 1;
			}
		}
		int v = (check(r) ? r : l);
		dp[0][(int)cnt.size()] = v - i + 1;

		vl.push_back(n / i);
		cnt.push_back(v - i + 1);

		i = v + 1;
	}
	int sz = vl.size();

	for (int i = 1; i < k; i++) {
		vector<mint> psm;

		for (int j = 0; j < sz; j++) {
			psm.push_back(dp[i - 1][j]);
		}

		for (int j = 1; j < sz; j++) {
			psm[j] += psm[j - 1];
		}
		int id = sz - 1;
		for (int j = 0; j < sz; j++) {
			int vv = n / vl[j];
			// vv is an increasing, whearas vl is an decreasing.
			while (1) {
				if (vl[id] == vv) {
					break;
				}
				id--;
			}
			// 0->id
			dp[i][j] = psm[id] * cnt[j];
		}
	}
	mint ans = 0;
	for (auto [x, v] : dp[k - 1]) {
		ans += v;
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

