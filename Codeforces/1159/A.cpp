#include <bits/stdc++.h>
using namespace std;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    int n;
    cin >> n;
    string s;
    cin >> s;
    int res = 0;
    for (auto ch : s)
        if (ch == '+')
            ++res;
        else if (ch == '-')
            res = max(res - 1, 0);
    cout << res << "\n";
    return 0;
}
