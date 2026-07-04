#include <bits/stdc++.h>
using namespace std;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    int n;
    cin >> n;
    string s;
    cin >> s;
    vector<int> tims(n);
    int cur = 0;
    for (int i = n - 1; i >= 0; i--) {
        if (s[i] == 'o')
            cur++;
        tims[i] = cur;
    }
    deque<int> res;
    for (int i = 0; i < n; i++)
        if (tims[i] % 2)
            res.push_front(i);
        else res.push_back(i);
    for (int i = 0; i < res.size(); i++)
        cout << res[i] + 1 << (i + 1 < res.size() ? ' ' : '\n');
    return 0;
}
