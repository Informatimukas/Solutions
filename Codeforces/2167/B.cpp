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
        string s, t;
        cin >> n >> s >> t;
        ranges::sort(s);
        ranges::sort(t);
        cout << (s == t ? "YES" : "NO") << "\n";
    }
    return 0;
}
