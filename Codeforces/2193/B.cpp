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
        vector<int> a(n);
        for (auto& x : a)
            cin >> x;
        int nd = n;
        for (int i = 0; i < n; i++) {
            if (a[i] != nd) {
                int j = i + 1;
                while (a[j] != nd)
                    j++;
                reverse(a.begin() + i, a.begin() + j + 1);
                break;
            }
            --nd;
        }
        for (int i = 0; i < n; i++)
            cout << a[i] << (i + 1 < n ? ' ' : '\n');
    }
    return 0;
}
