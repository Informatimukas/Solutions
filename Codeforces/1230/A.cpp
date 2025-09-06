#include <bits/stdc++.h>
using namespace std;

constexpr int Maxb = 4;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    array<int, Maxb> a{};
    int sum = 0;
    for (auto& x : a) {
        cin >> x;
        sum += x;
    }
    for (int i = 0; i < 1 << Maxb; i++) {
        int got = 0;
        for (int j = 0; j < Maxb; j++)
            if (i & 1 << j)
                got += a[j];
        if (2 * got == sum) {
            cout << "YES\n";
            return 0;
        }
    }
    cout << "NO\n";
    return 0;
}