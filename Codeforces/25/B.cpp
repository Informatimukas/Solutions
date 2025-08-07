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
    int pnt = 0;
    while (n - pnt > 3) {
        cout << s.substr(pnt, 2) << "-";
        pnt += 2;
    }
    cout << s.substr(pnt) << "\n";
    return 0;
}
