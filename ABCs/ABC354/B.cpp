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
Notes :
*> Just a straighforward implmentation problem, maybe try using custom sort ?

*/

void solve() {
	int n, sm = 0;
	cin >> n;
	set<pair<string, int>> s;

	for (int i = 0; i < n; i++) {
		string ss;
		int c;
		cin >> ss >> c;
		s.insert({ss, c});
		sm += c;
	}

	int id = sm % n;
	int cur = 0;
	for (auto it = s.begin(); it != s.end(); it++) {
		if (cur == id) {
			cout << (it->first) << "\n";
			break;
		}
		cur++;
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

