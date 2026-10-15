#include <bits/stdc++.h>
using namespace std;

using ii = pair<int, int>;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
    int n, k;
    cin >> n >> k;
    vector<ii> a(n);
    for (int i = 0; i < n; i++) {
        cin >> a[i].first;
        a[i].second = i + 1;
    }
    ranges::sort(a, greater());
    cout << a[k - 1].first << "\n";
    for (int i = 0; i < k; i++)
        cout << a[i].second << (i + 1 < k ? ' ' : '\n');
    return 0;
}
