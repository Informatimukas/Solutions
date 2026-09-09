#include <bits/stdc++.h>
using namespace std;

using ll = long long;

constexpr int Maxb = 30;

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

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    int T;
    cin >> T;
    while (T--) {
        int a, b, d;
        cin >> a >> b >> d;
        unordered_map<long long, int, custom_hash> safe_map;
        for (int i = 0; i < 1 << 15; i++) {
            ll wra = (((a >> 15) | i) << 15) % d;
            ll wrb = (((b >> 15) | i) << 15) % d;
            safe_map.emplace(wra << 30 | wrb, i);
        }
        bool ok = false;
        ll all = (1 << 15) - 1;
        ll x;
        for (int i = 0; i < 1 << 15; i++) {
            ll wra = ((a & all) | i) % d;
            ll wrb = ((b & all) | i) % d;
            wra = (d - wra) % d;
            wrb = (d - wrb) % d;
            if (safe_map.contains(wra << 30 | wrb)) {
                ok = true;
                x = i | safe_map[wra << 30 | wrb] << 15;
                break;
            }
        }
        cout << (ok ? x : -1) << "\n";
    }
    return 0;
}
