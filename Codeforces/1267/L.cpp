#include <bits/stdc++.h>
using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    int n, l, k;
    cin >> n >> l >> k;
    string s;
    cin >> s;
    ranges::sort(s);
    vector<string> B(n);
    for (int i = 0; i < n; i++)
        B[i].resize(l, '?');
    int lef = 0, rig = k - 1, pnt = 0;
    for (int j = 0; j < l; j++) {
        for (int i = lef; i <= rig; i++)
            B[i][j] = s[pnt++];
        lef = rig;
        while (lef > 0 && B[lef - 1][j] == B[rig][j])
            lef--;
    }
    for (int j = 0; j < l; j++)
        for (int i = 0; i < n; i++)
            if (B[i][j] == '?')
                B[i][j] = s[pnt++];
    for (int i = 0; i < n; i++)
        cout << B[i] << "\n";
    return 0;
}
