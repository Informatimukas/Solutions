#include <bits/stdc++.h>
using namespace std;

using ll = long long;
using lli = pair<ll, int>;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    int T;
    cin >> T;
    while (T--) {
        int n;
        cin >> n;
        vector<ll> a(n);
        vector<ll> difs(n);
        for (int i = 0; i < n; i++) {
            cin >> a[i];
            if (i)
                difs[i] = a[i] - a[i - 1];
        }
        for (int i = 1, j; i < n; i = j + 1) {
            j = i;
            while (j + 1 < n && (a[j - 1] % 2 != 0) == (a[j + 1] % 2 != 0))
                j++;
            sort(difs.begin() + i, difs.begin() + j + 1);
        }
        for (int i = 1; i < n; i++)
            a[i] = a[i - 1] + difs[i];
        for (int i = 0; i < n; i++)
            cout << a[i] << (i + 1 < n ? ' ' : '\n');
    }
    return 0;
}
