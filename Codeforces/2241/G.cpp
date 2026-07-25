#include <bits/stdc++.h>
using namespace std;

using ll = long long;

void print(__int128 x) {
    if (x > 9) print(x / 10);
    cout << char(x % 10 + '0');
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
        __int128_t res = 0;
        vector<int> seq;
        seq.push_back(n - 1);
        for (int i = n - 2; i >= 0; i--) {
            while (!seq.empty() && a[seq.back()] % a[i] == 0)
                seq.pop_back();
            ll best = 0;
            if (!seq.empty()) {
                ll mn = a[seq.back()] % a[i];
                mn = min(mn, abs(mn - a[i]));
                best = mn * (n - seq.back());
            }
            res += best;
            seq.push_back(i);
        }
        print(res);
        cout << "\n";
    }
    return 0;
}
