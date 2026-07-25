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
        n *= 2;
        vector<int> a(n);
        for (auto& x : a)
            cin >> x;
        int res = 0;
        for (int i = 0; i < n; i++) {
            int j = 1;
            set S = {a[i]};
            while (i - j >= 0 && i + j < n && a[i - j] == a[i + j]) {
                S.insert(a[i - j]);
                j++;
            }
            int num = 0;
            while (S.contains(num))
                num++;
            res = max(res, num);
        }
        for (int i = 0; i + 1 < n; i++)
            if (a[i] == a[i + 1]) {
                int j = 1;
                set S = {a[i]};
                while (i - j >= 0 && i + 1 + j < n && a[i - j] == a[i + 1 + j]) {
                    S.insert(a[i - j]);
                    j++;
                }
                int num = 0;
                while (S.contains(num))
                    num++;
                res = max(res, num);
            }
        cout << res << "\n";
    }
    return 0;
}
