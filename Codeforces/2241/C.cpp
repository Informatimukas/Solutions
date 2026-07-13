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
        int cnt = 0;
        for (int i = 0, j; i < s.length(); i = j) {
            j = i;
            while (j < s.length() && s[i] == s[j])
                j++;
            cnt++;
        }
        if (cnt == 1 || cnt > 2)
            cout << "1\n";
        else cout << "2\n";
    }
    return 0;
}
