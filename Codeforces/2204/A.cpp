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
        int pnt = 0;
        while (s[pnt] == 'R')
            pnt++;
        cout << pnt + 1 << "\n";
    }
    return 0;
}
