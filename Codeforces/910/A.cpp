#include <bits/stdc++.h>
using namespace std;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    int n, d;
    cin >> n >> d;
    string s;
    cin >> s;
    int cur = 0;
    int res = 0;
    while (cur < n - 1) {
        int nxt = cur;
        for (int i = min(n - 1, cur + d); i > cur; --i)
            if (s[i] == '1') {
                nxt = i;
                break;
            }
        if (nxt == cur) {
            cout << "-1\n";
            return 0;
        }
        ++res;
        cur = nxt;
    }
    cout << res << "\n";
    return 0;
}
