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
*> Okay so not a very hard problem, def. not a 2300 on atcoder.

*> The main idea is since s repeats itself -> s1 s2 s3 .. s|s| s1 s2 ...
*> so, t needs to start matching from some si, for some i <= |s|
*> So store for each index i, if it's possible.
*> i -> (i+|t|) %s in the next string (or the same string) in the infinite concatination.
*> and this is unique, so if a path for  'i' is calculated it could be stoed.

*> So we a directed graph with atmost 1 outgoing edge for each node.
	- check for DAG
	- if not a DAG, longest path on G!
*/
const int MOD = 1e9 + 7;
const int MOD2 = 998244353;

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

template<class modInt>struct stringHash {
public:
	stringHash(string &s, int base) {
		_n = s.size();
		_base = base;
		_Ibase = _base.inverse();

		hashF.resize(_n);
		pw.resize(_n);
		inv.resize(_n);


		for (int i = 0; i < _n; i++) {
			pw[i] = _base.binpow(i);
			inv[i] = _Ibase.binpow(i);
		}

		hashF[0] = modInt(s[0] - 'a' + 1);
		for (int i = 1; i < _n; i++) {
			hashF[i] = hashF[i - 1] + pw[i] * (modInt(s[i] - 'a' + 1ll));
		}
	}

	modInt get(int i, int j) {
		if (i == 0) {
			return hashF[j];
		}
		return (hashF[j] - hashF[i - 1]) * inv[i];
	}
private:
	//int base = 31;
	int _n;
	modInt _base, _Ibase;
	vector<modInt> hashF, pw, inv;
};




void solve() {
	string s, t;
	cin >> s >> t;
	string _s = s;

	int szS = s.size(), szT = t.size();
	int j = 0;
	while (_s.size() < szS + szT) {
		_s.push_back(s[j]);
		j++;
		j %= szS;
	}

	stringHash<mint> hsh1(_s, 31);
	// stringHash<mint2> hsh2(_s, 31);

	stringHash<mint> hsht1(t, 31);
	// stringHash<mint> hsht2(t, 31);

	vector<int> dp(szS, false);
	for (int i = 0; i < szS; i++) {
		if (hsh1.get(i, i + szT - 1) == hsht1.get(0, szT - 1)) {
			dp[i] = 1;
		}
	}

	vector<vector<int>> g(szS);
	for (int i = 0; i < szS; i++) {
		if (!dp[i]) {
			continue;
		}
		int cur = i;
		while (1) {
			if (!dp[cur]) {
				break;
			}

			if (g[cur].size() == 1) {
				break;
			}
			int nxt = (cur + szT) % szS;
			g[cur].push_back(nxt);

			swap(cur, nxt);
		}
	}
	int n = szS;

	vector<int> in(n, 0);
	for (int i = 0; i < n; i++) {
		for (auto ch : g[i]) {
			in[ch]++;
		}
	}

	queue<int> q;
	for (int i = 0; i < n; i++) {
		if (in[i] == 0) {
			q.push(i);
		}
	}
	vector<int> tp;
	while (q.size()) {
		int node = q.front();
		q.pop();
		tp.push_back(node);

		for (auto ch : g[node]) {
			in[ch]--;
			if (in[ch] == 0) {
				q.push(ch);
			}
		}
	}
	if (tp.size() != n) {
		cout << -1 << '\n'; return;
	}

	vector<int> dis(n, 0);
	for (int i = n - 1; i >= 0; i--) {
		int node = tp[i];

		for (auto ch : g[node]) {
			dis[node] = max(dis[ch] + 1, dis[node]);
		}
	}

	cout << *max_element(dis.begin(), dis.end()) << '\n';

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
