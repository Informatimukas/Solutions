#include <bits/stdc++.h>
using namespace std;

constexpr int Maxm = 1000006;

bool Win(const vector<int>& a, const vector<int>& mx) {
    if (ranges::is_sorted(a))
        return false;
    int cur = 1;
    for (auto x : a)
        if (x == 1) {
            if (cur > 1)
                return true;
        } else while (x > 1) {
            if (cur > mx[x])
                return true;
            cur = mx[x];
            x /= mx[x];
        }
    return false;
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    vector<int> mx(Maxm);
    for (int i = 2; i < Maxm; i++)
        if (mx[i] == 0)
            for (int j = i; j < Maxm; j += i)
                mx[j] = i;
    int T;
    cin >> T;
    while (T--) {
        int n;
        cin >> n;
        vector<int> a(n);
        for (auto& x : a)
            cin >> x;
        cout << (Win(a, mx) ? "Alice" : "Bob") << "\n";
    }
    return 0;
}
