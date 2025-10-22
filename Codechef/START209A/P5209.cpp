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
        string r = s;
        ranges::reverse(r);
        if (ranges::is_sorted(s) || ranges::is_sorted(r))
            cout << "Bob\n";
        else cout << "Alice\n";
    }
    return 0;
}
