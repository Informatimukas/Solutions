#include <bits/stdc++.h>
using namespace std;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    int T;
    cin >> T;
    while (T--) {
        int n, k;
        cin >> n >> k;
        string s;
        cin >> s;
        int res = 0;
        for (int i = 0; i < n; i += k)
            res += s.substr(i, k) == string(k, '1');
        cout << res << "\n";
    }
    return 0;
}
