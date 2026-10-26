#include <bits/stdc++.h>
using namespace std;

constexpr int Maxd = 4;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    int n, q;
    cin >> n >> q;
    string s;
    cin >> s;
    vector<array<int, Maxd>> sum(n);
    for (int i = 1; i < n; i++) {
        ranges::copy(sum[i - 1], sum[i].begin());
        sum[i][(s[i - 1] - '0') << 1 | (s[i] - '0')]++;
    }
    while (q--) {
        int l, r;
        cin >> l >> r;
        l--; r--;
        array<int, Maxd> my{};
        for (int d = 0; d < Maxd; d++)
            my[d] = sum[r][d] - sum[l][d];
        my[(s[r] - '0') << 1 | (s[l] - '0')]++;
        int res = 0;
        if (my[0] > my[3])
            swap(my[3], my[0]);
        if (my[3] > my[0] && my[3] > my[1]) {
            int d = min(my[3] - my[0], (my[3] - my[1]) / 2);
            my[3] -= d;
            my[1] += d;
            res += d;
        }
        if (my[0] == my[3] && my[3] > my[1]) {
            int d = (my[3] - my[1]) / 3;
            my[1] += 2 * d;
            my[0] -= d;
            my[3] -= d;
            res += 2 * d;
        }
        while (true) {
            if (my[3] > my[1]) {
                my[1]++;
                my[3]--;
                res++;
            } else break;
            if (my[0] > my[3])
                swap(my[0], my[3]);
        }
        if (my[0] < my[1])
            res += my[1] - my[0];
        if (my[3] < my[1])
            res += my[1] - my[3];
        cout << res << "\n";
    }
    return 0;
}
