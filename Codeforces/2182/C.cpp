#include <bits/stdc++.h>
using namespace std;

using ll = long long;

int Count(const vector<int>& a, const vector<int>& b) {
    int res = 0;
    for (int i = 0; i < a.size(); i++) {
        bool ok = true;
        for (int j = 0; j < a.size(); j++)
            if (a[j] >= b[(i + j) % b.size()]) {
                ok = false;
                break;
            }
        res += ok;
    }
    return res;
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    int T;
    cin >> T;
    while (T--) {
        int n;
        cin >> n;
        array<vector<int>, 3> a;
        for (auto& V : a) {
            V.resize(n);
            for (auto& el : V)
                cin >> el;
        }
        cout << static_cast<long long>(n) * Count(a[0], a[1]) * Count(a[1], a[2]) << "\n";
    }
    return 0;
}
