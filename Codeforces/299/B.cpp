#include <bits/stdc++.h>
using namespace std;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    int n, k;
    cin >> n >> k;
    string s;
    cin >> s;
    int cnt = 0;
    for (auto c : s)
        if (c == '#') {
            if (++cnt >= k) {
                cout << "NO\n";
                return 0;
            }
        } else cnt = 0;
    cout << "YES\n";
    return 0;
}
