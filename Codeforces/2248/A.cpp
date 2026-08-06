#include <bits/stdc++.h>
using namespace std;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    int T;
    cin >> T;
    while (T--) {
        string s;
        cin >> s;
        for (int i = 0; i < 2; i++) {
            int pnt = 0;
            while (s[pnt] != '0' + i)
                pnt++;
            s.erase(s.begin() + pnt);
        }
        cout << s << "\n";
    }
    return 0;
}
