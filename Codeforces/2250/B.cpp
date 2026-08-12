#include <bits/stdc++.h>
using namespace std;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    int T;
    cin >> T;
    while (T--) {
        int n, k;
        cin >> n >> k;
        if (k == n - 1) {
            cout << "-1\n";
            continue;
        }
        int dif = n - k;
        int sam2 = (k + 1) / 2;
        int sam1 = k / 2;
        cout << "0";
        while (sam1--)
            cout << "0";
        cout << "1";
        while (sam2--)
            cout << "1";
        for (int i = 2; i < dif; i++)
            cout << (i % 2 == 0 ? '0' : '1');
        cout << "\n";
    }
    return 0;
}
