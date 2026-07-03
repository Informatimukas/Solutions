#include <bits/stdc++.h>
using namespace std;

constexpr int Inf = 1000000007;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    int n;
    cin >> n;
    int res = Inf;
    int lst = -1;
    string s;
    cin >> s;
    for (int i = 0; i < n; i++) {
        int x;
        cin >> x;
        if (s[i] == 'L' && lst != -1)
            res = min(res, (x - lst) / 2);
        if (s[i] == 'R')
            lst = x;
    }
    cout << (res >= Inf ? -1 : res) << "\n";
    return 0;
}
