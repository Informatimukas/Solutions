#include <bits/stdc++.h>
using namespace std;

using ii = pair<int, int>;

int Next(int a) {
    int res = 0;
    while (a) {
        res += a % 10 * (a % 10);
        a /= 10;
    }
    return res;
}

map<ii, int> M;

bool Solve(int a, int b) {
    if (a == b)
        return true;
    auto it = M.find({a, b});
    if (it != M.end())
        return it->second;
    M[{a, b}] = false;
    auto res = Solve(Next(a), Next(b));
    M[{a, b}] = res;
    return res;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    int T;
    cin >> T;
    while (T--) {
        int n;
        cin >> n;
        vector<int> a(n);
        for (auto& x : a)
            cin >> x;
        int res = 0;
        for (int i = 0; i < n; i++)
            for (int j = i + 1; j < n; j++)
                if (Solve(a[i], a[j]))
                    res++;
        cout << res << "\n";
    }
    return 0;
}
