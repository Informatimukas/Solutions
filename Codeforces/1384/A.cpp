#include <bits/stdc++.h>
using namespace std;

constexpr int Maxl = 26;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    int T;
    cin >> T;
    while (T--) {
        int n;
        cin >> n;
        vector<int> a(n);
        for (auto& x : a)
            cin >> x;
        vector<string> res(n + 1);
        for (int i = 1; i <= 50; i++) {
            int cur = 0;
            for (int j = 0; j < n; j++) {
                res[j] += cur + 'a';
                if (i == a[j] + 1)
                    cur = (cur + 1) % Maxl;
            }
            res[n] += cur + 'a';
        }
        for (auto& x : res)
            cout << x << "\n";
    }
    return 0;
}
