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
        vector<int> b(n);
        for (auto& x : b)
            cin >> x;
        array<array<int, 2>, 2> cnt{};
        for (int i = 0; i < n; i++)
            cnt[a[i]][b[i]]++;
        if (cnt[1][0] == 0 && cnt[0][1] == 0)
            cout << "0\n";
        else if (cnt[1][0] % 2)
            cout << "1\n";
        else if (cnt[1][0] > 0 || cnt[0][0] > 0 && cnt[1][1] > 0)
            cout << "2\n";
        else cout << "-1\n";
    }
    return 0;
}
