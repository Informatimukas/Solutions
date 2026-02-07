#include <bits/stdc++.h>
using namespace std;

bool Check(const vector<int>& seq, int l, int r, int need) {
    if ((r - l + 1) % 2)
        return false;
    while (l < r) {
        if (seq[l] + seq[r] != need)
            return false;
        ++l; --r;
    }
    return true;
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    int n;
    cin >> n;
    vector<int> a(n);
    for (auto& x : a)
        cin >> x;
    ranges::sort(a);
    int lst = a.size() - 1;
    while (lst >= 0 && a.back() == a[lst])
        --lst;
    vector<int> res;
    if (lst < 0 || Check(a, 0, lst, a.back()))
        res.push_back(a.back());
    if (a.size() >= 2 && Check(a, 1, a.size() - 2, a[0] + a.back()))
        res.push_back(a[0] + a.back());
    for (int i = 0; i < res.size(); i++)
        cout << res[i] << (i + 1 < res.size() ? ' ' : '\n');
    return 0;
}
