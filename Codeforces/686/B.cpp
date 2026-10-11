#include <bits/stdc++.h>
using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    int n;
    cin >> n;
    vector<int> a(n + 1);
    for (int i = 1; i <= n; i++)
        cin >> a[i];
    for (int i = 1; i <= n; i++)
        for (int j = 1; j + 1 <= n; j++)
            if (a[j] > a[j + 1]) {
                cout << j << " " << j + 1 << "\n";
                swap(a[j], a[j + 1]);
            }
    return 0;
}
