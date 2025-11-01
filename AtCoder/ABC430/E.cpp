#include <bits/stdc++.h>
using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    int T;
    cin >> T;
    while (T--) {
        string a, b;
        cin >> a >> b;
        int blen = b.length();
        b += a + a;
        vector Z(b.length(), 0);
        int l = -1, r = -1;
        int res = -1;
        for (int i = 1; i < b.length(); i++) {
            if (i <= r)
                Z[i] = min(r - i, Z[i - l]);
            while (i + Z[i] < b.length() && b[Z[i]] == b[i + Z[i]])
                Z[i]++;
            if (Z[i] >= blen && i >= blen) {
                res = i - blen;
                break;
            }
            if (i + Z[i] - 1 > r) {
                r = i + Z[i] - 1;
                l = i;
            }
        }
        cout << res << "\n";
    }
    return 0;
}