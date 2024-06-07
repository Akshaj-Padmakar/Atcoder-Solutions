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
*> comparater sorting problem, dont go into decimals !
*> cmp(a,b) -> what order do you want to satisfy between a and b
               {if that is the order the appear in your final array ... a .. b...}
*> return true if satisfy else false.
*/

bool cmp(pair<pair<int, int>, int> a, pair<pair<int, int>, int>b) {
	int x1 = a.first.first * (b.first.first + b.first.second);
	int x2 = b.first.first * (a.first.first + a.first.second);

	return (x1 == x2 ? a.second<b.second : x1>x2);
}
void solve() {
	int n;
	cin >> n;

	vector<pair<pair<int, int>, int>> v;
	for (int i = 0, a, b; i < n; i++) {
		cin >> a >> b;
		v.push_back({{a, b}, i});
	}

	sort(v.begin(), v.end(), cmp);

	for (auto x : v) {
		cout << x.second + 1 << " ";
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

