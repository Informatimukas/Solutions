#include <bits/stdc++.h>
using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    int T;
    cin >> T;
    while (T--) {
        int n;
        cin >> n;
        vector<int> a(n), b(n);
        for (auto& i : a)
            cin >> i;
        for (auto& i : b)
            cin >> i;
        int A = 0;
        for (int i = 0; i < n; i++)
            if (a[i] > b[i])
                A += a[i] - b[i];
        cout << A + 1 << "\n";
    }
    return 0;
}