#include <bits/stdc++.h>
using namespace std;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    int n;
    cin >> n;
    map<int, int> M;
    for (int i = 0; i < n; i++) {
        int a;
        cin >> a;
        M[a]++;
    }
    for (auto val : M | views::values)
        if (val > n - val + 1) {
            cout << "NO\n";
            return 0;
        }
    cout << "YES\n";
    return 0;
}
