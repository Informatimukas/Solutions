#include <bits/stdc++.h>
using namespace std;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    int T;
    cin >> T;
    while (T--) {
        int n, k;
        cin >> n >> k;
        if (k % 2)
            for (int i = 0; i < k; i++)
                cout << n << (i + 1 < k ? ' ' : '\n');
        else {
            vector res(k, 0);
            int fre = 0;
            for (int b = 30; b >= 0; b--)
                if (n & 1 << b) {
                    int skip = fre % k;
                    for (int i = 0; i < k; i++)
                        if (i != skip)
                            res[i] |= 1 << b;
                    if (fre < k)
                        ++fre;
                } else for (int i = 0; i < fre / 2; i++) {
                    res[2 * i] |= 1 << b;
                    res[2 * i + 1] |= 1 << b;
                }
            for (int i = 0; i < res.size(); i++)
                cout << res[i] << (i + 1 < res.size() ? ' ' : '\n');
        }
    }
    return 0;
}
