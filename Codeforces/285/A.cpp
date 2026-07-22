#include <bits/stdc++.h>
using namespace std;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    int n, k;
    cin >> n >> k;
    int lef = 1, rig = n;
    vector<int> res;
    while (lef <= rig)
        if (k == 0)
            res.push_back(lef++);
        else {
            res.push_back(rig--);
            k--;
        }
    for (int i = 0; i < res.size(); i++)
        cout << res[i] << (i + 1 < res.size() ? ' ' : '\n');
    return 0;
}
