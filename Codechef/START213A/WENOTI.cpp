#include <bits/stdc++.h>
using namespace std;

using ll = long long;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    int T;
    cin >> T;
    while (T--) {
        int n, k;
        cin >> n >> k;
        string s;
        cin >> s;
        vector<int> seq;
        for (int i = 0; i < n; i++)
            if (s[i] != 'I')
                seq.push_back(i);
        if (seq.empty()) {
            cout << static_cast<ll>(n) * k - 1 << "\n";
            continue;
        }
        ll res = 0;
        for (int i = 0; i + 1 < seq.size(); i++)
            if (s[seq[i]] == s[seq[i + 1]])
                res += static_cast<ll>(seq[i + 1] - seq[i]) * k;
            else res += static_cast<ll>(seq[i + 1] - seq[i] - 1) * k;
        res += seq[0] + static_cast<ll>(seq[0] + n - seq.back()) * (k - 1) +
                (n - 1 - seq.back());
        if (s[seq[0]] != s[seq.back()])
            res -= (k - 1);
        cout << res << "\n";
    }
    return 0;
}
