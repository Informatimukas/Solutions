#include <bits/stdc++.h>
using namespace std;

constexpr int Maxn = 200005;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    int n;
    cin >> n;
    vector rem(Maxn, 0);
    vector<int> res;
    for (int i = 0; i < n; i++) {
        int a;
        cin >> a;
        rem[a]++;
    }
    int car = 0, cur = n;
    for (int i = 0; i < Maxn; i++) {
        cur -= rem[i];
        if (car == 0 && cur == 0)
            break;
        car += cur;
        res.push_back(car % 10);
        car /= 10;
    }
    while (car > 0) {
        res.push_back(car % 10);
        car /= 10;
    }
    for (int i = res.size() - 1; i >= 0; i--)
        cout << res[i];
    cout << "\n";
    return 0;
}
