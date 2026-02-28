#include <bits/stdc++.h>
using namespace std;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    string s;
    cin >> s;
    int a = 0, b = 0, c = 0;
    for (auto ch : s)
        if (ch == 'A')
            ++a;
        else if (ch == 'B' && a > 0) {
            --a;
            ++b;
        } else if (ch == 'C' && b > 0) {
            --b;
            ++c;
        }
    cout << c << "\n";
    return 0;
}
