#include <bits/stdc++.h>
using namespace std;

using ll = long long;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    int n;
    int s;
    ll L;
    cin >> n >> s >> L;
    vector<ll> a(n + 1);
    a[1] = 0;
    for (int i = 2; i <= n; i++) {
        cin >> a[i];
        a[i] += a[i - 1];
    }
    int res = 0;
    for (int i = 1; i <= s; i++)
        for (int j = s; j <= n; j++) {
            ll A = a[s] - a[i];
            ll B = a[j] - a[s];
            ll cand = A + B + min(A, B);
            if (cand <= L)
                res = max(res, j - i + 1);
        }
    cout << res << "\n";
    return 0;
}
