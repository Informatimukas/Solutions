#include <bits/stdc++.h>
using namespace std;

using ii = pair<int, int>;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    int n;
    cin >> n;
    vector<ii> seq(n);
    for (int i = 0; i < n; i++) {
        cin >> seq[i].first;
        seq[i].second = i + 1;
    }
    ranges::sort(seq);
    if (seq.size() == 1 || seq.size() == 2 && seq[0].first == seq[1].first) {
        cout << "-1\n";
        return 0;
    }
    cout << "1\n" << seq[0].second << "\n";
    return 0;
}
