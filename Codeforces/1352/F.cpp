#include <bits/stdc++.h>
using namespace std;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    int T;
    cin >> T;
    while (T--) {
        int n0, n1, n2;
        cin >> n0 >> n1 >> n2;
        if (n1 == 0) {
            if (n0 > 0) {
                cout << string(n0 + 1, '0') << "\n";
                continue;
            }
            cout << string(n2 + 1, '1') << "\n";
            continue;
        }
        cout << string(n0 + 1, '0') << string(n2 + 1, '1');
        char cur = '0', oth = '1';
        for (int i = 2; i <= n1; i++) {
            cout << cur;
            swap(cur, oth);
        }
        cout << "\n";
    }
    return 0;
}
