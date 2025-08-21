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
        ranges::sort(s, [](char a, char b) {
            return (a == 'T') > (b == 'T');
        });
        cout << s << "\n";
    }
    return 0;
}
