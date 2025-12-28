#include <bits/stdc++.h>
using namespace std;

using ll = long long;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    int T;
    cin >> T;
    while (T--) {
        ll x, m;
        cin >> x >> m;
        ll res = 0;
        for (int i = 1; i <= m && i <= x; i++)
            if ((i ^ x) % i == 0)
                res++;
		ll lef = 2, rig = m / x + 1;
		while (lef <= rig) {
			ll mid = (lef + rig) / 2;
			if (((mid * x) ^ x) <= m)
				lef = mid + 1;
			else rig = mid - 1;
		}
		if (rig >= 2)
			res += rig - 1;
		for (int j = 1; j <= 2 * x; j++)
			if ((((rig + j) * x) ^ x) <= m)
				++res;
		cout << res << "\n";
    }
    return 0;
}