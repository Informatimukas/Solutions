#include <bits/stdc++.h>
using namespace std;

using ii = pair<int, int>;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    int T;
    cin >> T;
    while (T--) {
        int n, k;
        cin >> n >> k;
        vector<ii> seq(n);
        for (int i = 0; i < n; i++)
            seq[i] = {0, i + 1};
        for (int j = 1; j <= n; j++) {
            int a;
            cin >> a;
            seq[a - 1].first = j;
        }
        ranges::sort(seq);
        for (int i = 0; i < k; i++)
            cout << seq[i].second << (i + 1 < k ? ' ' : '\n');
    }
    return 0;
}