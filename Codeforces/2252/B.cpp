#include <bits/stdc++.h>
using namespace std;

constexpr int Inf = 1000000000;

int Cand(const array<int, 2>& cnt) {
    return max(cnt[0], cnt[1]) - min(cnt[0], cnt[1]) <= 1 ?
        cnt[0] + cnt[1] : Inf;
}

int Solve(const string& s, int need) {
    array<int, 2> cnt{};
    for (auto ch : s)
        cnt[ch - '0']++;
    int res = Cand(cnt);
    for (auto ch : s)
        if (ch - '0' == need) {
            cnt[need]--;
            res = min(res, Cand(cnt));
            need = 1 - need;
        }
    return res;
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
        string s;
        cin >> s;
        int res = min(Solve(s, 0), Solve(s, 1));
        cout << (res < Inf ? res : -1) << "\n";
    }
    return 0;
}
