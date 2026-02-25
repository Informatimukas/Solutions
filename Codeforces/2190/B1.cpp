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
        string t = s;
        int lef = 0;
        while (s[lef] == '(')
            ++lef;
        int rig = s.length() - 1;
        while (s[rig] == ')')
            --rig;
        if (lef > rig)
            swap(lef, rig);
        t.erase(t.begin() + rig);
        t.erase(t.begin() + lef);
        if (t < s && s.substr(0, t.length()) != t)
            cout << t.length() << "\n";
        else cout << "-1\n";
    }
    return 0;
}
