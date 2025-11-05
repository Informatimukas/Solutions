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
        if (s[0] != '1' || s[n - 1] != '1') {
            cout << "-1\n";
            continue;
        }
        list L = {n};
        for (int i = n - 1; i > 0; i--)
            if (s[i - 1] == '1')
                L.insert(L.begin(), i);
            else L.insert(next(L.begin()), i);
        for (auto it = L.begin(); it != L.end(); ++it) {
            if (it != L.begin())
                cout << " ";
            cout << *it;
        }
        cout << "\n";
    }
    return 0;
}
