#include <bits/stdc++.h>
using namespace std;

bool Match(const vector<int>& a, const vector<int>& b, int k) {
    int lef = max(-1, static_cast<int>(a.size()) - k - 1);
    int rig = min(static_cast<int>(a.size()), k);
    for (int i = 0; i <= lef; i++)
        if (b[i] != -1 && a[i] != b[i])
            return false;
    for (int i = rig; i < a.size(); i++)
        if (b[i] != -1 && a[i] != b[i])
            return false;
    map<int, int> M;
    for (int i = lef + 1; i < rig; i++) {
        M[a[i]]++;
        if (b[i] != -1)
            M[b[i]]--;
    }
    for (auto& v : M | views::values)
        if (v < 0)
            return false;
    return true;
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    int T;
    cin >> T;
    while (T--) {
        int n, k;
        cin >> n >> k;
        vector<int> a(n);
        for (auto& x : a)
            cin >> x;
        vector<int> b(n);
        for (auto& x : b)
            cin >> x;
        cout << (Match(a, b, k) ? "YES" : "NO") << "\n";
    }
    return 0;
}
