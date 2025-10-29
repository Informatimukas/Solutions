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
        vector<int> a(n);
        bool odd = false, ev = false;
        for (auto& x : a) {
            cin >> x;
            if (x % 2) odd = true;
            else ev = true;
        }
        if (odd && ev)
            ranges::sort(a);
        for (int i = 0; i < a.size(); i++)
            cout << a[i] << (i + 1 < a.size() ? ' ' : '\n');
    }
    return 0;
}
