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
        cout << (accumulate(s.begin(), s.end(), 0, [](int a, char ch) {
            return a + (ch == '(' ? 1 : -1);
        }) == 0 ? "YES" : "NO") << "\n";
    }
    return 0;
}
