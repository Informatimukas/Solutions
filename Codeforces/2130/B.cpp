#include <bits/stdc++.h>
using namespace std;

void Print(const vector<int>& seq, vector<int>& cnt) {
    for (auto& x: seq)
        while (cnt[x]--)
            cout << x << " ";
    cout << "\n";
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    int T;
    cin >> T;
    while (T--) {
        int n, s;
        cin >> n >> s;
        vector cnt(3, 0);
        for (int i = 0; i < n; i++) {
            int a;
            cin >> a;
            cnt[a]++;
        }
        int got = cnt[1] + 2 * cnt[2];
        if (got > s) {
            Print({0, 1, 2}, cnt);
            continue;
        }
        if (got == s || got + 1 < s) {
            cout << "-1\n";
            continue;
        }
        Print({0, 2, 1}, cnt);
    }
    return 0;
}
