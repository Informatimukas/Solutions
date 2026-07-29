#include <bits/stdc++.h>
using namespace std;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    array<int, 6> a;
    for (auto& x : a)
        cin >> x;
    for (int i = 0; i < 1 << a.size(); i++)
        if (__builtin_popcount(i) == 3) {
            int res1 = 0, res2 = 0;
            for (int j = 0; j < a.size(); j++)
                if (i & 1 << j)
                    res1 += a[j];
                else res2 += a[j];
            if (res1 == res2) {
                cout << "YES\n";
                return 0;
            }
        }
    cout << "NO\n";
    return 0;
}
