#include <bits/stdc++.h>
using namespace std;

int Steps(int b, int mask, int cur) {
    set<int> S;
    int step = 0;
    while (cur != 0) {
        step++;
        while (!(cur & 1 << b))
            cur <<= 1;
        if (!S.insert(cur).second)
            return step;
        cur ^= mask;
    }
    return step;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    int mx = 0;
    constexpr int Maxb = 20;
    mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());
    while (true) {
        int i = uniform_int_distribution(1 << (Maxb - 1), (1 << Maxb) - 1)(rng);
        int j = uniform_int_distribution(0, (1 << (Maxb - 1)) - 1)(rng);
        int got = Steps(Maxb - 1, i, j);
        if (got > mx) {
            mx = got;
            cout << "mx = " << mx << ", i = " << i << ", j = " << j << endl;
        }
    }
    return 0;
}