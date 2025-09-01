#include <bits/stdc++.h>
using namespace std;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    int T;
    cin >> T;
    while (T--) {
        int n, k;
        cin >> n >> k;
        vector<long long> a(n);
        for (auto& x : a) {
            cin >> x;
            x += static_cast<long long>(x % (k + 1)) * k;
        }
        for (int i = 0; i < n; i++)
            cout << a[i] << (i + 1 < n? ' ': '\n');
    }
    return 0;
}
