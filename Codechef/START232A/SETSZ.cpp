#include <bits/stdc++.h>
using namespace std;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    int n, q;
    cin >> n >> q;
    vector<int> a(n);
    for (auto& x : a)
        cin >> x;
    ranges::sort(a);
    map<int, int> M;
    for (int i = 0; i + 1 < a.size(); i++) {
        M[0]++;
        M[a[i + 1] - a[i]]--;
    }
    M[0]++;
    map<int, int> R, D;
    int lst = -1, delt = 0, val = 0;
    for (auto& [key, d] : M) {
        val += (key - lst) * delt;
        lst = key;
        delt += d;
        R[key] = val;
        D[key] = delt;
    }
    while (q--) {
        int x;
        cin >> x;
        auto it = M.upper_bound(x);
        --it;
        int key = it->first;
        cout << R[key] + (x - key) * D[key] << "\n";
    }
    return 0;
}
