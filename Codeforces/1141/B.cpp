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
    int res = 0, cur = 0;
    for (int i = 0; i < 2; i++)
        for (auto x : a) {
            if (x)
                ++cur;
            else cur = 0;
            res = max(res, cur);
        }
    cout << res << "\n";
    return 0;
}
