#include <bits/stdc++.h>
using namespace std;

void Add(vector<int>& bas, int x) {
    for (int i = bas.size() - 1; i >= 0; i--)
        if (x & 1 << i)
            if (bas[i]) x ^= bas[i];
            else {
                bas[i] = x;
                break;
            }
}

int Solve(const vector<int>& a, int k) {
    constexpr int Maxb = 30;
    vector bas(Maxb, 0);
    if (k == a.size()) {
        int num = 0;
        for (int i = 0; i < k; i++)
            num ^= a[i];
        Add(bas, num);
    } else if (k % 2 == 0) {
        for (auto& x : a)
            Add(bas, x ^ a[0]);
    } else for (auto& x : a)
        Add(bas, x);
    int res = 1;
    for (int i = 0; i < bas.size(); i++)
        if (bas[i]) res *= 2;
    return res;
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    int T;
    cin >> T;
    while (T--) {
        int n, k;
        cin >> n >> k;
        vector<int> a(n);
        for (auto& x : a)
            cin >> x;
        cout << Solve(a, k) << "\n";
    }
    return 0;
}
