#include <bits/stdc++.h>
using namespace std;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    int T;
    cin >> T;
    while (T--) {
        int n;
        cin >> n;
        int zer = 0, neg = 0;
        for (int i = 0; i < n; i++) {
            int a;
            cin >> a;
            if (a == 0) zer++;
            else if (a < 0) neg++;
        }
        int res = zer;
        if (neg % 2) res += 2;
        cout << res << "\n";
    }
    return 0;
}
