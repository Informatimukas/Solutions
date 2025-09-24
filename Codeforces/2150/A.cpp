#include <bits/stdc++.h>
using namespace std;

int getWhite(const set<int>& black, int x) {
    x++;
    while (black.contains(x))
        x++;
    return x;
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    int T;
    cin >> T;
    while (T--) {
        int n, m;
        cin >> n >> m;
        string s;
        cin >> s;
        set<int> black;
        for (int i = 0; i < m; i++) {
            int x;
            cin >> x;
            black.insert(x);
        }
        int lst = 1;
        for (int i = 0; i < s.length(); i++) {
            lst = (i == 0 || s[i - 1] == 'A') ? lst : getWhite(black, lst);
            if (s[i] == 'A') lst++;
            else lst = getWhite(black, lst);
            black.insert(lst);
        }
        cout << black.size() << "\n";
        for (auto& x : black) {
            if (x != *black.begin())
                cout << " ";
            cout << x;
        }
        cout << "\n";
    }
    return 0;
}
