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
        cout << ranges::count_if(s, [&](char ch) {
            return ch != s[n - 1];
        }) << "\n";
    }
    return 0;
}
