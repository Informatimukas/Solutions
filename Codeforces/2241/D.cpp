#include <bits/stdc++.h>
using namespace std;

using ll = long long;

bool Solve(vector<ll> a, vector<ll> b) {
    for (int i = 0; i < a.size(); i++) {
        if (a[i] > b[i])
            return false;
        ll tk = b[i] - a[i];
        if (i + 1 < a.size())
            a[i + 1] -= tk;
    }
    return true;
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    int T;
    cin >> T;
    while (T--) {
        int n;
        cin >> n;
        vector<ll> a(n);
        for (auto& x : a)
            cin >> x;
        vector<ll> b(n);
        for (auto& x : b)
            cin >> x;
        cout << (Solve(a, b) ? "YES" : "NO") << "\n";
    }
    return 0;
}
