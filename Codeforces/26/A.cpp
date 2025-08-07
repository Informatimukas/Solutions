#include <bits/stdc++.h>
using namespace std;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    int n;
    cin >> n;
    vector<int> cnt(n + 1);
    int res = 0;
    for (int i = 2; i <= n; i++)
        if (cnt[i] == 0) {
            for (int j = i; j <= n; j += i)
                cnt[j]++;
        } else if (cnt[i] == 2)
            res++;
    cout << res << "\n";
    return 0;
}
