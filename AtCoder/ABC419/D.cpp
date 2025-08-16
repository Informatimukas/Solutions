#include <bits/stdc++.h>
using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    int n, m;
    cin >> n >> m;
    string s, t;
    cin >> s >> t;
    vector dif(n + 1, false);
    while (m--) {
        int l, r;
        cin >> l >> r;
        dif[l - 1] = !dif[l - 1];
        dif[r] = !dif[r];
    }
    bool sam = true;
    for (int i = 0; i < n; i++) {
        sam ^= dif[i];
        if (!sam) swap(s[i], t[i]);
    }
    cout << s << "\n";
    return 0;
}