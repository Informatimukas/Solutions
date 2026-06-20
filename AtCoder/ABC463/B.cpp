#include <bits/stdc++.h>
using namespace std;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    int n;
    char ch;
    cin >> n >> ch;
    int ind = ch - 'A';
    while (n--) {
        string s;
        cin >> s;
        if (s[ind] == 'o') {
            cout << "Yes\n";
            return 0;
        }
    }
    cout << "No\n";
    return 0;
}
