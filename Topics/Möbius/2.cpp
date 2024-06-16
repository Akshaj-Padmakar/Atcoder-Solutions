#include <bits/stdc++.h>
using namespace std;

#define int long long

const int MAXN = 2e5 + 5;
vector<int> spf(MAXN);

template<typename T> T gcd(T a, T b) {if (b == 0) return a; a %= b; return gcd(b, a);}

void seive() {
	spf[1] = 1;
	for (int i = 2; i < MAXN; i++) {
		if (spf[i] == 0) {
			spf[i] = i;
			for (int j = 2 * i; j < MAXN; j += i) {
				spf[j] = i;
			}
		}
	}
}

vector<int> mu(MAXN, -5);
int mobF(int x) {
	if (mu[x] != -5) {
		return mu[x];
	}
	if (x == 1) {
		return mu[x] = 1;
	} else if (spf[x] == x) {
		return mu[x] = -1;
	} else if ((x / spf[x]) % spf[x]) {
		return mu[x] = mobF(x / spf[x]) * mobF(spf[x]);
	} else {
		return mu[x] = 0;
	}
}
vector<int> cnt(MAXN);
vector<vector<int>> fac(MAXN);
int cal(vector<int> &cur) {
	int sm = 0;
	for (auto x : cur) {
		// elements in the array p
		for (auto f : fac[x]) {
			sm += (2ll * cnt[f] + 1ll) * mu[f];
			cnt[f]++;
		}
	}

	for (auto x : cur) {
		for (auto f : fac[x]) {
			cnt[f] = 0;
		}
	}
	return sm;
}
void solve() {
	int n; cin >> n;
	vector<int> p(n + 1); int val = 0;
	for (int i = 1; i <= n; i++) {
		cin >> p[i];
	}

	for (int i = 1; i <= n; i++) {
		if (gcd(i, i) != 1 && gcd(p[i], p[i]) != 1) {
			val++;
			//stores the count of valid array such that gcd(a[i],a[i])=1 or gcd(i,i)=1
		}
	}
	for (int i = 1; i <= n; i++) {
		for (int j = i; j <= n; j += i) {
			fac[j].push_back(i);
		}
	}
	int s1 = 0, s2 = 0, s3 = 0;
	for (int d = 1; d <= n; d++) {
		s1 += mobF(d) * (n / d) * (n / d);
	}
	s2 = s1;



	for (int i = 1; i <= n; i++) {
		vector<int> cur;
		for (int j = i; j <= n; j += i) {
			cur.push_back(p[j]);
		}
		s3 += cal(cur) * mu[i];
	}

	int ans = n * n - (s1 + s2 - s3);

	cout << (ans + val) / 2 << "\n";
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
	seive();
	for (int i = 1; i < MAXN; i++) {
		mobF(i);
	}
	while (t--) {
		solve();
	}
}



