#include <bits/stdc++.h>
using namespace std;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    int n, m;
    cin >> n >> m;
    string s, t;
    cin >> s;
    cin >> t;
    int q;
    cin >> q;
    while (q--) {
        string a;
        cin >> a;
        bool okS = true, okT = true;
        for (auto ch : a) {
            if (s.find(ch) == string::npos)
                okS = false;
            if (t.find(ch) == string::npos)
                okT = false;
        }
        if (okS && !okT)
            cout << "Takahashi\n";
        else if (okT && !okS)
            cout << "Aoki\n";
        else cout << "Unknown\n";
    }
    return 0;
}
