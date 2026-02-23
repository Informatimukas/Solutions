#include <bits/stdc++.h>
using namespace std;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    int n, m;
    cin >> n >> m;
    vector taken(m + 1, false);
    for (int i = 0; i < n; i++) {
        int l;
        cin >> l;
        vector<int> seq(l);
        for (auto& x : seq)
            cin >> x;
        int res = 0;
        for (auto x : seq)
            if (!taken[x]) {
                taken[x] = true;
                res = x;
                break;
            }
        cout << res << "\n";
    }
    return 0;
}
