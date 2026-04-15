#include <bits/stdc++.h>
using namespace std;

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
        int sum = 0;
        for (auto& x : a) {
            cin >> x;
            sum += x;
        }
        if (sum % 2 || n * k % 2 == 0)
            cout << "YES\n";
        else cout << "NO\n";
    }
    return 0;
}
