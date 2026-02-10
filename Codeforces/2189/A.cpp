#include <bits/stdc++.h>
using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    int T;
    cin >> T;
    while (T--) {
        int n, h, l;
        cin >> n >> h >> l;
        int both = 0, one = 0;
        for (int i = 0; i < n; i++) {
            int a;
            cin >> a;
            if (a <= h && a <= l)
                both++;
            else if (a <= h || a <= l)
                one++;
        }
        int tk = min(one, both);
        cout << tk + (both - tk) / 2 << "\n";
    }
    return 0;
}