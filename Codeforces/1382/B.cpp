#include <bits/stdc++.h>
using namespace std;

bool Win(const vector<int>& a, int lvl) {
    if (lvl >= a.size())
        return false;
    if (a[lvl] >= 2)
        return true;
    return !Win(a, lvl + 1);
}

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
        for (auto& x : a)
            cin >> x;
        cout << (Win(a, 0) ? "First" : "Second") << "\n";
    }
    return 0;
}
