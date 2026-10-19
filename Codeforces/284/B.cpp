#include <bits/stdc++.h>
using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    int n;
    cin >> n;
    string s;
    cin >> s;
    int cnt = ranges::count(s, 'I');
    int res = 0;
    for (auto ch : s)
        if (ch != 'F') {
            cnt -= ch == 'I';
            res += cnt == 0;
            cnt += ch == 'I';
        }
    cout << res << "\n";
    return 0;
}
