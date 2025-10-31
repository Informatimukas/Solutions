#include <bits/stdc++.h>
using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    int T;
    cin >> T;
    while (T--) {
        int n;
        cin >> n;
        if (n == 0) {
            cout << "YES\n";
            continue;
        }
        while (n % 2 == 0)
            n /= 2;
        string s;
        while (n) {
            s += string(1, '0' + n % 2);
            n /= 2;
        }
        string r = s;
        ranges::reverse(r);
        cout << (s == r && ranges::count(s, '1') % 2 == 0? "YES" : "NO") << "\n";
    }
    return 0;
}