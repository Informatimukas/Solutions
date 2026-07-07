#include <bits/stdc++.h>
using namespace std;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    int n;
    cin >> n;
    vector<int> res(n + 1);
    for (int i = 1; i <= n; i++)
        res[i] = i;
    int cur = n;
    while (cur > 1) {
        swap(res[cur], res[cur - 1]);
        cur--;
    }
    for (int i = 1; i <= n; i++)
        cout << res[i] << (i + 1 <= n ? ' ' : '\n');
    return 0;
}
