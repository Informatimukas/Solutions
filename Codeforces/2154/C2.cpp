#include <bits/stdc++.h>
using namespace std;

using ii = pair<int, int>;

constexpr int Inf = 2000000000;
constexpr int Maxn = 400005;

struct custom_hash {
    static uint64_t splitmix64(uint64_t x) {
        // http://xorshift.di.unimi.it/splitmix64.c
        x += 0x9e3779b97f4a7c15;
        x = (x ^ (x >> 30)) * 0xbf58476d1ce4e5b9;
        x = (x ^ (x >> 27)) * 0x94d049bb133111eb;
        return x ^ (x >> 31);
    }

    size_t operator()(uint64_t x) const {
        static const uint64_t FIXED_RANDOM = chrono::steady_clock::now().time_since_epoch().count();
        return splitmix64(x + FIXED_RANDOM);
    }
};

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    vector<vector<int>> divs(Maxn);
    for (int i = 2; i < Maxn; i++)
        if (divs[i].empty())
            for (int j = i; j < Maxn; j += i)
                divs[j].push_back(i);
    int T;
    cin >> T;
    while (T--) {
        int n;
        cin >> n;
        vector<int> a(n);
        unordered_map<long long, int, custom_hash> cnt;
        for (auto& x : a) {
            cin >> x;
            for (auto y : divs[x])
                ++cnt[y];
        }
        vector<int> b(n);
        for (auto& x : b)
            cin >> x;
        bool found = false;
        for (auto x : cnt | views::values)
            if (x > 1) {
                found = true;
                break;
            }
        if (found) {
            cout << "0\n";
            continue;
        }
        vector<int> tmp = b;
        ranges::sort(tmp);
        int best = tmp[0] + tmp[1];
        for (int i = 0; i < n; i++) {
            int x = a[i];
            for (int j = x + 1; j <= x + 1; j++) {
                bool found = false;
                for (auto d : divs[j])
                    if (cnt[d] > 0) {
                        found = true;
                        break;
                    }
                if (found) {
                    best = min(best, (j - x) * b[i]);
                    break;
                }
            }
        }
        ii mn = {Inf, Inf};
        for (int i = 0; i < n; i++)
            mn = min(mn, {b[i], i});
        int root = a[mn.second];
        for (int i = 0; i < n; i++)
            if (i != mn.second) {
                int x = a[i];
                for (auto d : divs[x]) {
                    int tk = (root - 1) / d * d + d - a[mn.second];
                    if (tk <= best / b[mn.second])
                        best = min(best, tk * b[mn.second]);
                }
            }
        cout << best << "\n";
    }
    return 0;
}
