#include <bits/stdc++.h>
using namespace std;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    int n;
    cin >> n;
    set<int> S;
    int mx = 0;
    for (int i = 0; i < 2 * n; i++) {
        int a;
        cin >> a;
        if (S.contains(a))
            S.erase(a);
        else S.insert(a);
        mx = max(mx, static_cast<int>(S.size()));
    }
    cout << mx << "\n";
    return 0;
}
