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
        int res = 0;
        for (int i = 0, j; i < n; i = j) {
            j = i;
            while (j < n && s[i] == s[j])
                j++;
            if (s[i] == '#')
                res = max(res, j - i);
        }
        cout << (res + 1) / 2 << "\n";
    }
    return 0;
}
