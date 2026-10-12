#include <bits/stdc++.h>
using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    int v;
    cin >> v;
    vector<int> seq(10);
    for (int i = 1; i < seq.size(); i++)
        cin >> seq[i];
    int mn = *ranges::min_element(seq.begin() + 1, seq.end());
    int d = v / mn;
    if (d == 0) {
        cout << "-1\n";
        return 0;
    }
    for (int i = d - 1; i >= 0; i--)
        for (int j = 9; j > 0; j--)
            if (v >= i * mn + seq[j]) {
                cout << j;
                v -= seq[j];
                break;
            }
    cout << "\n";
    return 0;
}
