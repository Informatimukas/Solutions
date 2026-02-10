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
        for (auto& x : a)
            cin >> x;
        if (a[0] == 0 && a.back() == 0)
            cout << "Bob\n";
        else cout << "Alice\n";
    }
    return 0;
}
