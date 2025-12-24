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
        string s;
        cin >> n;
        cin >> s;
        int pnt = n - 1;
        while (pnt >= 0 && s[pnt] == ')')
            --pnt;
        int has = n - 1 - pnt;
        if (has > n - has)
            cout << "Yes\n";
        else cout << "No\n";
    }
    return 0;
}
