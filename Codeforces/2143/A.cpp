#include <bits/stdc++.h>
using namespace std;

bool Check(const vector<int>& seq) {
    int need = 1;
    int l = 0, r = seq.size() - 1;
    while (l <= r)
        if (seq[l] == need) { l++; need++; }
        else if (seq[r] == need) { r--; need++; }
        else return false;
    return true;
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
        cout << (Check(a)? "YES" : "NO") << "\n";
    }
    return 0;
}
