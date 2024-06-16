#include <bits/stdc++.h>
using namespace std;

#define int long long

const int MAXN = 1e5 + 5;
const int MOD = 998244353;
vector<int> spf(MAXN);

int add(int a, int b, int c = MOD) {int res = a + b; return (res >= c ? res % c : res);}
int sub(int a, int b, int c = MOD) {int res; if (abs(a - b) < c)res = a - b; else res = (a - b) % c; return (res < 0 ? res + c : res);}
int mul(int a, int b, int c = MOD) {int res = (int)a * b; return (res >= c ? res % c : res);}

int ceil(int a, int b) {
    return (a + b - 1) / b;
}

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
        int n, m;
        cin >> n >> m;
        vector<pair<int, int>> range(n);
        for (int i = 0; i < n; i++) {
            cin >> range[i].first >> range[i].second;
        }

        int ans = 0;

        for (int d = 1; d <= m; d++) {
            vector<pair<int, int>> newR(n);
            for (int i = 0; i < n; i++) {
                newR[i] = {ceil(range[i].first, d), range[i].second / d};
            }

            vector<vector<int>> dp(n, vector<int>(m / d + 2, 0ll));

            for (int i = newR[0].first; i <= newR[0].second; i++) {
                dp[0][i] = 1;
            }

            vector<int> psm(m / d + 2, 0ll);
            for (int i = 0; i <= m / d; i++) {
                psm[i] = (i == 0 ? dp[0][i] : add(dp[0][i] , psm[i - 1]));
            }

            for (int i = 1; i < n; i++) {
                for (int j = 0; j <= m / d; j++) {

                    auto sm = [&](int i, int j) {
                        if (i == 0) {
                            return psm[j];
                        } else {
                            return sub(psm[j], psm[i - 1]);
                        }
                    };
                    int r = j - newR[i].first;
                    int l =  j - newR[i].second;

                    if (l < 0) {
                        l = 0;
                    }
                    if (r >= 0) {
                        dp[i][j] = sm(l, r);
                    }
                }

                for (int j = 0; j <= m / d; j++) {
                    psm[j] = (j == 0 ? dp[i][j] : add(dp[i][j] , psm[j - 1]));
                }
            }
            int sm = 0;
            for (int i = 0; i <= m / d; i++) {
                sm = add(sm, dp[n - 1][i]);
            }
            ans = add(ans, mul(mu[d], sm));
            ans = add(ans, MOD);
        }

        cout << ans << "\n";
    }
}
