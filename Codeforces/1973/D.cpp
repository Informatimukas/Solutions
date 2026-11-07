#include <bits/stdc++.h>
using namespace std;

int Ask(int l, int x) {
    cout << "? " << l << " " << x << endl;
    int res;
    cin >> res;
    return res;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    int T;
    cin >> T;
    while (T--) {
        int n, k;
        cin >> n >> k;
        int mx = n;
        while (Ask(1, n * mx) > n)
            --mx;
        int res = -1;
        for (int i = n / k; i > 0; i--) {
            int nxt = 1, cnt = 0;
            while (cnt < k && nxt <= n) {
                ++cnt;
                nxt = Ask(nxt, i * mx) + 1;
            }
            if (cnt == k && nxt == n + 1) {
                res = i * mx;
                break;
            }
        }
        cout << "! " << res << endl;
        int cor;
        cin >> cor;
    }
    return 0;
}
