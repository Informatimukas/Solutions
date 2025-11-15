#include <bits/stdc++.h>
using namespace std;

using ll = long long;

constexpr ll lim = 1000000000000ll;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    int T;
    cin >> T;
    while (T--) {
        int x;
        ll y, k;
        cin >> x >> y >> k;
        if (y == 1) {
            cout << "-1\n";
            continue;
        }
        for (int i = 0; i < x && k <= lim; i++)
            k += (k - 1) / (y - 1);
        if (k > lim)
            k = -1;
        cout << k << "\n";
    }
    return 0;
}
