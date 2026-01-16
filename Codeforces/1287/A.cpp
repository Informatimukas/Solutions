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
        string s;
        cin >> s;
        int lst = -1;
        int res = 0;
        for (int i = 0; i < n; i++)
            if (s[i] == 'A')
                lst = i;
            else if (lst != -1)
                res = max(res, i - lst);
        cout << res << "\n";
    }

    return 0;
}
