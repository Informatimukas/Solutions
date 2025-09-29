#include <bits/stdc++.h>
using namespace std;

using ii = pair<int, int>;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    int n;
    cin >> n;
    vector<ii> seq(n);
    for (auto& [fir, sec] : seq)
        cin >> fir >> sec;
    int mx = max(seq[0].first, seq[0].second);
    for (int i = 1; i < n; i++) {
        if (seq[i].first > seq[i].second)
            swap(seq[i].first, seq[i].second);
        if (seq[i].second <= mx)
            mx = seq[i].second;
        else if (seq[i].first <= mx)
            mx = seq[i].first;
        else {
            cout << "NO\n";
            return 0;
        }
    }
    cout << "YES\n";
    return 0;
}