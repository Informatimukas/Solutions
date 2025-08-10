#include <bits/stdc++.h>
using namespace std;

using ll = long long;

constexpr int Maxm = 1000006;

ll Add(const vector<int>& primes, int lvl, vector<int>& cnt, int cur, int mult) {
    if (lvl >= primes.size())
        return mult * cnt[cur]++;
    return Add(primes, lvl + 1, cnt, cur, mult) +
        Add(primes, lvl + 1, cnt, cur * primes[lvl], -mult);
}

int findCoprime(const vector<int>& a, int m,
    const vector<vector<int>>& primes, const set<int>& forb) {
    vector<int> cnt(m + 1);
    for (int i = 1; i < a.size(); i++)
        if (!forb.contains(i))
            if (Add(primes[a[i]], 0, cnt, 1, 1) > 0)
                return i;
    return -1;
}

vector<int> findGood(const vector<int>& a, int fir, const set<int>& forb) {
    vector<int> good;
    for (int i = 1; i < a.size(); i++)
        if (i != fir && !forb.contains(i) && __gcd(a[i], a[fir]) == 1)
            good.push_back(i);
    return good;
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    vector<vector<int>> primes(Maxm);
    for (int i = 2; i < Maxm; i++) if (primes[i].empty())
        for (int j = i; j < Maxm; j += i)
            primes[j].push_back(i);
    int T;
    cin >> T;
    while (T--) {
        int n, m;
        cin >> n >> m;
        vector<int> a(n + 1);
        for (int i = 1; i <= n; i++)
            cin >> a[i];
        int fir = findCoprime(a, m, primes, {});
        if (fir == -1) {
            cout << "0\n";
            continue;
        }
        auto sec = findGood(a, fir, {});
        if (sec.size() == 1) {
            int thir = findCoprime(a, m, primes, {fir, sec[0]});
            if (thir == -1) {
                cout << "0\n";
                continue;
            }
            auto four = findGood(a, thir, {fir, sec[0]});
            cout << fir << " " << sec[0] << " " << thir << " " << four[0] << "\n";
            continue;
        }
        if (sec.size() >= 3) {
            int thir = findCoprime(a, m, primes, {fir});
            if (thir == -1) {
                cout << "0\n";
                continue;
            }
            auto four = findGood(a, thir, {fir});
            sec = findGood(a, fir, {thir, four[0]});
            cout << fir << " " << sec[0] << " " << thir << " " << four[0] << "\n";
            continue;
        }
        vector all = {fir, sec[0], sec[1]};
        bool found = false;
        for (int i = 0; i < all.size() && !found; i++)
            for (int j = i + 1; j < all.size() && !found; j++)
                if (__gcd(a[all[i]], a[all[j]]) == 1) {
                    int thir = findCoprime(a, m, primes, {all[i], all[j]});
                    if (thir == -1) continue;
                    auto four = findGood(a, thir, {all[i], all[j]});
                    cout << all[i] << " " << all[j] << " " << thir << " " << four[0] << "\n";
                    found = true;
                }
        if (!found) cout << "0\n";
    }
    return 0;
}
