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
        int l = 1, r = n;
        bool rig = true;
        for (int i = n - 1; i >= 0; i--) {
            if (rig)
                a[i] = r--;
            else a[i] = l++;
            rig = !rig;
        }
        for (int i = 0; i < n; i++)
            cout << a[i] << (i + 1 < n ? ' ' : '\n');
    }
    return 0;
}
