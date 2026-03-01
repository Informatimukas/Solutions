#include <bits/stdc++.h>
using namespace std;

using ll = long long;

const ll mod = 1000000007;

bool isPower2(int c) {
    while (c % 2 == 0)
        c /= 2;
    return c == 1;
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    int T;
    cin >> T;
    while (T--) {
        int n, c;
        cin >> n >> c;
        string s;
        cin >> s;
        if (s[0] == '0' || s[n - 1] == '0') {
            cout << "-1\n";
            continue;
        }
        s[0] = s[n - 1] = '1';
        ll res = 1;
        vector<int> seq;
        for (int i = 0; i + 1 < n; i++)
            if (s[i] != '?')
                if (s[i] == '1') {
                    if (c % 2 == 0)
                        c /= 2;
                    res = 2 * res % mod;
                } else {
                    c /= __gcd(i, c);
                    res = res * i % mod;
                }
            else if (i % 2 == 0) {
                if (c % 2 == 0)
                    c /= 2;
                res = 2 * res % mod;
            } else if (i != 1)
                seq.push_back(i);
        if (c == 1) {
            cout << "-1\n";
            continue;
        }
        if (!isPower2(c)) {
            for (int i = 0; i < seq.size(); i++)
                res = 2 * res % mod;
            cout << res << "\n";
            continue;
        }
        int tims = 0;
        while (c % 2 == 0) {
            ++tims;
            c /= 2;
        }
        --tims;
        for (int i = 0; i < static_cast<int>(seq.size()) - tims; i++)
            res = res * seq[i] % mod;
        for (int i = 0; i < seq.size() && i < tims; i++)
            res = res * 2 % mod;
        cout << res << "\n";
    }
    return 0;
}
