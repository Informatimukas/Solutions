#include <bits/stdc++.h>
using namespace std;

bool Solve(vector<int>& a, set<int>& S) {
    for (int i = a.size() - 1; i > 0; i -= 2) {
        auto it = S.upper_bound(a[i]);
        if (it == S.begin())
            return false;
        --it;
        a[i - 1] = *it;
        S.erase(it);
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
        vector<int> a(n);
        set<int> S;
        for (int i = 1; i <= n; i++)
            S.insert(i);
        bool ok = true;
        for (int i = 1; i < n; i += 2) {
            cin >> a[i];
            if (!S.contains(a[i]))
                ok = false;
            S.erase(a[i]);
        }
        if (ok && Solve(a, S))
            for (int i = 0; i < a.size(); i++)
                cout << a[i] << (i + 1 < a.size() ? ' ' : '\n');
        else cout << "-1\n";
    }
    return 0;
}
