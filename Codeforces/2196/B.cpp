#include <bits/stdc++.h>
using namespace std;

constexpr int Maxp = 450;

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
        int res = 0;
        for (int i = 0; i < n; i++) {
            cin >> a[i];
            if (a[i] >= Maxp)
                for (int j = 1; j * a[i] <= i; j++)
                    if (a[i - j * a[i]] == j)
                        res++;
        }
        for (int i = 0; i < n; i++)
            for (int j = 1; j < Maxp && i + j * a[i] < n; j++)
                if (a[i + j * a[i]] == j)
                    res++;
        cout << res << "\n";
    }
    return 0;
}
