#include <bits/stdc++.h>
using namespace std;

constexpr int Inf = 1000000000;

int Solve(const vector<int>& a, const vector<int>& b) {
    int res = 0;
    for (int i = 0; i < a.size(); i++) {
        if (a[i] < b[i])
            return Inf;
        res += a[i] - b[i];
    }
    return res;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    int T;
    cin >> T;
    while (T--) {
        int n, c;
        cin >> n >> c;
        vector<int> a(n);
        for (auto& x : a)
            cin >> x;
        vector<int> b(n);
        for (auto& x : b)
            cin >> x;
        int res1 = Solve(a, b);
        ranges::sort(a);
        ranges::sort(b);
        int res2 = c + Solve(a, b);
        int res = min(res1, res2);
        if (res >= Inf)
            res = -1;
        cout << res << "\n";
    }
    return 0;
}
