#include <bits/stdc++.h>
using namespace std;

bool Check(const vector<int>& a) {
    int l = 1, r = a.size() - 1;
    while (l < r)
        if (a[l] == l)
            l++;
        else if (a[r] == r)
            r--;
        else if (a[l] == r && a[r] == l)
            l++, r--;
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
        vector<int> a(n + 1);
        for (int i = 1; i <= n; i++)
            cin >> a[i];
        cout << (Check(a) ? "YES" : "NO") << "\n";
    }
    return 0;
}
