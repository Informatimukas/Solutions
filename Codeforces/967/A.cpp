#include <bits/stdc++.h>
using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    int n, s;
    cin >> n >> s;
    vector<int> seq;
    for (int i = 0; i < n; i++) {
        int h, m;
        cin >> h >> m;
        seq.push_back(h * 60 + m);
    }
    for (int i = 0; ; i++) {
        auto it = ranges::lower_bound(seq, i);
        if (it != seq.end() && *it - i <= s)
            continue;
        if (it != seq.begin() && i - *prev(it) <= s)
            continue;
        cout << i / 60 << " " << i % 60 << "\n";
        return 0;
    }
    return 0;
}
