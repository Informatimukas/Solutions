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
        vector<int> res(n);
        int cur = 0;
        for (int i = 0; i < res.size(); i += 2)
            res[i] = ++cur;
        for (int i = 1; i < res.size(); i += 2)
            res[i] = ++cur;
        for (int i = 0; i < res.size(); i++)
            cout << res[i] << (i + 1 < res.size() ? ' ' : '\n');
    }
    return 0;
}
