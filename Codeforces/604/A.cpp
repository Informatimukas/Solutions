#include <bits/stdc++.h>
using namespace std;

const vector probs = {500, 1000, 1500, 2000, 2500};

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    vector<int> m(probs.size());
    for (auto& x : m)
        cin >> x;
    vector<int> w(probs.size());
    for (auto& x : w)
        cin >> x;
    int res = 0;
    for (int i = 0; i < probs.size(); i++)
        res += max(3 * probs[i] / 10, (250 - m[i]) * probs[i] / 250 - 50 * w[i]);
    int hs, hu;
    cin >> hs >> hu;
    res += hs * 100 - hu * 50;
    cout << res << "\n";
    return 0;
}
