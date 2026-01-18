#include <bits/stdc++.h>
using namespace std;

using ll = long long;

void Add(vector<int>& BIT, int x) {
    for (int i = x; i < BIT.size(); i += i & -i)
        BIT[i]++;
}

int Get(const vector<int>& BIT, int x) {
    int res = 0;
    for (int i = x; i > 0; i -= i & -i)
        res += BIT[i];
    return res;
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    int n;
    cin >> n;
    string s;
    cin >> s;
    vector BIT(2 * n + 5, 0);
    int cur = n + 1;
    Add(BIT, cur);
    ll res = 0;
    for (auto ch : s) {
        if (ch == 'A')
            ++cur;
        else if (ch == 'B')
            --cur;
        res += Get(BIT, cur - 1);
        Add(BIT, cur);
    }
    cout << res << "\n";
    return 0;
}
