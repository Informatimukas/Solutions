#include <bits/stdc++.h>
using namespace std;

constexpr int Maxn = 400005;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    vector prime(Maxn, true);
    vector mn(Maxn, 0);
    for (int i = 2; i < Maxn; i++)
        if (prime[i]) {
            for (int j = i + i; j < Maxn; j += i)
                prime[j] = false;
            if (i % 2)
                for (int j = i; j < Maxn; j += i)
                    if (mn[j] == 0)
                        mn[j] = i;
        }
    int T;
    cin >> T;
    while (T--) {
        int n;
        cin >> n;
        vector<int> a(n);
        set<int> primes;
        for (auto& x : a) {
            cin >> x;
            if (prime[x])
                primes.insert(x);
        }
        if (primes.empty()) {
            cout << "2\n";
            continue;
        }
        if (primes.size() >= 2) {
            cout << "-1\n";
            continue;
        }
        int p = *primes.begin();
        bool ok = true;
        for (auto x : a) {
            bool good = p == 2 || x == p || x % 2 == 0 && x >= 2 * p || x % 2 && mn[x] && x - mn[x] >= 2 * p;
            if (!good)
                ok = false;
        }
        cout << (ok ? p : -1) << "\n";
    }
    return 0;
}
