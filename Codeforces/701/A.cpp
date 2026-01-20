#include <bits/stdc++.h>
using namespace std;

using ii = pair<int, int>;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    int n;
    cin >> n;
    vector<ii> seq(n);
    for (int i = 0; i < n; i++) {
        cin >> seq[i].first;
        seq[i].second = i;
    }
    ranges::sort(seq);
    for (int i = 0; i < n / 2; i++)
        cout << seq[i].second + 1 << " " << seq[n - 1 - i].second + 1 << "\n";
    return 0;
}
