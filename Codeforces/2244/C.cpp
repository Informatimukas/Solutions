#include <bits/stdc++.h>
using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    int T;
    cin >> T;
    while (T--) {
        int n, x, y;
        cin >> n >> x >> y;
        int g = gcd(x, y);
        vector<int> a(n);
        for (auto& z : a)
            cin >> z;
        for (int i = 0; i < g; i++) {
            vector<int> srt;
            for (int j = i; j < n; j += g)
                srt.push_back(a[j]);
            ranges::sort(srt);
            for (int j = i, p = 0; j < n; j += g, p++)
                a[j] = srt[p];
        }
        cout << (ranges::is_sorted(a) ? "YES" : "NO") << "\n";
    }
    return 0;
}
