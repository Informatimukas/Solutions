#include <bits/stdc++.h>
using namespace std;

using ii = pair<int, int>;

constexpr int Maxn = 1000005;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    int n;
    cin >> n;
    vector<ii> cnt(Maxn);
    for (int i = 0; i < n; i++) {
        int a;
        cin >> a;
        ++cnt[a].first;
        cnt[a].second = -i;
    }
    int mx = 1;
    for (int i = 1; i < Maxn; i++)
        if (cnt[i] > cnt[mx])
            mx = i;
    cout << mx << "\n";
    return 0;
}
