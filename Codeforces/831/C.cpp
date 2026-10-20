#include <bits/stdc++.h>
using namespace std;

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
    int k, n;
    cin >> k >> n;
    int cur = 0;
    set<int> A;
    for (int i = 0; i < k; i++) {
        int a;
        cin >> a;
        cur += a;
        A.insert(cur);
    }
    set<int> B;
    for (int i = 0; i < n; i++) {
        int b;
        cin >> b;
        B.insert(b);
    }
    unordered_map<long long, int, custom_hash> M;
    for (auto a : A)
        for (auto b : B)
            M[b - a]++;
    int res = 0;
    for (auto val : M | views::values)
        res += val >= n;
    cout << res << "\n";
    return 0;
}
