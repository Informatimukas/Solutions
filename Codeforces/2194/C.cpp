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
        vector<int> masks(n);
        for (int i = 0; i < k; i++) {
            string s;
            cin >> s;
            for (int j = 0; j < n; j++)
                masks[j] |= 1 << (s[j] - 'a');
        }
        for (int d = 1; d <= n; d++)
            if (n % d == 0) {
                bool ok = true;
                vector<int> good(d);
                for (int i = 0; i < d; i++) {
                    good[i] = (1 << 26) - 1;
                    for (int j = i; j < n; j += d)
                        good[i] &= masks[j];
                    if (!good[i]) {
                        ok = false;
                        break;
                    }
                }
                if (ok) {
                    string s(n, '?');
                    for (int i = 0; i < d; i++) {
                        int let = 0;
                        while (!(good[i] & 1 << let))
                            ++let;
                        for (int j = i; j < n; j += d)
                            s[j] = let + 'a';
                    }
                    cout << s << "\n";
                    break;
                }
            }
    }
    return 0;
}
