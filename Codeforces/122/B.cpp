#include <bits/stdc++.h>
using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    string s;
    cin >> s;
    int t4 = 0, t7 = 0;
    for (auto& x : s)
        if (x == '4')
            t4++;
        else if (x == '7')
            t7++;
    int res = -1;
    if (t4 || t7)
        res = t4 >= t7 ? 4 : 7;
    cout << res << "\n";
    return 0;
}