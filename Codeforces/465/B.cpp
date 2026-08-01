#include <bits/stdc++.h>
using namespace std;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    int n;
    cin >> n;
    vector<int> a(n);
    for (auto& x : a)
        cin >> x;
    int res = 0, cnt = 0;
    for (int i = 0; i < n; i++)
        if (a[i] == 1) {
            res++;
            if (i == 0 || a[i - 1] == 0)
                cnt++;
        }
    res += max(0, cnt - 1);
    cout << res << "\n";
    return 0;
}
