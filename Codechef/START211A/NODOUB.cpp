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
        vector<int> a(n);
        for (auto& x : a)
            cin >> x;
        ranges::sort(a);
        if (a.size() > 2)
            swap(a[0], a[n - 2]);
        for (int i = a.size() - 1; i >= 0; i--)
            cout << a[i] << (i - 1 >= 0 ? ' ' : '\n');
    }
    return 0;
}