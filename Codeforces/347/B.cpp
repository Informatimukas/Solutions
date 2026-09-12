#include <bits/stdc++.h>
using namespace std;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    int n;
    cin >> n;
    vector<int> p(n);
    for (auto& x : p)
        cin >> x;
    vector<bool> tk(n);
    int res = 0, add = 0;
    for (int i = 0; i < n; i++) {
        int num = i;
        int cnt = 0;
        while (!tk[num]) {
            cnt++;
            tk[num] = true;
            num = p[num];
        }
        if (cnt == 1)
            res++;
        else if (cnt == 2)
            add = 2;
        else add = max(add, 1);
    }
    res += add;
    cout << res << "\n";
    return 0;
}
