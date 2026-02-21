#include <bits/stdc++.h>
using namespace std;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    int n, d;
    cin >> n >> d;
    int cur = 0, mx = 0;
    string all = string(n, '1');
    for (int i = 0; i < d; i++) {
        string s;
        cin >> s;
        if (s == all)
            cur = 0;
        else cur++;
        mx = max(mx, cur);
    }
    cout << mx << "\n";
    return 0;
}
