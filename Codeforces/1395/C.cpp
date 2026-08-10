#include <bits/stdc++.h>
using namespace std;

bool Check(int mask, const vector<int>& a, const vector<int>& b) {
    for (auto x : a) {
        bool ok = false;
        for (auto y : b) {
            int num = (x & y);
            if ((mask & num) == num) {
                ok = true;
                break;
            }
        }
        if (!ok)
            return false;
    }
    return true;
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    int n, m;
    cin >> n >> m;
    vector<int> a(n);
    vector<int> b(m);
    for (auto& x : a)
        cin >> x;
    for (auto& x : b)
        cin >> x;
    for (int i = 0; i < 1 << 9; i++)
        if (Check(i, a, b)) {
            cout << i << "\n";
            break;
        }
    return 0;
}
