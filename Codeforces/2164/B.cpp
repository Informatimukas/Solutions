#include <bits/stdc++.h>
using namespace std;

vector<int> Solve(const vector<int>& a) {
    vector<int> ev;
    for (int i = 0; i < a.size(); i++) {
        if (a[i] % 2 == 0)
            ev.push_back(a[i]);
    }
    if (ev.size() >= 2)
        return {ev[0], ev[1]};
    for (int i = 0; i < a.size(); i++)
        for (int j = i + 1; j < a.size(); j++)
            if (a[j] % a[i] % 2 == 0)
                return {a[i], a[j]};
    return {};
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
        for (auto& x : a)
            cin >> x;
        auto res = Solve(a);
        if (res.empty())
            cout << "-1\n";
        else cout << res[0] << " " << res[1] << "\n";
    }
    return 0;
}
